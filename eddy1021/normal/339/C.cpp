#include <stdio.h>
#define L 15
#define N 1010
bool flag;
char c[ L ];
int m , bx[ N ];
void DFS( int now , int l , int r ){
	if( now == m ){
		flag = true; puts( "YES" );
		for( int i = 0 ; i < now ; i ++ )
			printf( "%d%c" , bx[ i ] , i == now - 1 ? '\n' : ' ' );
		return;
	}
	for( int i = 10 ; i >= 1 ; i -- )
		if( c[ i ] == '1' && i != bx[ now - 1 ] ){
			if( now % 2 ){
				if( l + i > r ){
					bx[ now ] = i;
					DFS( now + 1 , l + i , r );
					if( flag ) return;
				}else break;
			}else{
				if( r + i > l ){
					bx[ now ] = i;
					DFS( now + 1 , l , r + i );
					if( flag ) return;
				}else break;
			}
		}
}
int main(){
	scanf( "%s" , c + 1 ); scanf( "%d" , &m );
	DFS( 0 , 0 , 0 ); if( !flag ) puts( "NO" );
}