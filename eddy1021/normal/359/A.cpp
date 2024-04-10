#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , m , x , cnt;
int main(){
	n = getint(); m = getint();
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ ){
			x = getint();
			if( x && ( i == 1 || j == 1 || i == n || j == m ) )
				cnt = 2;
		}
	printf( "%d\n" , 4 - cnt );
}