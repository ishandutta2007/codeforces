#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 310
int n , m;
char c[ N ][ N ] , c1 , c2;
void init(){
	scanf( "%d" , &n );
	for( int i = 1 ; i <= n ; i ++ )
		scanf( "%s" , c[ i ] + 1 );
}
void process(){
	bool chk = true;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ; j ++ )
			if( i == j || i == n + 1 - j ){
				if( !c1 ) c1 = c[ i ][ j ];
				else if( c[ i ][ j ] != c1 )
					chk = false;
			}else{
				if( !c2 ) c2 = c[ i ][ j ];
				else if( c[ i ][ j ] != c2 )
					chk = false;
			}
	if( c1 == c2 || !chk ) puts( "NO" );
	else puts( "YES" );
}
int main(){
	init();
	process();
}