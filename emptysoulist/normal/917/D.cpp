#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 1000 + 5 ; 
int n, sz[N], fac[N], bef[N][N][2], dp[N][N][2], C[N][N], f[N], g[N] ; 
vector<int> G[N] ; 
void add( int x, int y ) { G[x].pb(y), G[y].pb(x) ; }
void inc( int &x, int y ) {
	( ( x += y ) >= P ) && ( x -= P ) ; 
}
void dfs( int x, int fa ) {
	dp[x][1][0] = 1, dp[x][1][1] = 1, sz[x] = 1 ; 
	for( int v : G[x] ) {
		if( v == fa ) continue ; dfs( v, x ) ;
		drep( j, 1, sz[x] ) drep( k, 1, sz[v] ) {
			inc( bef[x][j + k][0], dp[x][j][0] * dp[v][k][1] % P ) ;
			inc( bef[x][j + k][1], dp[x][j][1] * dp[v][k][1] % P ) ; 
			inc( bef[x][j + k - 1][0], dp[x][j][0] * dp[v][k][0] % P ) ;
			inc( bef[x][j + k - 1][1], ( dp[x][j][1] * dp[v][k][0] + dp[x][j][0] * dp[v][k][1] ) % P ) ; 
		}
		sz[x] += sz[v] ; 
		rep( j, 1, sz[x] ) dp[x][j][0] = bef[x][j][0], dp[x][j][1] = bef[x][j][1], bef[x][j][0] = 0, bef[x][j][1] = 0 ; 
	}
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add( x, y ) ; 
	dfs( 1, 1 ), C[0][0] = 1, fac[0] = 1 ; 
	rep( i, 1, n ) rep( j, 0, i ) C[i][j] = ( ( j == 0 ) ? 1 : ( C[i - 1][j] + C[i - 1][j - 1] ) % P ) ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * n % P ;
	for( re int i = 0; i < n - 1; ++ i ) g[i] = dp[1][n - i][1] * fac[n - i - 2] ; 
	g[n - 1] = 1 ; 
	drep( i, 0, n ) {
		f[i] = g[i] ; 
		for( re int j = i + 1; j <= n; ++ j ) {
			f[i] = ( f[i] - f[j] * C[j][i] % P + P ) % P ;
		}
	}
	for( re int i = 0; i < n; ++ i ) printf("%lld ", f[i] ) ;
	return 0 ;
}