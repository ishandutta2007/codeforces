#include <stdio.h>
#include <algorithm>
#define N 10010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[ N ] , n , m , d;
int cnt , ans , precnt , dlt;
void init(){
	n = getint(); m = getint();
	d = getint(); n *= m;
	for( int i = 0 ; i < n ; i ++ )
		bx[ i ] = getint();
	std::sort( bx , bx+n );
}
bool solvable(){
	for( int i = 1 ; i < n ; i ++ )
		if( ( bx[i] - bx[i-1] ) % d )
			return false;
	return true;
}
void process(){
	for( int i = 1 ; i < n ; i ++ )
		cnt += ( bx[i] - bx[0] ) / d;
	precnt = ans = cnt;
	for( int i = 1 ; i < n ; i ++ ){
		dlt = ( bx[i] - bx[i-1] ) / d;
		cnt = precnt + i * dlt;
		cnt -= ( n - i ) * dlt;
		if( cnt < ans ) ans = cnt;
		precnt = cnt;
	}
	printf("%d\n",ans);
}
int main(){
	init();
	if( solvable() ){
		process();
	}else puts("-1");
}