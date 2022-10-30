#include <stdio.h>
#include <algorithm>
#define N 100
int n , m , bx[ N ] , min;
int main(){
	scanf( "%d%d" , &n , &m );
	for( int i = 0 ; i < m ; i ++ )
		scanf( "%d" , &bx[ i ] );
	std::sort( bx , bx + m );
	min = bx[ n - 1 ] - bx[ 0 ];
	for( int i = n ; i < m ; i ++ )
		if( bx[ i ] - bx[ i - n + 1 ] < min )
			min = bx[ i ] - bx[ i - n + 1];
	printf( "%d\n" , min );
}