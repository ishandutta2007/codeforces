#include <stdio.h>
#include <algorithm>
#define N 300010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int a[ N ] , n , k , ans;
void init(){
	n = getint(); k = getint();
	for( int i = 1 ; i <= n ; i ++ )
		a[ i ] = getint();
	std::sort( a + 1 , a + n + 1 );
	ans = a[ 1 ];
}
void find_ans(){
	bool flag = 1;
	while( flag ){
		flag = 0;
		for( int i = n ; i ; i -- )
			while( a[ i ] % ans > k ) ans -- , flag = 1;
	}
}
int main(){
	init();
	find_ans();
	printf( "%d\n" , ans );
}