#include <stdio.h>
#define N 110
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , sum[ N ] , x , y;
void init(){
	n = getint();
	for( int i = 1 ; i <= n ; i ++ ){
		sum[ i ] = getint();
		sum[ i ] += sum[ i - 1 ];
	}
	x = getint(); y = getint();
}
bool in( int t ){
	if( t >= x && t <= y ) return true;
	return false;
}
void process(){
	for( int i = 1 ; i <= n ; i ++ )
		if( in( sum[ i - 1 ] ) && in( sum[ n ] - sum[ i - 1 ] ) ){
			printf( "%d\n" , i ); return;
		}
	puts( "0" );
}
int main(){
	init();
	process();
}