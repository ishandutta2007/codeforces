#include <stdio.h>
#define N 1299710
#define ll long long
int p[ N ] , pt , n , first;
void build(){
	for( ll i = 2 ; i < N ; i ++ )
		if( !p[ i ] ){
			pt ++;
			if( first ) putchar( ' ' );
			first = 1;
			printf( "%d" , i );
			if( pt == n ) return;
			for( ll j = i ; j * i < N ; j ++ )
				p[ i * j ] = 1;
		}
}
int main(){
	scanf( "%d" , &n );
	build();
	putchar( '\n' );
}