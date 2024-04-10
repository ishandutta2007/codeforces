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
const int N = 2e5 + 5 ; 
int n, m, cnt, head[N], sz[N], Ans1, Ans2, vis[N] ; 
struct E {
	int to, next, w ; 
} e[N << 1] ;
void add( int x, int y, int z ) {
	e[++ cnt] = (E){ y, head[x], z }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], z }, head[y] = cnt ; 
}
void dfs( int x, int fa ) {
	sz[x] = 1 ; 
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		dfs( v, x ), sz[x] += sz[v] ; if( sz[v] % 2 == 0 ) Ans2 -= e[i].w ; 
		Ans1 += min( sz[v], m - sz[v] ) * e[i].w ;
	}
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), m = 2 * n ; int x, y, z ; cnt = 0 ;
		rep( i, 1, m - 1 ) x = gi(), y = gi(), z = gi(), Ans2 += z, add( x, y, z ) ; 
		dfs( 1, 1 ), printf("%I64d %I64d\n", Ans2, Ans1 ) ;
		rep( i, 1, m ) sz[i] = head[i] = 0 ; Ans1 = 0, Ans2 = 0 ;
	}
	return 0 ;
}