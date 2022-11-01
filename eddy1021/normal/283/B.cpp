#include <stdio.h>
#define N 200010
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll a[ N ] , dp[ N ][ 3 ] , n , times , got[ N ][ 3 ];
ll DP( ll now , ll dlt ){
	if( now <= 0 || now > n ) return 0;
	if( now == 1 && dlt == 1 || got[ now ][ dlt+1 ] == times ) return -1;
	if( got[ now ][ dlt+1 ] ) return dp[ now ][ dlt+1 ];
	got[ now ][ dlt+1 ] = times;
	ll tsum = DP( now+a[now]*dlt , -dlt );
	return dp[ now ][ dlt+1 ] = tsum < 0 ? -1 : tsum+a[now];
}
int main(){
	n = getint();
	for( int i=2;i<=n;i++ ) a[i] = getint();
	for( int i=1;i<n;i++ ){
		++times; DP( i+1 , 1 ); ++times; DP( i+1 , -1 );
	}
	for( int i=1;i<n;i++ ) printf("%I64d\n",dp[i+1][0]<0?-1:dp[i+1][0]+i);
}