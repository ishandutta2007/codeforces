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
const int M = 1e6 + 10 ; 
const int N = 5e5 + 5 ; 
int n, Q, maxn, a[N], op[M] ; 
struct Tr {
	int mi, s, tag ; 
} tr[M << 2] ; 
void pushup( int x ) {
	tr[x].mi = min( tr[rs(x)].mi, tr[ls(x)].mi ), tr[x].s = 0 ; 
	if( tr[rs(x)].mi == tr[x].mi ) tr[x].s += tr[rs(x)].s ; 
	if( tr[ls(x)].mi == tr[x].mi ) tr[x].s += tr[ls(x)].s ; 
}
void pushmark( int x ) {
	if( tr[x].tag ) 
		tr[ls(x)].mi += tr[x].tag, tr[ls(x)].tag += tr[x].tag,
		tr[rs(x)].mi += tr[x].tag, tr[rs(x)].tag += tr[x].tag,
		tr[x].tag = 0 ; 
}
void update( int x, int l, int r, int ll, int rr, int k ) {
	if( l > rr || r < ll ) return ; 
	if( ll <= l && r <= rr ) { tr[x].tag += k, tr[x].mi += k ; return ; }
	int mid = ( l + r ) >> 1 ; pushmark(x) ; 
	update( ls(x), l, mid, ll, rr, k ), 
	update( rs(x), mid + 1, r, ll, rr, k ) ;
	pushup(x) ; 
}
void upd( int x, int l, int r, int u, int k ) {
	if( l == r ) return tr[x].s = k, void() ;
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	if( mid >= u ) upd( ls(x), l, mid, u, k ) ;
	else upd( rs(x), mid + 1, r, u, k ) ; 
	pushup(x) ; 
}
void build( int x, int l, int r ) {
	if( l == r ) return tr[x].s = op[l], void() ; 
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ),
	pushup(x) ; 
}
int qry( int x, int l, int r, int u ) {
	if( l == r ) return tr[x].mi ;
	int mid = (l + r) >> 1 ; pushmark(x) ; 
	if( mid >= u ) return qry( ls(x), l, mid, u ) ;
	else return qry( rs(x), mid + 1, r, u ) ; 
}
signed main()
{
	n = gi(), Q = gi(), maxn = M - 9 ; 
	rep( i, 1, n ) a[i] = gi(), op[a[i]] = 1 ; 
	a[0] = maxn, a[n + 1] = 0, build( 1, 1, maxn ) ; 
	rep( i, 1, n + 1 ) if( a[i] < a[i - 1] ) 
		update( 1, 1, maxn, a[i] + 1, a[i - 1], 1 ) ; 
	rep( i, 1, Q ) {
		int x = gi(), y = gi() ; 
		if( a[x] < a[x - 1] ) update( 1, 1, maxn, a[x] + 1, a[x - 1], -1 ) ; 
		if( a[x + 1] < a[x] ) update( 1, 1, maxn, a[x + 1] + 1, a[x], -1 ) ; 
		upd( 1, 1, maxn, a[x], 0 ), a[x] = y ; 
		if( a[x] < a[x - 1] ) update( 1, 1, maxn, a[x] + 1, a[x - 1], +1 ) ; 
		if( a[x + 1] < a[x] ) update( 1, 1, maxn, a[x + 1] + 1, a[x], +1 ) ;
		upd( 1, 1, maxn, a[x], 1 ) ; 
		printf("%d\n", tr[1].s ) ; 
	}
	return 0 ;
}