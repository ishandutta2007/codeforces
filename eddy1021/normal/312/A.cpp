#include <stdio.h>
#include <string.h>
#define L 110
int n , l , r , f;
char c[ L ];
int main(){
	scanf( "%d" , &n ); getchar();
	while( n -- ){
		gets( c ); r = f = 0;
		l = strlen( c );
		if( l >= 5 ){
			if( c[ 0 ] == 'm' && 
				c[ 1 ] == 'i' &&
				c[ 2 ] == 'a' && 
				c[ 3 ] == 'o' &&
				c[ 4 ] == '.' ) r = 1;
			if( c[ l - 5 ] == 'l' &&
				c[ l - 4 ] == 'a' &&
				c[ l - 3 ] == 'l' &&
				c[ l - 2 ] == 'a' &&
				c[ l - 1 ] == '.' ) f = 1;
		}
		if( f ^ r ){
			if( f ) puts( "Freda's" );
			else puts( "Rainbow's" );
		}else puts( "OMG>.< I don't know!" );
	}
}