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
const int N = 1e6 + 5 ; 
int n, ans[N], c[N], a[N], Id[N] ; 
struct Tree {
    int L, R, l, r, ans, f ;
    void init() { L = R = l = r = ans = f = 0 ; }
    void init2( int x ) { l = r = x, f = 1, L = R = ans = 1 ; }
} tr[N << 2] ; 
set<int> t ; 
bool cmp( int x, int y ) {
    return a[x] > a[y] ; 
}
Tree pushup( Tree lx, Tree rx ) {
    Tree u ; u.init() ; 
    u.ans = max( lx.ans, rx.ans ), u.l = lx.l, u.r = rx.r ;
    if( lx.r ^ rx.l ) 
		u.ans = max( u.ans, lx.R + rx.L ), u.f = ( lx.f & rx.f ),
		u.L = ( lx.f ) ? lx.L + rx.L : lx.L,
		u.R = ( rx.f ) ? rx.R + lx.R : rx.R ; 
	else 
		u.L = lx.L, u.R = rx.R, u.f = 0 ;
	return u ; 
}
void build( int x, int l, int r ) {
	if( l == r ) { tr[x].init2(0) ; return ; }
	int mid = ( l + r ) >> 1 ;
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
	tr[x] = pushup( tr[ls(x)], tr[rs(x)] ) ;
}
Tree query1( int x, int l, int r, int wh ) {
	if( l == r ) return tr[x] ; 
	int mid = ( l + r ) >> 1 ; 
	if( mid >= wh ) return query1( ls(x), l, mid, wh ) ;
	Tree u = query1( rs(x), mid + 1, r, wh ) ;
	return pushup( tr[ls(x)], u ) ;
}
Tree query2( int x, int l, int r, int wh ) {
	if( l == r ) return tr[x] ; 
	int mid = ( l + r ) >> 1 ; 
	if( mid < wh ) return query2( rs(x), mid + 1, r, wh ) ;
	Tree u = query2( ls(x), l, mid, wh ) ;
	return pushup( u, tr[rs(x)] ) ;
}
void modify( int x, int l, int r, int wh ) {
	if( l == r ) { tr[x].init2(1) ; return ; }
	int mid = ( l + r ) >> 1 ; 
	if( mid >= wh ) modify( ls(x), l, mid, wh ) ;
	else modify( rs(x), mid + 1, r, wh ) ;
	tr[x] = pushup( tr[ls(x)], tr[rs(x)] ) ;
}
void solve( int L, int R, int id ) {
	if( t.empty() ) return ; 
	set<int>::iterator it = t.lower_bound(L) ;
	while( it != t.end() ) {
		if( *it <= R ) {
			set<int>::iterator ir = it ; ++ it ;
			ans[*ir] = id, t.erase(ir) ; 
		}
		else break ; 
	}
}
signed main()
{
    n = gi() ; 
    rep( i, 1, n ) a[i] = gi() ; 
    rep( i, 1, n ) Id[i] = i, t.insert( i ) ;
    build( 1, 1, n ) ;
	sort( Id + 1, Id + n + 1, cmp ) ;
	int Ans = 0 ;
    rep( i, 1, n ) {
    //	printf("Modify %lld %lld\n", Id[i], a[Id[i]] ) ;
		modify( 1, 1, n, Id[i] ), c[Id[i]] = 1 ;
    	if( a[Id[i]] != a[Id[i + 1]] ) Ans = max( Ans, ( tr[1].ans - 1 ) / 2 ) ; 
		Tree ll = query1( 1, 1, n, Id[i] ) ; 
		Tree rr = query2( 1, 1, n, Id[i] ) ;
		int Lx = Id[i] - ll.R + 1, Rx = Id[i] + rr.L - 1 ;
		int len = Rx - Lx + 1 ; 
		if( c[Lx] == 0 && c[Rx] == 0 ) continue ; 
		if( c[Lx] == 1 && c[Rx] == 1 ) solve( Lx - 1, Rx + 1, a[Id[i]] ) ;
		if( c[Lx] == 0 && c[Rx] == 1 ) solve( Lx + len / 2, Rx + 1, a[Id[i]] ) ; 
		if( c[Lx] == 1 && c[Rx] == 0 ) solve( Lx - 1, Rx - len / 2, a[Id[i]] ) ;
		if( Lx == Id[i] && Id[i] != 1 ) {
			Tree lll = query1( 1, 1, n, Id[i] - 1 ) ; 
			int lx = Id[i] - lll.R ; len = Id[i] - lx ; 
			if( c[lx] == 1 ) solve( lx - 1, Id[i], a[Id[i]] ) ;
			if( c[lx] == 0 ) solve( lx + len / 2, Id[i], a[Id[i]] ) ; 
		} 
		if( Rx == Id[i] && Id[i] != n ) {
			Tree rrr = query2( 1, 1, n, Id[i] + 1 ) ; 
			int rx = Id[i] + rrr.L ; len = rx - Id[i] ; 
			if( c[rx] == 1 ) solve( Id[i], rx, a[Id[i]] ) ;
			if( c[rx] == 0 ) solve( Id[i], rx - len / 2, a[Id[i]] ) ; 
		} 
	}
    printf("%d\n", Ans ) ;
    rep( i, 1, n ) printf("%d ", ans[i] ) ;
	return 0 ;
}