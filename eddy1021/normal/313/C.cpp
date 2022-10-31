#include <stdio.h>
#include <algorithm>
#define N 2000010
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll bx[ N ] , n , ans , idx , bonus , tn;
bool cmp( int i , int j ){ return i > j; }
int main(){
	tn = n = getint(); idx = 1;
	for( int i = 1 ; i <= n ; i ++ )
		bx[ i ] = getint();
	std::sort( bx + 1 , bx + n + 1 , cmp );
	while( tn ) bonus ++ , tn >>= 2;
	for( int i = 1 ; i <= n ; i ++ ){
		ans += bonus * bx[ i ];
		if( i == idx ){
			bonus --; idx <<= 2;
		}
	}
	printf( "%I64d\n" , ans );
}