#include <stdio.h>
#define N 132000
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , q , p , b , rn;
int ST[ N << 2 ] , bx[ N ];
void build( int no , int lvl , int l , int r ){
	if( l == r ){ ST[ no ] = bx[ l ]; return; }
	int m = ( l + r ) >> 1;
	build( no << 1 , lvl + 1 , l , m );
	build( ( no << 1 ) + 1 , lvl + 1 , m + 1 , r );
	if( ( lvl & 1 ) != ( n & 1 ) )
		ST[ no ] = ST[ no << 1 ] | ST[ ( no << 1 ) + 1 ];
	else ST[ no ] = ST[ no << 1 ] ^ ST[ ( no << 1 ) + 1 ];
}
void update( int no , int lvl , int l , int r ){
	if( l == r ){ ST[ no ] = b; return; }
	int m = ( l + r ) >> 1;
	if( p <= m ) update( no << 1 , lvl + 1 , l , m );
	else update( ( no << 1 ) + 1 , lvl + 1 , m + 1 , r );
	if( ( lvl & 1 ) != ( n & 1 ) )
		ST[ no ] = ST[ no << 1 ] | ST[ ( no << 1 ) + 1 ];
	else ST[ no ] = ST[ no << 1 ] ^ ST[ ( no << 1 ) + 1 ];
}
void init(){
	n = getint(); q = getint(); rn = 1 << n;
	for( int i = 1 ; i <= rn ; i ++ )
		bx[ i ] = getint();
	build( 1 , 0 , 1 , rn );
}
void process(){
	while( q -- ){
		p = getint(); b = getint();
		update( 1 , 0 , 1 , rn );
		printf( "%d\n" , ST[ 1 ] );
	}
}
int main(){
	init();
	process();
}