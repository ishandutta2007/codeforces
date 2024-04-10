#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define ls(x) tr[x].l
#define rs(x) tr[x].r 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, m, cnt, rt[N << 2], L[N], R[N] ; 
struct Tr { int l, r, mx ; } tr[N * 400] ; 
priority_queue<int> Q ; 
void insert(int &x, int l, int r, int k, int val) {
	if(!x) x = ++ cnt ; 
	if(l == r) return tr[x].mx = max(tr[x].mx, val), void() ; 
	int mid = (l + r) >> 1 ; 
	if(k <= mid) insert(ls(x), l, mid, k, val) ;
	else insert(rs(x), mid + 1, r, k, val) ; 
	tr[x].mx = max(tr[ls(x)].mx, tr[rs(x)].mx) ; 
}
int query(int x, int l, int r, int ql, int qr) {
	if(!x || r < ql || qr < l) return 0 ;
	if(ql <= l && r <= qr) return tr[x].mx ; 
	int mid = (l + r) >> 1 ; 
	return max(query(ls(x), l, mid, ql, qr), query(rs(x), mid + 1, r, ql, qr)) ; 
}
void ins(int x, int l, int r, int k, int p, int val) { 
	insert(rt[x], 1, n, p, val) ; if(l == r) return ; 
	int mid = (l + r) >> 1 ; 
	if(k <= mid) ins(x << 1, l, mid, k, p, val) ;
	else ins(x << 1 | 1, mid + 1, r, k, p, val) ; 
}
int Query(int x, int l, int r, int ql, int qr, int ul, int ur) {
	if(r < ql || qr < l) return 0 ; 
	if(ql <= l && r <= qr) return query(rt[x], 1, n, ul, ur) ; 
	int mid = (l + r) >> 1 ; 
	return max(Query(x << 1, l, mid, ql, qr, ul, ur), 
			Query(x << 1 | 1, mid + 1, r, ql, qr, ul, ur)) ; 
}
int stl[N], str[N], top, ans[N] ; vector<int> rp[N] ; 
signed main() { 
	n = gi(), m = gi() ; 
	rep( i, 1, m ) L[i] = gi(), R[i] = gi() ; 
	rep( i, 1, m / 2 ) swap(L[i], L[m - i + 1]), swap(R[i], R[m - i + 1]) ; 
	rep( i, 1, m ) rp[R[i] - L[i] + 1].pb(i) ; 
	
	drep( x, 1, n ) {
		for(int v : rp[x]) ins(1, 1, n, L[v], R[v], v) ; 
		stl[top = 1] = 1, str[top] = n ; ans[x] = 0 ; 
		for(int i = 1; i <= top; ++ i) {
			if(stl[i] > str[i]) continue ; 
			int u = Query(1, 1, n, stl[i], str[i], stl[i], str[i]) ; 
			if(!u) continue ; ans[x] += (R[u] - L[u] + 1) ; 
			++ top, stl[top] = stl[i], str[top] = L[u] - 1 ;
			++ top, str[top] = str[i], stl[top] = R[u] + 1 ; 
		} 
	}
	rep( x, 1, n ) printf("%d\n", ans[x]) ; 
	return 0 ;
}