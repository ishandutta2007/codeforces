#include <stdio.h>
#define N 5
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int max( int x , int y ){ return x>y?x:y; }
int d[ N ] , a[ N ];
void init(){
    for( int i = 0 ; i < 4 ; i ++ ){
        d[ i ] = getint();
        a[ i ] = getint();
    }
}
bool det1(){
    if( a[ 0 ] > max( d[ 2 ] , d[ 3 ] ) && d[ 1 ] > max( a[ 2 ] , a[ 3 ] ) )
        return true;
    if( a[ 1 ] > max( d[ 2 ] , d[ 3 ] ) && d[ 0 ] > max( a[ 2 ] , a[ 3 ] ) )
        return true;
    return false;
}
bool det2(){
    if( ( a[ 2 ] > d[ 0 ] && d[ 3 ] > a[ 1 ] ) ||
        ( a[ 3 ] > d[ 0 ] && d[ 2 ] > a[ 1 ] ) );
    else return false;
    if( ( a[ 2 ] > d[ 1 ] && d[ 3 ] > a[ 0 ] ) ||
        ( a[ 3 ] > d[ 1 ] && d[ 2 ] > a[ 0 ] ) );
    else return false;
    return true;
}
void process(){
    bool win1 , win2;
    win1 = det1();
    win2 = det2();
    if( win1 && !win2 ) puts( "Team 1" );
    else if( !win1 && win2 ) puts( "Team 2" );
    else puts( "Draw" );
}
int main(){
    init();
    process();
}