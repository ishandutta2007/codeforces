#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, q, idx, Id[N], w[N], dfn[N], dep[N], fa[N], top[N], sz[N], son[N] ; 
vi G[N] ; 
struct node {
	int u, v, f ; 
	node(int _u = 0, int _v = 0, int _f = 0) { u = _u, v = _v, f = _f ; }
	void init() { u = 0, v = 0, f = 0 ; }
} tr[N << 2], fs ;
void dfs1(int x) {
	sz[x] = 1, dep[x] = dep[fa[x]] + 1 ; 
	for(int v : G[x]) {
		dfs1(v), sz[x] += sz[v] ; 
		if( sz[v] >= sz[son[x]] ) son[x] = v ;
	} 
}
void dfs2(int x, int high) {
	top[x] = high, dfn[x] = ++ idx ; 
	if(son[x]) dfs2(son[x], high) ;
	for(int v : G[x]) if(v ^ son[x]) dfs2(v, v) ; 
}
int LCA(int x, int y) {
	while( top[x] != top[y] ) {
		if( dep[top[x]] < dep[top[y]] ) swap(x, y) ;
		x = fa[top[x]] ; 
	} return (dep[x] > dep[y]) ? y : x ; 
}
int dis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)] ;
}
int a[10] ;
node merge(node x, node y) {
	if( x.f || y.f ) return node(-1, -1, 1) ;
	a[0] = x.u, a[1] = x.v, a[2] = y.u, a[3] = y.v ;
	sort(a, a + 4) ;
	do {
		int d = dis(a[0], a[3]) ;
		for(int i = 1; i < 4; ++ i) d -= dis(a[i], a[i - 1]) ;
		if( d == 0 ) return node(a[0], a[3], 0) ; 
	} while(next_permutation(a, a + 4)) ; 
	return node(-1, -1, 1) ;
}
void build(int x, int l, int r) {
	if( l == r ) return tr[x] = node(Id[l], Id[l], 0), void() ;
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r) ; 
	tr[x] = merge(tr[ls(x)], tr[rs(x)]) ; 
//	printf("build %d [%d %d] %d %d %d\n", x, l, r, tr[x].u, tr[x].v, tr[x].f) ;
}
void update(int x, int l, int r, int k, node u) {
	if( l == r ) return tr[x] = u, void() ; 
	int mid = (l + r) >> 1 ;
	if( k <= mid ) update(ls(x), l, mid, k, u) ;
	else update(rs(x), mid + 1, r, k, u) ;
	tr[x] = merge(tr[ls(x)], tr[rs(x)]) ; 
}
bool check(node x) {
	if( x.f ) return 0 ; 
	if( fs.u == 0 ) { fs = x ; return 1 ; }
	node t = merge(x, fs) ; 
	if( t.f ) return 0 ; 
	fs = t ; return 1 ; 
}
int query(int x, int l, int r) {
//	printf("query %d %d %d [%d %d %d]\n", x, l, r, tr[x].u, tr[x].v, tr[x].f ) ; 
	if( l == r ) return (check(tr[x])) ? l : 0 ; 
	int mid = (l + r) >> 1 ; 
	if(check(tr[ls(x)])) return max(mid, query(rs(x), mid + 1, r)) ; 
	else return query(ls(x), l, mid) ; 
}
void Change(int x, int y) {
//	printf("Change %d %d - %d %d\n", w[x], w[y], x, y ) ; 
	update(1, 0, n - 1, w[x], node(y, y, 0) ),
	update(1, 0, n - 1, w[y], node(x, x, 0) ),
	swap(w[x], w[y]) ; 
}
signed main()
{
	n = gi() ; int opt, x, y ;
	rep( i, 1, n ) x = gi(), Id[x] = i, w[i] = x ; 
	rep( i, 2, n ) fa[i] = gi(), G[fa[i]].pb(i) ; 
	dfs1(1), dfs2(1, 1), build(1, 0, n - 1) ; 
	q = gi() ; 
	while( q-- ) {
		opt = gi() ; 
		if(opt == 1) x = gi(), y = gi(), Change(x, y) ; 
		else fs.init(), printf("%d\n", query(1, 0, n - 1) + 1 ) ;  
	} 
	return 0 ;
}