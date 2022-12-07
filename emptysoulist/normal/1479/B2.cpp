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
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
const int N = 2e5 + 5 ; 
int n, a[N] ; 
struct Tr {
	int w, tag ; 
} tr[N << 2] ; 
void pushdown(int x) {
	if(!tr[x].tag) return ; 
	tr[x].tag = 0, tr[ls(x)].tag = tr[rs(x)].tag = 1 ;
	tr[ls(x)].w = tr[rs(x)].w = 0 ; 
}
void build(int x, int l, int r) {
	if(l == r) return tr[x].w = 0, void() ; 
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r) ; 
	tr[x].w = (tr[ls(x)].w + tr[rs(x)].w) ; 
}
void update(int x, int l, int r, int k, int type) {
	if(l == r) return tr[x].w = type, void() ; 
	int mid = (l + r) >> 1 ; pushdown(x) ; 
	if(k <= mid) update(ls(x), l, mid, k, type) ;
	else update(rs(x), mid + 1, r, k, type) ;
	tr[x].w = (tr[ls(x)].w + tr[rs(x)].w) ; 
}
int query(int x, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return tr[x].w ; 
	if(qr < l || r < ql) return 0 ; 
	int mid = (l + r) >> 1 ; pushdown(x) ; 
	return query(ls(x), l, mid, ql, qr) + query(rs(x), mid + 1, r, ql, qr) ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	int ans = 0 ; 
	for(int i = 1; i <= n; ++ i) {
		int col = a[i] ; 
		int z = query(1, 0, n, a[i], a[i]) ; 
		if(col == a[i - 1]) continue ; 
		else {
			ans += (z == 0) ; 
			if(z) {
				tr[1].tag = 1, update(1, 0, n, a[i - 1], 1) ; 
			}
			else update(1, 0, n, a[i - 1], 1) ; 
		}
	}
	cout << ans << endl ; 
	return 0 ;
}