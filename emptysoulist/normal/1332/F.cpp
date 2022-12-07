#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 998244353 ; 
const int N = 3e5 + 5 ; 
int n, cnt, head[N], dp[N][3], g[N] ; 
struct E {
	int to, next ; 
} e[N << 1] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void dfs( int x, int fa ) {
	dp[x][2] = 1 ; 
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		dfs( v, x ) ; 
		dp[x][0] = ( ( dp[x][0] + dp[x][2] ) * ( ( dp[v][0] + dp[v][1] + dp[v][2] * 2ll ) % P ) % P + dp[x][0] * ( ( 1ll * dp[v][0] + dp[v][1] + dp[v][2] ) % P ) % P ) % P;
		dp[x][1] = ( ( ( ( dp[x][1] + dp[x][2] ) % P ) * ( dp[v][0] + dp[v][2] ) ) % P + dp[x][1] * ( dp[v][0] + dp[v][1] + dp[v][2] ) % P ) % P;
		dp[x][2] = dp[x][2] * ( dp[v][0] + dp[v][1] + dp[v][2] ) % P ;
	} 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add( x, y ) ;
	dfs( 1, 1 ) ; 
	printf("%I64d\n", ( dp[1][1] + dp[1][2] + dp[1][0] - 1 + P ) % P ) ;
	return 0 ;
}