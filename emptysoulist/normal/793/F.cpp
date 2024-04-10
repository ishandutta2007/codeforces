#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
const int N = 1e5 + 5 ; 
int n, m, q, L[N] ; 
struct SegmentBeat {
	int bef, mx, se, tot, tag ; 
} tr[N << 2] ;
void cmax(int &x, int y) { x = (x < y) ? y : x ; }
inline void pushup(int x) {
	tr[x].tot = tr[x].se = 0, tr[x].mx = max(tr[ls(x)].mx, tr[rs(x)].mx) ;
	if(tr[x].mx == tr[ls(x)].mx)
		tr[x].tot += tr[ls(x)].tot, cmax(tr[x].se, tr[ls(x)].se) ;
	else cmax(tr[x].se, tr[ls(x)].mx) ;
	if(tr[x].mx == tr[rs(x)].mx)
		tr[x].tot += tr[rs(x)].tot, cmax(tr[x].se, tr[rs(x)].se) ;
	else cmax(tr[x].se, tr[rs(x)].mx) ;
	tr[x].bef = tr[x].mx ; 
}
inline void push(int x, int k) { tr[x].mx = k, tr[x].tag = k ; }
inline void pushmark(int x) {
	if(!tr[x].tag) return ; 
	if(tr[ls(x)].mx == tr[x].bef) push(ls(x), tr[x].tag) ;
	if(tr[rs(x)].mx == tr[x].bef) push(rs(x), tr[x].tag) ; 
	tr[x].tag = 0, tr[x].bef = tr[x].mx ; 
}
int query(int x, int l, int r, int k) {
	if(l == r) return tr[x].mx ; 
	int mid = (l + r) >> 1 ; pushmark(x) ;
	if(k <= mid) return query(ls(x), l, mid, k) ;
	else return query(rs(x), mid + 1, r, k) ; 
}
void update(int x, int l, int r, int k, int d) {
	if(l == r) return tr[x].mx = d, tr[x].se = 0, tr[x].tot = 1, void() ; 
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	if(k <= mid) update(ls(x), l, mid, k, d) ;
	else update(rs(x), mid + 1, r, k, d) ;
	pushup(x) ; 
}
void modify(int x, int l, int r, int ql, int qr, int y, int z) {
	if(tr[x].mx < y || r < ql || qr < l) return ; 
	if((ql <= l && r <= qr) && (tr[x].se < y && tr[x].mx >= y)) 
		return push(x, z) ;
	int mid = (l + r) >> 1 ; pushmark(x) ;
	modify(ls(x), l, mid, ql, qr, y, z),
	modify(rs(x), mid + 1, r, ql, qr, y, z), pushup(x) ; 
} vector<pi> p[N] ; int ans[N] ; 
signed main() {
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, m ) x = gi(), y = gi(), L[y] = x ; q = gi() ; 
	rep( i, 1, q ) x = gi(), y = gi(), p[y].pb(mp(x, i)) ; 
	rep( i, 1, n ) {
		update(1, 1, n, i, i) ; 
		if(L[i]) modify(1, 1, n, 1, L[i], L[i], i) ;
		for(auto u : p[i])
		ans[u.second] = query(1, 1, n, u.first) ;  
	}
	rep( i, 1, q ) printf("%d\n", ans[i]) ; 
	return 0 ;
}