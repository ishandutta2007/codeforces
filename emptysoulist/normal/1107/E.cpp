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
const int N = 150 + 5 ; 
int n, dp[N][N][N], a[N], c[N] ; 
signed main()
{
	n = gi() ; rep( i, 1, n ) c[i] = getchar() - '0' ;
	rep( i, 1, n ) a[i] = gi() ; memset( dp, -63, sizeof(dp) ) ;
	for( re int i = 1; i <= n; ++ i ) dp[i][i][1] = 0, dp[i][i][0] = a[1] ;
	for( re int l = 2; l <= n; ++ l ) {
		for( re int i = 1; i <= n - l + 1; ++ i ) {
			int j = i + l - 1 ; 
			for( re int k = 1; k <= l; ++ k ) {
				for( re int t = i; t < j; ++ t )
				if( c[t] == c[j] || k == 1 ) dp[i][j][k] = max( dp[i][j][k], dp[i][t][k - 1] + max( 0ll, dp[t + 1][j - 1][0] ) ) ;
			}
			for( re int k = 1; k <= l; ++ k ) dp[i][j][0] = max( dp[i][j][0], dp[i][j][k] + a[k] ) ;
		}
	}
	printf("%I64d\n", dp[1][n][0] ) ;
	return 0 ;
}