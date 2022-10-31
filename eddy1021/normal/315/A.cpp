#include <stdio.h>
#define N 1001
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , a[ N ] , b[ N ] , cnt[ N ] , ans;
void init(){
	n = getint();
	for( int i = 0 ; i < n ; i++ ){
		a[ i ] = getint();
		b[ i ] = getint();
		cnt[ b[ i ] ] ++;
	}
}
void process(){
	for( int i = 0 ; i < n ; i++ )
		if( !cnt[ a[ i ] ] || ( cnt[ a[ i ] ] == 1 && a[ i ] == b[ i ] ) )
			ans ++;
	printf( "%d\n" , ans );
}
int main(){
	init();
	process();
}