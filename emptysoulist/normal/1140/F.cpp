#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1) 
#define fi first
#define se second
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 6e5 + 5 ; 
int n, Ans, maxn, sz[N], cntx[N], cnty[N], fa[N], ans[N] ;  
struct node { int x, y ; } ;
struct Tr {
	vector<node> S ; 
} tr[N << 2] ; 
map<pi, int> S ; 
void insert(int x, int l, int r, int ql, int qr, node k) {
	if(ql <= l && r <= qr) return tr[x].S.pb(k), void() ; 
	if(qr < l || r < ql) return ; 
	int mid = (l + r) >> 1 ; 
	insert(ls(x), l, mid, ql, qr, k), 
	insert(rs(x), mid + 1, r, ql, qr, k) ; 
}
vector<node> q ; 
int fd(int x) { return (fa[x] == x) ? x : fd(fa[x]) ; }
void merge(int x, int y) {
	int u = fd(x), v = fd(y) ; 
	if(u == v) return ; 
	if(sz[u] > sz[v]) swap(u, v) ; 
	Ans -= cntx[u] * cnty[u], Ans -= cntx[v] * cnty[v],
	fa[u] = v, cntx[v] += cntx[u], cnty[v] += cnty[u], 
	Ans += cntx[v] * cnty[v], sz[v] += sz[u], q.pb((node){u, v}) ; 
}
void solve(int x, int l, int r) {
	if(l == r) {
		int lsz = q.size() ; 
		for(node v : tr[x].S) merge(v.x, v.y + maxn) ; 
		ans[l] = Ans ; int siz = q.size() ; 
		for(int i = siz - 1; i >= lsz; -- i) {
			int u = q[i].x, v = q[i].y ; Ans -= cntx[v] * cnty[v], 
			fa[u] = u, cntx[v] -= cntx[u], cnty[v] -= cnty[u],
			sz[v] -= sz[u] ; 
			Ans += cntx[u] * cnty[u], Ans += cntx[v] * cnty[v] ; 
		} 
		while( q.size() > lsz ) q.pop_back() ; 
		return ; 
	}
	int mid = (l + r) >> 1, lsz = q.size() ; 
	for(node v : tr[x].S) merge(v.x, v.y + maxn) ; 
	solve(ls(x), l, mid), solve(rs(x), mid + 1, r) ; 
	int siz = q.size() ; 
	for(int i = siz - 1; i >= lsz; -- i) {
		int u = q[i].x, v = q[i].y ; Ans -= cntx[v] * cnty[v], 
		fa[u] = u, cntx[v] -= cntx[u], cnty[v] -= cnty[u],
		sz[v] -= sz[u] ; 
		Ans += cntx[u] * cnty[u], Ans += cntx[v] * cnty[v] ; 
	} 
	while( q.size() > lsz ) q.pop_back() ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 1, n ) {
		x = gi(), y = gi(), maxn = max(max(x, y), maxn) ; 
		if(S[mp(x, y)]) {
			node opt = (node){x, y} ;
			insert(1, 1, n, S[mp(x, y)], i - 1, opt), 
			S[mp(x, y)] = 0 ; 
		}
		else S[mp(x, y)] = i ; 
	}
	for(auto z : S) if(z.se) insert(1, 1, n, z.se, n, (node){z.fi.fi, z.fi.se}) ;
	rep( i, 1, (maxn * 2) ) sz[i] = 1, fa[i] = i ; 
	rep( i, 1, maxn ) cntx[i] = 1, cnty[i + maxn] = 1 ;  
	solve(1, 1, n) ; 
	rep( i, 1, n ) printf("%lld ", ans[i] ) ; 
	return 0 ;
}