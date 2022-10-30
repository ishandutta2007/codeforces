#include <stdio.h>
#define N 1010
#define mod 1000000007
int n , a , b[ N ] , t;
int main(){
    scanf( "%d" , &n );
    for( int i = 1 ; i <= n ; i ++ ){
        scanf( "%d" , &t ); b[ i ] = 2;
        for( int j = t ; j < i ; j ++ )
            b[ i ] = ( b[ i ] + b[ j ] ) % mod;
        a = ( a + b[ i ] ) % mod;
    }
    printf( "%d\n" , a );
}