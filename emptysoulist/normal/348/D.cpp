#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3000 + 5 ; 
const int P = 1e9 + 7 ; 
int n, m, dp[N][N], a[N][N] ; 
char s[N][N] ; 
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) scanf("%s", s[i] + 1 ) ;
	rep( i, 1, n ) rep( j, 1, m ) a[i][j] = ( s[i][j] == '.' ) ? 1 : 0 ; 
	dp[n - 1][m] = 1 ; 
	drep( i, 1, n - 1 ) drep( j, 1, m ) dp[i][j] = ( a[i][j] ) * ( dp[i][j] + dp[i + 1][j] + dp[i][j + 1] ) % P ; 
	int ans1 = dp[1][2], ans2 = dp[2][1] ; memset( dp, 0, sizeof(dp) ) ;
	dp[n][m - 1] = 1 ; 
	drep( i, 1, n ) drep( j, 1, m - 1 ) dp[i][j] = ( a[i][j] ) * ( dp[i][j] + dp[i + 1][j] + dp[i][j + 1] ) % P ; 
	ans1 = ans1 * dp[2][1] % P, ans2 = ans2 * dp[1][2] % P ; 
	printf("%lld\n", ( ans1 - ans2 + P ) % P ) ;
	return 0 ;
}