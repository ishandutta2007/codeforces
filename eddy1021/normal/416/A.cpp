#include <stdio.h>
#include <string.h>
#define inf 2000000000
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp=-1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int min( int x , int y ){ return x<y?x:y; }
int max( int x , int y ){ return x>y?x:y; }
int n , x , l , r;
bool flag = true;
char c1[ 3 ] , c2[ 3 ];
void cal(){
    if( strlen( c1 ) == 2 ){
        if( c1[ 0 ] == '<' ){
            if( c2[ 0 ] == 'Y' ){
                if( l > x ) flag = false;
                r = min( r , x );
            }else{
                if( r <= x ) flag = false;
                l = max( l , x + 1 );
            }
        }else{
            if( c2[ 0 ] == 'Y' ){
                if( r < x ) flag = false;
                l = max( x , l );
            }else{
                if( l >= x ) flag = false;
                r = min( x - 1 , r );
            }
        }
    }else{
        if( c1[ 0 ] == '<' ){
            if( c2[ 0 ] == 'Y' ){
                if( l >= x ) flag = false;
                r = min( r , x - 1 );
            }else{
                if( r < x ) flag = false;
                l = max( l , x );
            }
        }else{
            if( c2[ 0 ] == 'Y' ){
                if( r <= x ) flag = false;
                l = max( l , x + 1 );
            }else{
                if( l > x ) flag = false;
                r = min( x , r );
            }
        }
    }
}
void process(){
    l = -inf; r = inf;
    n = getint(); while( n -- ){
        scanf( "%s" , c1 );
        x = getint();
        scanf( "%s" , c2 );
        cal();
//        printf( "%d %d\n" , l , r );
    }
}
void print(){
    if( l > r || !flag ) puts( "Impossible" );
    else if( l != -inf ) printf( "%d\n" , l );
    else printf( "%d\n" , r );
}
int main(){
    process();
    print();
}