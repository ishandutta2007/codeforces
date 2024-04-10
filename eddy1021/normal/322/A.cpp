#include <stdio.h>
int n , m;
void process(){
	printf( "%d\n" , n + m - 1 );
	for( int i = 1 ; i <= m ; i ++ )
		printf( "1 %d\n" , i );
	for( int i = 2 ; i <= n ; i ++ )
		printf( "%d %d\n" , i , m );
}
int main(){
	scanf( "%d%d" , &n , &m );
	process();
}