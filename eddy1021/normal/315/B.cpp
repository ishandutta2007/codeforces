#include <stdio.h>
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[ N ] , n , m , t , a , b , q , base;
void init(){
	n = getint(); m = getint();
	for( int i = 1 ; i <= n ; i++ )
		bx[ i ] = getint();
}
void process(){
	while( m -- ){
		t = getint();
		if( t == 1 ){
			a = getint(); b = getint();
			bx[ a ] = b - base;
		}else if( t == 2 ){
			base += getint();
		}else{
			q = getint();
			printf( "%d\n" , bx[ q ] + base );
		}
	}
}
int main(){
	init();
	process();
}