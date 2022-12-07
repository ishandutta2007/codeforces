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
const int N = 1000 + 5 ; 
const int P = 1e9 + 7 ; 
int n, m, dp[N][N][3][3], g[N], f[N], C[N][N], fac[N] ; 

signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 0, n ) rep( j, 0, i ) C[i][j] = ( j == 0 ) ? 1 : ( C[i - 1][j - 1] + C[i - 1][j] ) % P ; 
	dp[0][0][2][2] = 1 ; 
	rep( i, 1, n ) rep( j, 0, i ) rep( k1, 0, 2 ) rep( k2, 0, 2 ) {
		dp[i][j][k2][2] = ( dp[i][j][k2][2] + dp[i - 1][j][k1][k2] ) % P ; 
		if( k1 != 1 && ( i != 1 ) ) dp[i][j + 1][k2][0] = ( dp[i][j + 1][k2][0] + dp[i - 1][j][k1][k2] ) % P ;
		if( i != n ) dp[i][j + 1][k2][1] = ( dp[i][j + 1][k2][1] + dp[i - 1][j][k1][k2] ) % P ;  
	} fac[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ;
	rep( i, 0, n ) rep( k1, 0, 2 ) rep( k2, 0, 2 ) g[i] = ( g[i] + dp[n][i][k1][k2] ) % P ; 
	drep( i, 0, n ) {
		f[i] = g[i] * fac[n - i] % P ; 
		rep( j, i + 1, n ) f[i] = ( f[i] - C[j][i] * f[j] % P + P ) % P ;
	}
	printf("%lld\n", f[m] ) ;
	return 0 ;
}