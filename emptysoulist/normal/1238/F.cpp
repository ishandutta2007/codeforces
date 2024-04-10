#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, cnt, Ans, head[N], out[N], dp[N] ; 
struct E {
	int to, next ; 
} e[N * 2] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt, 
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ;
}
void dfs( int x, int fa ) {
	dp[x] = out[x] + 1 ; 
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		dfs( v, x ) ; 
		Ans = max( Ans, dp[x] + dp[v] - 2 ) ; 
		dp[x] = max( dp[x], dp[v] + out[x] - 1 ) ;
	}
	Ans = max( Ans, dp[x] ) ;
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; int x, y ; cnt = 0, Ans = 0 ;
		rep( i, 1, n ) head[i] = 0, dp[i] = 0, out[i] = 0 ; 
		rep( i, 2, n ) x = gi(), y = gi(), add( x, y ), ++ out[x], ++ out[y] ; 
		dfs( 1, 1 ), printf("%d\n", Ans ) ; 
	}
	return 0 ;
}