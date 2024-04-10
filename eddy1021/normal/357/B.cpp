#include <stdio.h>
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , m , clr[ N ] , tmp[ 3 ] , div , tclr;
void process(){
	n = getint(); m = getint();
	for( int i = 1 ; i <= n ; i ++ ) clr[ i ] = -1;
	while( m -- ){
		div = 1;
		for( int i = 0 ; i < 3 ; i ++ ){
			tmp[ i ] = getint();
			if( clr[ tmp[ i ] ] != -1 ) tclr = clr[ tmp[ i ] ];
		}
		for( int i = 0 ; i < 3 ; i ++ )
			if( clr[ tmp[ i ] ] != tclr ){
				clr[ tmp[ i ] ] = ( tclr + div ) % 3; div ++;
			}
	}
	for( int i = 1 ; i <= n ; i ++ )
		printf( "%d " , clr[ i ] + 1 );
}
int main(){
	process();
}