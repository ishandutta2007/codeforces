#include <stdio.h>
#define N 110
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[ N ] , n , sum , max , tmp , dp[ N ];
void init(){
	n = getint(); max = -10000;
	for( int i = 1 ; i <= n ; i ++ ){
		bx[ i ] = getint();
		dp[ i ] += dp[ i - 1 ];
		dp[ i ] += bx[ i ];
		sum += bx[ i ];
	}
}
void process(){
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = i ; j <= n ; j ++ ){
			tmp = dp [ j ] - dp[ i - 1 ];
			if( j - i + 1 - tmp - tmp > max )
				max = j - i + 1 - tmp - tmp;
		}
	printf( "%d\n" , sum + max );
}
int main(){
	init();
	process();
}