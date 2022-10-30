#include <stdio.h>
#include <algorithm>
#define N 110
int bx[ N ] , n;
int main(){
    scanf( "%d" , &n );
    for( int i = 0 ; i < n ; i ++ )
        scanf( "%d" , &bx[ i ] );
    std::sort( bx , bx + n );
    for( int i = 0 ; i < n ; i ++ )
        printf( "%d%c" , bx[ i ] , i == n - 1 ? '\n' : ' ' );
}