#include <stdio.h>
int n , m;
void process(){
	if( m <= ( n + 1 ) * 2 && m >= n + 1 ){
		int k = m / ( n + 1 ); m -= k;
		while( k -- ) putchar( '1' );
		for( int i = n ; i ; i -- ){
			printf( "0" );
			int k = m / i; m -= k;
			while( k -- ) putchar( '1' );
		}
		puts( "" );
	}else if( m <= n * 2 && m >= n ){
		for( int i = n ; i ; i -- ){
			printf( "0" );
			int k = m / i; m -= k;
			while( k -- ) putchar( '1' );
		}
		puts( "" );		
	}else if( m <= ( n - 1 ) * 2 && m >= n - 1 ){
		for( int i = n - 1 ; i ; i -- ){
			printf( "0" );
			int k = m / i; m -= k;
			while( k -- ) putchar( '1' );
		}
		puts( "0" );
	}else puts( "-1" );
}
int main(){
	scanf( "%d%d" , &n , &m );
	process();
}