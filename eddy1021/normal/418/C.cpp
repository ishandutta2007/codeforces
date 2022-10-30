#include <math.h>
#include <stdio.h>
#define N 110
bool got[ 2 ];
int n[ 2 ] , t[ 2 ][ N ];
void DFS( int idx , int x , int sum ){
    if( got[ idx ] ) return;
    if( x > n[ idx ] ){
        int x = int( sqrt( sum ) );
        x *= x;
        if( x != sum ) return;
        got[ idx ] = true;
        return;
    }
    for( int i = 1 ; i < 10 ; i ++ ){
        t[ idx ][ x ] = i;
        DFS( idx , x + 1 , sum + i * i );
        if( got[ idx ] ) return;
    }
}
void build(){
    DFS( 0 , 1 , 0 );
    DFS( 1 , 1 , 0 );
}
void print(){
    for( int i = 1 ; i <= n[ 0 ] ; i ++ )
        for( int j = 1 ; j <= n[ 1 ] ; j ++ )
            printf( "%d%c" , t[ 0 ][ i ] * t[ 1 ][ j ] , j == n[ 1 ] ? '\n' : ' ' );
}
int main(){
    scanf( "%d%d" , &n[ 0 ] , &n[ 1 ] );
    build();
    print();
}