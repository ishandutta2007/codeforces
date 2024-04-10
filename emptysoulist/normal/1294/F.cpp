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
int n, cnt, head[N], dep[N] ;
struct E {
	int to, next ;
} e[N << 1] ;
int Mxdep, a, b, c, Fa[N], Son[N], vis[N], Ans ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ;
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ;
}
void dfs2( int x, int fa ) {
	dep[x] = dep[fa] + 1 ; 
	if( Mxdep < dep[x] ) Mxdep = dep[x], a = x ;
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ;
		dfs2( v, x ) ;
	}
}
void dfs3( int x, int fa ) {
	dep[x] = dep[fa] + 1, Fa[x] = fa ;
	if( Mxdep < dep[x] ) Mxdep = dep[x], b = x ;
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ;
		dfs3( v, x ) ;
	}
}
void dfs4( int x, int fa, int H ) {
	if( H > Mxdep ) Mxdep = H, c = x ;
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ;
		dfs4( v, x, H + 1 ) ; 
	}
}
void dfs( int x, int fa ) {
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ;
		if( v != Son[x] ) dfs4( v, x, 1 ) ; 
	}
	if( Son[x] ) dfs( Son[x], x ) ;
}
signed main()
{
	n = gi() ; int x, y ;
	rep( i, 2, n ) x = gi(), y = gi(), add( x, y ) ;
	dep[1] = -1, dfs2( 1, 1 ),
	dep[a] = -1, Mxdep = 0, dfs3( a, a ) ;
	int u = b ; vis[a] = 1 ;
	while( u != a ) vis[u] = 1, Son[Fa[u]] = u, u = Fa[u] ;
	Mxdep = 0, c = Son[a], dfs( a, a ) ; 
	printf("%I64d\n", dep[b] + Mxdep ) ;
	cout << a << " " << b << " " << c << endl ;
	return 0 ;
}