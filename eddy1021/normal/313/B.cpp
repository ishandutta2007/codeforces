#include <stdio.h>
#include <string.h>
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
char c[ N ];
int dp[ N ] , q , a , b , l;
void init(){
	scanf( "%s" , c + 1 );
	l = strlen( c + 1 );
	for( int i = 2 ; i <= l ; i ++ )
		dp[ i ] = dp[ i - 1 ] + ( c[ i ] == c[ i - 1 ] );
}
void process(){
	q = getint(); while( q -- ){
		a = getint(); b = getint();
		printf( "%d\n" , dp[ b ] - dp[ a ] );
	}
}
int main(){
	init();
	process();
}