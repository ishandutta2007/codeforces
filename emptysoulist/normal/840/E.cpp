#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e4 + 5 ; 
const int M = 270 ; 
int n, Q, rt, cnt, a[N], fa[N], top[N], dep[N], f[N][M] ; 
vector<int> G[N] ; 
struct Trie {
	int ch[2], w, val ; 
} t[N * 20] ;
void insert( int x, int k ) {
	int u = rt ; 
	drep( i, 8, 15 ) {
		if( !t[u].ch[(x >> i) & 1] ) t[u].ch[(x >> i) & 1] = ++ cnt ;
		u = t[u].ch[(x >> i) & 1], t[u].w += k ;
	}
	if( k == 1 ) t[u].val = max( t[u].val, x & 255 ) ;
	else t[u].val = 0 ;
}
int query( int x ) {
	int u = rt, ans = 0 ; x = x * 256 ; 
	drep( i, 8, 15 ) {
		if( t[t[u].ch[((x >> i) & 1) ^ 1]].w ) u = t[u].ch[((x >> i) & 1) ^ 1], ans += ( 1ll << i ) ;
		else u = t[u].ch[((x >> i) & 1)] ;
	}
	return ( ans ^ t[u].val ) ; 
}
void dfs( int x, int Fa ) {
	fa[x] = Fa, dep[x] = dep[Fa] + 1 ; 
	for( re int i = 0; i < G[x].size(); ++ i ) {
		int v = G[x][i] ; if( v == Fa ) continue ;  
		dfs( v, x ) ;
	}
	if( dep[x] > 256 ) {
		int u = x ; insert( a[x], 1 ) ; 
		for( re int j = 1; j < 256; ++ j ) u = fa[u], insert( a[u] ^ j, 1 ) ;
		for( re int j = 0; j <= 200; ++ j ) f[x][j] = query(j) ;
		insert( a[x], -1 ), top[x] = fa[u], u = x ;
		for( re int j = 1; j < 256; ++ j ) u = fa[u], insert( a[u] ^ j, -1 ) ;
	}
}
void add( int x, int y ) { G[x].push_back(y), G[y].push_back(x) ; }
signed main()
{
	n = gi(), Q = gi(), cnt = rt = 1 ; int x, y ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 2, n ) x = gi(), y = gi(), add( x, y ) ;
	dfs( 1, 1 ) ;
	while( Q-- ) {
		int v = gi(), u = gi(), ans = 0, k = 0, dis = 0 ; 
		while( dep[u] - dep[v] > 256 ) {
			ans = max( ans, f[u][k] ), ++ k, u = top[u] ; 
		}
		dis = k * 256 ; 
		while( u != v ) ans = max( ans, a[u] ^ dis ), ++ dis, u = fa[u] ; 
		ans = max( ans, a[v] ^ dis ) ;
		printf("%d\n", ans ) ;
	}
	return 0 ;
}