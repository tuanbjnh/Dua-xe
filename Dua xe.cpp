#include "sdl.h"
SDL_Texture * igmage;
SDL_Event k;
int car_x=1, car_y=1;
bool up_= false,
     down_= false,
     left_ = false,
     right_= false;

void draw_car()
{
    igmage=loadTexture("car.bmp", renderer);
    renderTexture( igmage, renderer, car_x, car_y, car_x+99, car_y+99);
    SDL_DestroyTexture(igmage);
}
void draw_racetrack ()
{
    igmage=loadTexture("racetrack.bmp", renderer);
    renderTexture( igmage, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_DestroyTexture(igmage);
}
void move_car()
{
    SDL_PollEvent( &k);
    if( k.type==SDL_KEYDOWN){
        if( k.key.keysym.sym==SDLK_UP) up_=true, down_=false; else
        if( k.key.keysym.sym==SDLK_DOWN) up_=false, down_=true; else
        if( k.key.keysym.sym==SDLK_LEFT) left_=true, right_=false; else
        if( k.key.keysym.sym==SDLK_RIGHT) left_=false, right_=true;
    }
    if( k.type==SDL_KEYUP){
        if( k.key.keysym.sym==SDLK_UP) up_=false; else
        if( k.key.keysym.sym==SDLK_DOWN) down_=false; else
        if( k.key.keysym.sym==SDLK_LEFT) left_=false; else
        if( k.key.keysym.sym==SDLK_RIGHT) right_=false;
    }
    if( up_ && car_y-5>=0) car_y-=5; else
    if( down_ && car_y+104<=SCREEN_HEIGHT) car_y+=5;
    if( left_ && car_x-5>=0) car_x-=5; else
    if( right_ && car_x+104<=SCREEN_WIDTH) car_x+=5;
    draw_car();
}
int main( int argc, char* agrv[])
{
    initSDL( window, renderer);
    while( true){
        draw_racetrack();
        move_car();
        SDL_RenderPresent(renderer);
    }
}
