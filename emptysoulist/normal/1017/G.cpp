#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e9 + 5 ; 
const int N = 2e5 + 5 ;
int n, q, idnex, L[N], R[N], Id[N] ;
int top[N], f[N], dep[N], sz[N], son[N] ;
vector<int> G[N] ; 
struct Tr { int w, c, tag, mark ; } tr[N << 2] ;
void dfs1(int x, int fa) {
	f[x] = fa, dep[x] = dep[fa] + 1, sz[x] = 1 ;
	for(int v : G[x]) {
		dfs1(v, x), sz[x] += sz[v] ;
		if( sz[v] > sz[son[x]] ) son[x] = v ; 
	} 
}
void dfs2(int x, int high) {
	top[x] = high, L[x] = ++ idnex, Id[idnex] = x ; 
	if(son[x]) dfs2(son[x], high) ;
	for(int v : G[x]) if( v ^ son[x] ) dfs2(v, v) ;
	R[x] = idnex ; 
}
void pushup(int x) { tr[x].w = min(tr[ls(x)].w, tr[rs(x)].w ) ; }
void Col(int x) {
	tr[x].mark = 1, tr[x].w = tr[x].c, tr[x].tag = 0 ; 
}
void pushmark(int x) {
	if( tr[x].mark ) Col(ls(x)), Col(rs(x)), tr[x].mark = 0 ; 
	int s = tr[x].tag ; tr[x].tag = 0 ;
	tr[ls(x)].tag += s, tr[rs(x)].tag += s,
	tr[ls(x)].w += s, tr[rs(x)].w += s ;  
}
void build(int x, int l, int r) {
	if( l == r ) return tr[x].w = tr[x].c = -dep[Id[l]], void() ;
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r), pushup(x), tr[x].c = tr[x].w ; 
}
void Cover(int x, int l, int r, int ql, int qr) {
	if( ql <= l && r <= qr ) return Col(x), void() ; 
	if( qr < l || r < ql ) return ; 
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	Cover(ls(x), l, mid, ql, qr), Cover(rs(x), mid + 1, r, ql, qr), pushup(x) ; 
}
void update(int x, int l, int r, int ql, int qr, int k) {
	if( ql <= l && r <= qr ) return tr[x].w += k, tr[x].tag += k, void() ; 
	if( qr < l || r < ql ) return ; 
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	update(ls(x), l, mid, ql, qr, k), 
	update(rs(x), mid + 1, r, ql, qr, k), pushup(x) ; 
}
int query(int x, int l, int r, int ql, int qr) {
	if( ql <= l && r <= qr ) return tr[x].w ; 
	if( qr < l || r < ql ) return 0 ;
	int mid = (l + r) >> 1 ; pushmark(x) ;
	return min(query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr)) ; 
}
int Q(int x) { 
	int ans = inf ; 
	while( x != 1 ) ans = min( ans, query( 1, 1, n, L[top[x]], L[x]) ), x = f[top[x]] ; 
	ans = min( ans, query(1, 1, n, L[top[x]], L[x]) ) ;
	return ans ; 
}
void White(int x) {
	Cover(1, 1, n, L[x], R[x]) ; 
	int c = Q(f[x]), w = query(1, 1, n, L[x], L[x]) ; 
	c = max( 0, c - w - 1 ), update(1, 1, n, L[x], R[x], c) ; 
}
void Query(int x) {
	int c = Q(f[x]), w = query(1, 1, n, L[x], L[x]) ; 
	if( c <= w ) puts("black") ;
	else puts("white") ; 
} 
signed main()
{
	n = gi() + 1, q = gi() ; int opt, x ; 
	rep( i, 3, n ) x = gi() + 1, G[x].push_back(i) ; 
	G[1].push_back(2) ; 
	dfs1(1, 1), dfs2(1, 1), build(1, 1, n) ;
	rep( i, 1, q ) {
		opt = gi(), x = gi() + 1 ; 
		if( opt == 1 ) update(1, 1, n, L[x], R[x], 1) ;
		if( opt == 2 ) White(x) ; 
		if( opt == 3 ) Query(x) ;  
	}
	return 0 ;
}