#include <stdio.h>
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , l , r , ql , qr , sum[ N ] , ans;
void init(){
	n = getint(); l = getint(); r = getint();
	ql = getint(); qr = getint();
	for( int i = 1 ; i <= n ; i ++ ){
		sum[ i ] = getint();
		sum[ i ] += sum[ i - 1 ];
	}
}
void process(){
	ans = sum[ n ] * r + ( n - 1 ) * qr;
	for( int i = 1 ; i <= n ; i ++ ){
// 1 ~ i i + 1 ~ n
		int tmp = sum[ i ] * l + ( sum[ n ] - sum[ i ] ) * r;
		int div = ( n - i ) - i , tag = 0;
		if( div < 0 ) div = -div , tag = 1; if( div ) div --;
		if( tag ) tmp += div * ql; else tmp += div * qr;
		if( tmp < ans ) ans = tmp;
	}
	printf( "%d\n" , ans );
}
int main(){
	init();
	process();
}