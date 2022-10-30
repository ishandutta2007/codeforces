#include <stdio.h>
#include <string.h>
#define L 100010
int n , l , l2;
char c1[ L ] , c2[ L ];
void init(){
	scanf( "%d" , &n );
	c1[ 0 ] = '<'; c1[ 1 ] = '3'; l = 2;
	for( int i = 0 ; i < n ; i ++ ){
		scanf( "%s" , c1 + l );
		l = strlen( c1 );
		c1[ l ] = '<'; c1[ l + 1 ] = '3'; l += 2;
	}
	scanf( "%s" , c2 );
	l2 = strlen( c2 );
}
void process(){
	int idx = 0;
	for( int i = 0 ; i < l2 ; i ++ ){
		if( c2[ i ] == c1[ idx ] ) idx ++;
		if( idx == l ){ puts( "yes" ); return; }
	}
	puts( "no" );
}
int main(){
	init(); process();
}