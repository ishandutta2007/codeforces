#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , sum , now;
int main(){
	n = getint(); now = 1;
	sum = 1 + n * n;
	for( int i = 1 ; i <= n ; i ++ ){
		int first = 0;
		for( int j = ( n >> 1 ) ; j ; j -- ){
			if( first ) putchar( ' ' ); first = 1;
			printf( "%d %d" , now , sum - now );
			now ++;
		}
		puts( "" );
	}
}