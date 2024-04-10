#include <stdio.h>
#define N 110
#define inf 10000
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int min( int x , int y ){ return x<y?x:y; }
int cnt[ N + N ] , ti , wi , n;
void init(){
	n = getint();
	for( int i = 1 ; i <= n +n ; i ++ )
		cnt[ i ] = inf;
}
void process(){
	for( int i = 0 ; i < n ; i ++ ){
		ti = getint(); wi = getint();
		for( int j = n+n ; j >= 0 ; j -- ){
			if( j >= ti ) cnt[ j ] = min( cnt[ j-ti ] , cnt[ j ] + wi );
			else cnt[ j ] += wi;
		}
	}
}
void find_ans(){
	for( int i = 0 ; i <= n+n ; i ++ )
		if( cnt[ i ] <= i ){
			printf("%d\n",i);
			return;
		}
}
int main(){
	init();
	process();
	find_ans();
}