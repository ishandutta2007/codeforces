#include <stdio.h>
int n , k;
int main(){
	scanf( "%d%d" , &n , &k );
	if( n * ( n - 1 ) / 2 <= k )
		puts( "no solution" );
	else{
		for( int i = 0 ; i < n ; i++ )
			printf( "1 %d\n" , i );
	}
}