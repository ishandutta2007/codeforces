#include <stdio.h>
#define N 1010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , k , a[ N ];
void init(){
	n = getint(); k = getint();
	for( int i = 1 ; i <= n ; i ++ )
		a[ i ] = getint();
}
void process(){
	int bst = 1 , min = -1;
	for( int i = 1 ; i < N ; i ++ ){
		int tmp = 0 , nd = i;
		for( int j = 1 ; j <= n ; j ++ ){
			if( a[ j ] != nd ) tmp ++;
			nd += k;
		}
		if( min == -1 || tmp < min )
			min = tmp , bst = i;
	}
	printf( "%d\n" , min );
	for( int i = 1 , y = bst ; i <= n ; i ++ , y += k )
		if( a[ i ] > y )
			printf( "- %d %d\n" , i , a[ i ] - y ); 
		else if( a[ i ] < y )
			printf( "+ %d %d\n" , i , y - a[ i ] );
}
int main(){
	init();
	process();
}