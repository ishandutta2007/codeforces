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
const int N = 3e5 + 5 ; 
const int maxn = 1e9 ; 
#define ls(x) t[x].l
#define rs(x) t[x].r
#define ln(x) (x << 1)
#define rn(x) (x << 1 | 1)
int n, m, cnt, ans[N], a[N], rt[N] ; 
struct Tr { int l, r, mx ; } t[N * 30] ; 
struct node { int mi ; } tr[N << 2] ; 
void insert(int &x, int u, int l, int r, int w, int k) {
	x = ++ cnt, t[x] = t[u], t[x].mx = k ; 
	if(l == r) return ; int mid = (l + r) >> 1 ; 
	if(w <= mid) insert(ls(x), ls(u), l, mid, w, k) ; 
	else insert(rs(x), rs(u), mid + 1, r, w, k) ; 
}
int query(int x, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return 0 ; 
	if(ql <= l && r <= qr) return t[x].mx ; 
	int mid = (l + r) >> 1 ; 
	return max(query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr)) ; 
}
void build(int x, int l, int r) {
	if(l == r) return tr[x].mi = maxn, void() ; 
	int mid = (l + r) >> 1 ; 
	build(ln(x), l, mid), build(rn(x), mid + 1, r) ; 
	tr[x].mi = min(tr[ln(x)].mi, tr[rn(x)].mi) ;
}
int query(int x, int l, int r, int k) { 
	if(l == r) return tr[x].mi ; int mid = (l + r) >> 1 ; 
	if(k <= mid) return min(query(ln(x), l, mid, k), tr[rn(x)].mi) ; 
	else return query(rn(x), mid + 1, r, k) ; 
}
void update(int x, int l, int r, int w, int k) {
	if(l == r) return tr[x].mi = min(tr[x].mi, k), void() ; 
	int mid = (l + r) >> 1 ; 
	if(w <= mid) update(ln(x), l, mid, w, k) ; 
	else update(rn(x), mid + 1, r, w, k) ; 
	tr[x].mi = min(tr[ln(x)].mi, tr[rn(x)].mi) ;
}
vector<pi> q[N] ; 
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 1, n ) a[i] = gi(), 
		insert(rt[i], rt[i - 1], 0, maxn, a[i], i) ; 
	m = gi() ; 
	rep( i, 1, m ) x = gi(), y = gi(), q[y].pb(mp(x, i)) ; 
	build(1, 1, n) ; 
	rep( i, 2, n ) {
		int bef = i - 1, l = 0, r = a[i] ; 
		while(bef > 0) {
			bef = query(rt[bef], 0, maxn, l, r) ;
			if(bef) update(1, 1, n, bef, abs(a[bef] - a[i])) ; 
			l = (a[bef] + a[i] + 2) / 2, -- bef ; 
		}
		bef = i - 1, l = a[i], r = maxn ; 
		while(bef > 0) {
			bef = query(rt[bef], 0, maxn, l, r) ;
			if(bef) update(1, 1, n, bef, abs(a[bef] - a[i])) ; 
			r = (a[bef] + a[i] - 1) / 2, -- bef ; 
		}
		for(auto u : q[i]) ans[u.second] = query(1, 1, n, u.first) ; 
	}
	rep( i, 1, m ) printf("%d\n", ans[i]) ; 
	return 0 ; 
}