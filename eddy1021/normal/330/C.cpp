#include <stdio.h>
#include <string.h>
#define N 110
int n , ans[ N ];
char c[ N ][ N ];
void init(){
	scanf( "%d" , &n );
	for( int i = 1 ; i <= n ; i++ )
		scanf( "%s" , c[ i ] + 1 );
}
void process(){
	int can = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		int tmpans = -1;
		for( int j = 1 ; j <= n ; j ++ )
			if( c[ i ][ j ] == '.' ){
				tmpans = j; break;
			}
		if( tmpans == -1 ){
			can = 0; break;
		}
		ans[ i ] = tmpans;
	}
	if( can ){
		for( int i = 1 ; i <= n ; i++ )
			printf( "%d %d\n" , i , ans[ i ] );
		return;
	}
	can = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		int tmpans = -1;
		for( int j = 1 ; j <= n ; j ++ )
			if( c[ j ][ i ] == '.' ){
				tmpans = j; break;
			}
		if( tmpans == -1 ){
			can = 0; break;
		}
		ans[ i ] = tmpans;
	}
	if( can ){
		for( int i = 1 ; i <= n ; i ++ )
			printf( "%d %d\n" , ans[ i ] , i );
	}else puts( "-1" );
}
int main(){
	init();
	process();
}