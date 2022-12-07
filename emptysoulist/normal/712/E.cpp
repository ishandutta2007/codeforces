#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 )
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const double eps = 1e-9 ;
int n, q ; double p[N] ; 
struct Tr {
	double f, g ; 
} tr[N << 1] ; 
Tr pushup( Tr x, Tr y ) {
	Tr u ; 
	u.f = x.f * y.f / ( x.g + y.f - x.g * y.f + eps ) ;
	u.g = x.g * y.g / ( x.g + y.f - x.g * y.f + eps ) ;
	return u ; 
}
Tr query( int x, int l, int r, int ql, int qr ) {
	if( ql <= l && r <= qr ) return tr[x] ; 
	int mid = ( l + r ) >> 1 ; 
	if( mid >= qr ) return query( ls(x), l, mid, ql, qr ) ;
	if( mid < ql ) return query( rs(x), mid + 1, r, ql, qr ) ;
	return pushup( query( ls(x), l, mid, ql, mid ), query( rs(x), mid + 1, r, mid + 1, qr )  );
}
void update( int x, int l, int r, int wh ) {
	if( l == r ) { tr[x].f = p[l], tr[x].g = 1 - p[l] ; return ; }
	int mid = ( l + r ) >> 1 ; 
	if( wh <= mid ) update( ls(x), l, mid, wh ) ;
	else update( rs(x), mid + 1, r, wh ) ; 
	tr[x] = pushup( tr[ls(x)], tr[rs(x)] ) ;
}
void build( int x, int l, int r ) {
	if( l == r ) { tr[x].f = p[l], tr[x].g = 1 - p[l] ; return ; }
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ; 
	tr[x] = pushup( tr[ls(x)], tr[rs(x)] ) ;
}
signed main()
{
	n = gi(), q = gi() ; int x, y ; 
	rep( i, 1, n ) x = gi(), y = gi(), p[i] = ( 1.0 * x ) / ( 1.0 * y ) ;
	build( 1, 1, n ) ;  
	rep( i, 1, q ) {
		int opt = gi(), l = gi(), r = gi() ; 
		if( opt == 1 ) x = gi(), p[l] = ( 1.0 * r ) / ( 1.0 * x ), update( 1, 1, n, l ) ;
		if( opt == 2 ) printf("%.7lf\n", query( 1, 1, n, l, r ).f ) ;
	}
	return 0 ;
}