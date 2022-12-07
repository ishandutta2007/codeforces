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
const int N = 5e5 + 5 ; 
int n, m, t, p[N], fa[N], f[N][20], L[N], R[N], Id[N], w[N], num  ; 
vector<int> G[N] ;  
struct E {
	int fr, to, t ; 
} e[N << 1] ;
struct Q {
	int opt, x ; 
} q[N] ;
bool cmp( E x, E y ) {
	return x.t > y.t ; 
}
int fd(int x) {
	return (fa[x] != x) ? fa[x] = fd(fa[x]) : x ; 
}
void add(int x, int y) {
	G[x].push_back(y) ; 
}
void Dfs(int x, int ff) {
	f[x][0] = ff ; 
	rep( i, 1, 17 ) f[x][i] = f[f[x][i - 1]][i - 1] ; 
	if( x <= n ) return L[x] = R[x] = ++ num, Id[num] = x, void() ; 
	L[x] = n + 1 ; 
	for(int v : G[x]) Dfs(v, x), L[x] = min(L[x], L[v]) ;
	R[x] = num ; 
}
void Kruskal() {
	sort( e + 1, e + m + 1, cmp ) ; 
	rep( i, 1, n ) fa[i] = i ; int idx = n ;
	rep( i, 1, m ) {
		int x = e[i].fr, y = e[i].to ; 
		int u = fd(x), v = fd(y) ;
		if( u == v ) continue ; 
		++ idx, add(idx, u), add(idx, v),
		fa[u] = fa[v] = idx, fa[idx] = idx, w[idx] = e[i].t ; 
	} 
	rep( i, 1, idx ) if( fa[i] == i ) add(idx + 1, i) ; 
	Dfs(idx + 1, idx + 1) ; 
}
struct Tr {
	int mx, id ; 
} tr[N << 2], Zero ; 
Tr pushup(Tr l, Tr r) {
	return ( r.mx > l.mx ) ? r : l ; 
} 
void build(int x, int l, int r) {
	if( l == r ) return tr[x].mx = p[Id[l]], tr[x].id = Id[l], void() ; 
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r) ;
	tr[x] = pushup(tr[ls(x)], tr[rs(x)]) ;
}
Tr query(int x, int l, int r, int ql, int qr) {
	if( ql <= l && r <= qr ) return tr[x] ;
	if( l > qr || r < ql ) return Zero ; 
	int mid = (l + r) >> 1 ; 
	return pushup(query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr)) ; 
}
void update(int x, int l, int r, int k ) {
	if( l == r ) return tr[x].mx = 0, void() ;
	int mid = (l + r) >> 1 ; 
	if( k <= mid ) update(ls(x), l, mid, k) ;
	else update(rs(x), mid + 1, r, k) ;
	tr[x] = pushup(tr[ls(x)], tr[rs(x)]) ; 
}
signed main()
{
	n = gi(), m = gi(), t = gi() ; int x, y ; 
	rep( i, 1, n ) p[i] = gi() ; 
	rep( i, 1, m ) 
		x = gi(), y = gi(), e[i] = (E){x, y, t + 1} ; 
	rep( i, 1, t ) {
		q[i].opt = gi(), q[i].x = gi() ;
		if( q[i].opt == 2 ) e[q[i].x].t = i ; 
	}
	Kruskal(), Zero.mx = Zero.id = 0, build(1, 1, n) ;
	rep( i, 1, t ) {
		if( q[i].opt == 2 ) continue ; 
		int u = q[i].x ; 
		drep( j, 0, 17 ) if( w[f[u][j]] >= i ) u = f[u][j] ;
		Tr ans = query(1, 1, n, L[u], R[u]) ; 
		if( ans.mx == 0 ) puts("0") ;
		else printf("%d\n", ans.mx ), update(1, 1, n, L[ans.id]) ; 
	}
	return 0 ;
}