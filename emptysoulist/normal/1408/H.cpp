#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define pushup(x) (tr[x].mi = min( tr[ls(x)].mi, tr[rs(x)].mi ))
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
int n, Col, a[N], pre[N], nxt[N], Z, vis[N] ; 
int L, R, m, Lw[N], Rw[N], Ans ; 
struct Tr {
	int mi, tag ;
} tr[N << 2] ;
void pushmark(int x) {
	int d = tr[x].tag ; 
	tr[ls(x)].tag += d, tr[rs(x)].tag += d, 
	tr[ls(x)].mi += d, tr[rs(x)].mi += d, tr[x].tag = 0 ; 
}
void update(int x, int l, int r, int ql, int qr) {
	if( ql <= l && r <= qr ) return -- tr[x].tag, -- tr[x].mi, void() ;
	if( r < ql || qr < l ) return ; 
	int mid = (l + r) >> 1 ; pushmark(x) ;
	update(ls(x), l, mid, ql, qr), update(rs(x), mid + 1, r, ql, qr), pushup(x) ;
}
void build(int x, int l, int r) {
	if( l == r ) return tr[x].mi = l, void() ; 
	int mid = (l + r) >> 1 ; 
	build(ls(x), l, mid), build(rs(x), mid + 1, r), pushup(x) ;
}
void solve() {
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), vis[a[i]] = 1 ; 
	rep( i, 1, n ) pre[i] = pre[i - 1] + (a[i] == 0) ;
	drep( i, 1, n ) nxt[i] = nxt[i + 1] + (a[i] == 0) ;
	Z = pre[n] / 2, Ans = Z, L = 0, R = 0 ; 
	rep( i, 1, n ) if( pre[i] <= Z ) ++ L ; 
	R = L + 1, Col = 0 ; 
	rep( i, 1, n ) if( vis[i] ) ++ Col ; 
	rep( i, 1, n ) Rw[i] = n + 1 ; 
	rep( i, 1, L ) Lw[a[i]] = i ; 
	drep( i, R, n ) Rw[a[i]] = i ; 
	m = nxt[R], build(1, 0, m), Ans = min(Ans, Col) ; 
	rep( i, 1, n ) if( vis[i] && (!Lw[i]) ) {
		update(1, 0, m, nxt[Rw[i]], m) ; 
		Ans = min(Ans, Col + tr[1].mi ) ; 
	} 
	for(re int i = 1; i <= L; ++ i) {
		int u = a[i] ; 
		if( Lw[u] == i ) {
			update(1, 0, m, nxt[Rw[u]], m) ; 
			Ans = min(Ans, Col + tr[1].mi + pre[i]) ; 
		}
	}
	cout << Ans << endl ; 
	rep( i, 1, n ) pre[i] = nxt[i] = Lw[i] = Rw[i] = vis[i] = 0 ;
	rep( i, 1, n * 4 ) tr[i].mi = tr[i].tag = 0 ;  
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ;  
	return 0 ;
}