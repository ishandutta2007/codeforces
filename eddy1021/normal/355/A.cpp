#include <stdio.h>
int k , d;
int main(){
	scanf( "%d%d" , &k , &d );
	if( !d ){
		if( k > 1 ) puts( "No solution" );
		else puts( "0" );
	}else{
		putchar( d + '0' );
		while( -- k ) putchar( '0' );
		puts( "" );
	}
}