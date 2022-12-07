#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 65 ; 
int ans, dp[N][2][2], A[N], B[N], Len ;
int dfs( int n, int limit1, int limit2 ) {
	if( n == -1 ) return 1 ;
	if( dp[n][limit1][limit2] ) return dp[n][limit1][limit2] ; 
	int res1 = limit1 ? A[n] : 1 ;
	int res2 = limit2 ? B[n] : 1 ;
	int ret = 0 ; 
	for( re int i = 0; i <= res1; ++ i ) {
		for( re int j = 0; j <= res2; ++ j ) {
			if( ( i + j ) != ( i ^ j ) ) continue ;
			ret += dfs( n - 1, limit1 & ( i == res1 ), limit2 & ( j == res2 ) ) ;
		}
	} 
	dp[n][limit1][limit2] = ret ;
	return ret ;
}
int Query( int l, int r ) {
	if( l < 0 || r < 0 ) return 0 ;
	int L = 0, R = 0 ; memset( dp, 0, sizeof(dp) ) ;
	memset( A, 0, sizeof(A) ), memset( B, 0, sizeof(B) ) ; 
	while( l ) A[L] = ( l & 1 ), l >>= 1, ++ L ;
	while( r ) B[R] = ( r & 1 ), r >>= 1, ++ R ;
	Len = max( L, R ) ;
	return dfs( Len, 1, 1 ) ;
}
signed main()
{
	int T = gi(), l, r ; 
	while( T-- ) {
		l = gi(), r = gi() ; 
		printf("%I64d\n", Query( r, r ) - 2ll * Query( l - 1, r ) + Query( l - 1, l - 1 ) ) ;
	}
	return 0 ;
}
//[0,r]
//[0,l]
//[0,l]\to[0,r]