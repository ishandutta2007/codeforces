#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) x * 2
#define rs(x) x * 2 + 1
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, a[N], b[N], col[N] ; 
struct Tr {
    int w, tag ; 
} tr[N * 3] ;
void pushmark( int x ) {
    if( tr[x].tag ) {
        tr[ls(x)].w = 0, tr[rs(x)].w = 0,
        tr[ls(x)].tag = 1, tr[rs(x)].tag = 1,
        tr[x].tag = 0 ;
    }
}
void update( int x, int l, int r, int wh ) {
    if( l == r ) { ++ tr[x].w; return ; }
    int mid = ( l + r ) >> 1 ; pushmark( x ) ;
    if( mid >= wh ) update( ls(x), l, mid, wh ) ;
    else update( rs(x), mid + 1, r, wh ) ;
    tr[x].w = tr[ls(x)].w + tr[rs(x)].w ; 
}
void modify( int x, int l, int r, int ql, int qr ) {
    if( r < ql || l > qr ) return ; 
    if( ql <= l && r <= qr ) { tr[x].w = 0, tr[x].tag = 1; return ; }
    int mid = ( l + r ) >> 1 ; pushmark( x ) ;
    modify( ls(x), l, mid, ql, qr ), modify( rs(x), mid + 1, r, ql, qr ) ;
    tr[x].w = tr[ls(x)].w + tr[rs(x)].w ;
}
int Query( int x, int l, int r, int ql, int qr ) {
    if( r < ql || l > qr ) return 0 ;
    if( ql <= l && r <= qr ) return tr[x].w ; 
    int mid = ( l + r ) >> 1 ; pushmark(x) ;
    return Query( ls(x), l, mid, ql, qr ) + Query( rs(x), mid + 1, r, ql, qr ) ;
}
signed main()
{
    n = gi() ; 
    rep( i, 1, n ) a[i] = gi(), col[a[i]] = i ;
    rep( i, 1, n ) b[i] = gi(), b[i] = col[b[i]] ;
    int Ans = 0 ;
    rep( i, 1, n ) {
        Ans += Query( 1, 1, n, b[i], n ) ;
        modify( 1, 1, n, b[i], n ) ;
        update( 1, 1, n, b[i] ) ;
    }
    printf("%d\n", Ans ) ;
	return 0 ;
}