#include <stdio.h>
#define N 1010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int min( int x , int y ){ return x<y?x:y; }
int max( int x , int y ){ return x>y?x:y; }
int n , bx[ N ] , a , b , c , d;
int main(){
	n = getint();
	for( int i = 0 ; i < n ; i ++ ) bx[ i ] = getint();
	for( int i = 0 ; i < n - 1 ; i ++ ){
		a = min( bx[ i ] , bx[ i + 1 ] );
		b = max( bx[ i ] , bx[ i + 1 ] );
		for( int j = 0 ; j < n - 1 ; j ++ ){
			c = min( bx[ j ] , bx[ j + 1 ] );
			d = max( bx[ j ] , bx[ j + 1 ] );
			if( (c < a && d > a && d < b ) || ( c > a && c < b && d > b ) )
				return puts( "yes" ) , 0;
		}
	}
	puts( "no" );
}