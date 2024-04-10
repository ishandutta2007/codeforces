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
const int N = 100 + 5 ; 
int n, a[N], vis[N], tx[N], dp[N][N][N][2] ; 
signed main() {
	n = gi() ; rep( i, 1, n ) a[i] = gi(), vis[a[i]] = 1 ; 
	rep( i, 1, n ) if( !vis[i] ) ++ tx[i % 2] ;
	memset( dp, 63, sizeof(dp) ), dp[0][0][0][0] = dp[0][0][0][1] = 0 ; 
	for( re int i = 1; i <= n; ++ i ) {
		if( a[i] ) {
			if( a[i] % 2 ) rep( j, 1, n ) rep( k, 0, n ) dp[i][j][k][1] = min( dp[i - 1][j - 1][k][1], dp[i - 1][j - 1][k][0] + 1 ) ;
			else rep( j, 0, n ) rep( k, 1, n ) dp[i][j][k][0] = min( dp[i - 1][j][k - 1][1] + 1, dp[i - 1][j][k - 1][0] ) ;
		}
		else {
			rep( j, 1, n ) rep( k, 0, n ) dp[i][j][k][1] = min( dp[i - 1][j - 1][k][1], dp[i - 1][j - 1][k][0] + 1 ) ;
			rep( j, 0, n ) rep( k, 1, n ) dp[i][j][k][0] = min( dp[i - 1][j][k - 1][1] + 1, dp[i - 1][j][k - 1][0] ) ;
		}
	}
	int tp = 0, m = n / 2 ; 
	if( n % 2 == 1 ) ++ tp ; 
	printf("%I64d\n", min( dp[n][m + tp][m][0], dp[n][m + tp][m][1] ) ) ;
	return 0 ; 
}