#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) x * 2
#define rs(x) x * 2 + 1
#define int long long
#define pushup(x) tr[x].w = max( tr[ls(x)].w, tr[rs(x)].w ) ;
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ;
const int M = 2e5 + 5 ; 
const int inf = 1e12 + 7 ;
int n, m, p ;  
struct Tr {
	int w, tag ; 
} tr[N << 2] ;
struct node {
	int x, f, c ; 
} a[M], b[M], t[M] ;
bool cmp( node x, node y ) {
	return x.x < y.x ; 
}
void pushmark( int x, int mid, int l, int r ) {
	if( tr[x].tag ) {
		tr[ls(x)].tag += tr[x].tag, tr[ls(x)].w += tr[x].tag ; 
		tr[rs(x)].tag += tr[x].tag, tr[rs(x)].w += tr[x].tag ; 
		tr[x].tag = 0 ;
	}
}
void update( int x, int l, int r, int ql, int qr, int w ) {
	if( l > qr || r < ql ) return ; 
	if( ql <= l && r <= qr ) { tr[x].tag += w, tr[x].w += w ; return ; }
	int mid = ( l + r ) >> 1 ; pushmark( x, mid, l, r ) ;
	update( ls(x), l, mid, ql, qr, w ), update( rs(x), mid + 1, r, ql, qr, w ) ;
	pushup(x) ; 
}
void Change( int x, int l, int r, int wh, int w ) {
	if( l == r ) {
		tr[x].w = max( tr[x].w, w ) ; return ; 
	}
	int mid = ( l + r ) >> 1 ;
	if( mid >= wh ) Change( ls(x), l, mid, wh, w ) ;
	else Change( rs(x), mid + 1, r, wh, w ) ;
	pushup(x) ;
}
void build( int x, int l, int r ) {
	tr[x].w = -inf ; 
	if( l == r ) return ; 
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
}
signed main()
{
	n = gi(), m = gi(), p = gi() ; int Mx = 0 ;
	rep( i, 1, n ) a[i].x = gi(), a[i].c = gi() ;
	rep( i, 1, m ) b[i].f = gi(), b[i].c = gi(), Mx = max( b[i].f, Mx ) ;
	rep( i, 1, p ) t[i].x = gi(), t[i].f = gi(), t[i].c = gi(), Mx = max( t[i].f, Mx ) ;
	sort( t + 1, t + p + 1, cmp ), ++ Mx ;
	sort( a + 1, a + n + 1, cmp ) ;
	build( 1, 1, Mx ) ;
	rep( i, 1, m ) {
		Change( 1, 1, Mx, b[i].f, -b[i].c ) ;
	}
	int ll = 0, Ans = -inf ;
	for( re int i = 1; i <= n; ++ i ) {
		while( ll < p && t[ll + 1].x < a[i].x )
		++ ll, update( 1, 1, Mx, t[ll].f + 1, Mx, t[ll].c ) ;
		Ans = max( Ans, tr[1].w - a[i].c ) ;
	}
	cout << Ans << endl ; 
	return 0 ;
}