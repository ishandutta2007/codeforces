#include <stdio.h>
#define N 1010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int cst[ 5 ] , n , m , a[ N ] , b[ N ] , ans;
void init(){
	for( int i = 0 ; i < 4 ; i ++ ) cst[ i ] = getint();
	n = getint(); m = getint();
	for( int i = 0 ; i < n ; i ++ ) a[ i ] = getint();
	for( int i = 0 ; i < m ; i ++ ) b[ i ] = getint();
	ans = cst[ 3 ];
}
void process(){
	int cst_a = cst[ 2 ] , cst_b = cst[ 2 ] , tcst_a = 0 , tcst_b = 0;
	for( int i = 0 ; i < n ; i ++ )
		tcst_a += cst[ 1 ] < cst[ 0 ] * a[ i ] ? cst[ 1 ] : cst[ 0 ] * a[ i ];
	for( int i = 0 ; i < m ; i ++ )
		tcst_b += cst[ 1 ] < cst[ 0 ] * b[ i ] ? cst[ 1 ] : cst[ 0 ] * b[ i ];
	if( tcst_a < cst_a ) cst_a = tcst_a;
	if( tcst_b < cst_b ) cst_b = tcst_b;
	if( cst_a + cst_b < ans ) ans = cst_a + cst_b;
	printf( "%d\n" , ans );
}
int main(){
	init();
	process();
}