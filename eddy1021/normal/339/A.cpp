#include <stdio.h>
#include <string.h>
#define L 110
char c[ L ];
int cnt[ 5 ] , first;
int main(){
	scanf( "%s" , c );
	for( int i = 0 ; c[ i ] ; i ++ )
		if( c[ i ] >= '1' && c[ i ] <= '3' ) cnt[ c[ i ] - '0' ] ++;
	for( int i = 1 ; i <= 3 ; i ++ )
		while( cnt[ i ] ){
			if( first ) putchar( '+' ); first = 1;
			printf( "%d" , i ); cnt[ i ] --;
		}
	puts( "" );
}