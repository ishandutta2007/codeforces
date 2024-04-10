#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, q, a[N] ; 
struct Tr {
	int mx, mi, w, tag ; 
} tr[N << 2] ; 
void pushup(int x) {
	tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ) ; 
	tr[x].mx = max( tr[ls(x)].mx, tr[rs(x)].mx ) ;
	tr[x].w = tr[ls(x)].w + tr[rs(x)].w ; 
}
void pushmark(int x, int l, int r) {
	int u = tr[x].tag, mid = (l + r) >> 1 ; 
	if(!u) return ; 
	tr[ls(x)].tag = u, tr[rs(x)].tag = u ;
	tr[ls(x)].mx = u, tr[ls(x)].w = (mid - l + 1) * u,
	tr[rs(x)].mx = u, tr[rs(x)].w = (r - mid) * u ;  
	tr[ls(x)].mi = u, tr[rs(x)].mi = u ; 
	tr[x].tag = 0 ; 
}
int query(int x, int l, int r, int k) {
	if( r <= k ) return tr[x].w ; 
	int mid = (l + r) >> 1 ; pushmark(x, l, r) ; 
	if( mid < k ) return tr[ls(x)].w + query(rs(x), mid + 1, r, k) ;
	else return query(ls(x), l, mid, k) ; 
}
void update(int x, int l, int r, int ql, int qr, int k) {
	if( ql <= l && r <= qr ) { tr[x].mx = tr[x].mi = tr[x].tag = k, tr[x].w = (r - l + 1) * k ; return ; }
	if( l > qr || r < ql ) return ; 
	int mid = (l + r) >> 1 ; pushmark(x, l, r) ; 
	update(ls(x), l, mid, ql, qr, k), update(rs(x), mid + 1, r, ql, qr, k) ; 
	pushup(x) ; 
} 
int Get1(int x, int l, int r, int S) {
	if( l == r ) return (tr[x].mx <= S) ? l : n + 1 ; 
	int mid = (l + r) >> 1 ; pushmark(x, l, r) ; 
	if( tr[ls(x)].mi <= S ) return Get1(ls(x), l, mid, S) ;
	else return Get1(rs(x), mid + 1, r, S) ;  
}
int Get2(int x, int l, int r, int S) {
	if( l == r ) return (tr[x].w <= S) ? l : l - 1 ; 
	int mid = (l + r) >> 1 ;  pushmark(x, l, r) ; 
	if( tr[ls(x)].w > S ) return Get2(ls(x), l, mid, S) ;
	else return Get2(rs(x), mid + 1, r, S - tr[ls(x)].w) ;  
}
void build(int x, int l, int r) {
	if( l == r ) return tr[x].w = tr[x].mi = tr[x].mx = a[l], void() ; 
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r), pushup(x) ; 
}
signed main()
{
	n = gi(), q = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	build(1, 1, n) ; int type, x, k ; 
	rep( i, 1, q ) {
		type = gi(), x = gi(), k = gi() ; 
		if(type == 1) {
			int l = Get1(1, 1, n, k) ; 
			if( l > x ) continue ; 
			update(1, 1, n, l, x, k) ; 
		}
		else {
			int ans = 0 ; 
			while(233) {
				int bg = Get1(1, 1, n, k) ;
				//printf("QAQ Get1 %lld %lld\n", bg, k ) ; 
				bg = max( bg, x ) ;
				if( bg == n + 1 ) break ; 
				int st = ((bg == 1) ? 0 : query(1, 1, n, bg - 1)) ; 
				int go = Get2(1, 1, n, st + k) ;
			//	printf("qaq %lld %lld\n", bg, go ) ; 
				ans += (go - bg + 1) ; 
				k -= (query(1, 1, n, go) - st), x = go + 1 ; 
			}
			cout << ans << endl ; 
		}
	}
	return 0 ;
}
/*
10 7
10 10 10 6 6 5 5 5 3 1
2 2 17
2 3 50
2 4 10
1 3 10
2 2 36
1 4 7
2 2 17
*/