#include <stdio.h>
#include <algorithm>
#define N 101
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[ N ] , n , sum , at , ans[ N ];
void init(){
	n = getint();
	for( int i = 0 ; i < n ; i ++ )
		bx[ i ] = getint();
	std::sort( bx , bx + n  );
}
bool test( int a , int b ){
	while( a && b ){
		if( ( a % 10 ) && ( b % 10 ) ) return false;
		a /= 10; b /= 10;
	}
	return true;
}
void process(){
	for( int i = 0 ; i < n ; i ++ )
		if( test( sum , bx[ i ] ) ){
			sum += bx[ i ];
			ans[ at ++ ] = bx[ i ];
		}
	printf( "%d\n" , at );
	for( int i = 0 ; i < at ; i ++ )
		printf( "%d%c" , ans[ i ] , i == at - 1 ? '\n' : ' ' );
}
int main(){
	init();
	process();
}