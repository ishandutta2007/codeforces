#include <stdio.h>
int n , d , ti , s;
int main(){
    scanf( "%d%d" , &n , &d );
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%d" , &ti );
        s += ti;
    }
    if( s + 10 * ( n - 1 ) > d ) puts( "-1" );
    else printf( "%d\n" , ( d - s ) / 5 );
}