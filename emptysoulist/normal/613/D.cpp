#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 1e5 + 5 ; 
int n, m, head[N], Ans, K[N], idnex, s[N], top, vis[N] ;
int Top[N], sz[N], Fa[N], dfn[N], Son[N], dep[N], cnt ; 
struct E {
	int to, next ; 
} e[N * 2] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ; 
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ;
}
void dfs( int x, int fa ) {
	sz[x] = 1, dep[x] = dep[fa] + 1, Fa[x] = fa ;  
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		dfs( v, x ), sz[x] += sz[v] ;
		if( sz[Son[x]] < sz[v] ) Son[x] = v ;
	}
} 
void dfs2( int x, int high ) {
	Top[x] = high, dfn[x] = ++ idnex ;
	if( Son[x] ) dfs2( Son[x], high ) ;
	Next( i, x ) {
		int v = e[i].to ; if( v == Fa[x] || v == Son[x] ) continue ; 
		dfs2( v, v ) ;
	}
}
int LCA( int x, int y ) {
	while( Top[x] != Top[y] ) {
		if( dep[Top[x]] < dep[Top[y]] ) swap( x, y ) ;
		x = Fa[Top[x]] ; 
	}
	return ( dep[x] > dep[y] ) ? y : x ; 
}
bool cmp( int x, int y ) {
	return dfn[x] < dfn[y] ; 
}
void insert( int x ) {
	if( top == 1 ) { s[++ top] = x; return ; }
	int lca = LCA( s[top], x ) ;
	while( top > 1 && dfn[s[top - 1]] > dfn[lca] ) add( s[top - 1], s[top] ), -- top ;
	if( dfn[lca] < dfn[s[top]] ) add( lca, s[top] ), -- top ; 
	if( dfn[lca] > dfn[s[top]] ) s[++ top] = lca ; 
	s[++ top] = x ; 
}
int flag ; 
void dfs3( int x, int fa ) {
	if( vis[x] ) {
		Next( i, x ) {
			int v = e[i].to ; if( v == fa ) continue ; 
			dfs3( v, x ) ; if( vis[v] ) vis[v] = 0, ++ Ans ; 
		}
	}
	else {
		Next( i, x ) {
			int v = e[i].to ; if( v == fa ) continue ; 
			dfs3( v, x ), vis[x] += vis[v], vis[v] = 0 ;
		}
		if( vis[x] > 1 ) ++ Ans, vis[x] = 0 ;
	}
	head[x] = 0 ;
}
signed main()
{
	n = gi() ; rep( i, 2, n ) add( gi(), gi() ) ;
	dfs( 1, 1 ), dfs2( 1, 1 ) ; memset( head, 0, sizeof(head) ), cnt = 0 ;
	int T = gi(), m ; memset( vis, 0, sizeof(vis) ) ; 
	while( T-- ) {
		flag = 0, cnt = 0, top = 0, Ans = 0 ;
		m = gi() ; rep( i, 1, m ) K[i] = gi(), vis[K[i]] = 1 ; 
		rep( i, 1, m ) if( vis[Fa[K[i]]] && K[i] != 1 ) flag = 1 ; 
		sort( K + 1, K + m + 1, cmp ) ; s[top = 1] = 1 ; 
		rep( i, 1, m ) insert( K[i] ) ;
		while( top > 1 ) add( s[top - 1], s[top] ), -- top ;
		dfs3( 1, 1 ), vis[1] = 0 ;
		if( flag ) puts("-1") ;
		else printf("%d\n", Ans ) ;
	}
	return 0;
}