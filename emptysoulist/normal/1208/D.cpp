#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
#define Ls ( x << 1 ) 
#define Rs ( x << 1 | 1 )
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 12345678000000 ;
const int N = 2e5 + 5 ; 
int Mi[N << 2], tag[N << 2], n, A[N] ;  
void build( int x, int l, int r ) {
	if( l == r ) { Mi[x] = A[l] ; return ; }
	int mid = ( l + r ) >> 1 ; 
	build( Ls, l, mid ), build( Rs, mid + 1, r ),
	Mi[x] = min( Mi[Ls], Mi[Rs] ) ;
}
void pushmark( int x ) {
	if( tag[x] ) {
		tag[Ls] += tag[x], tag[Rs] += tag[x], 
		Mi[Ls] += tag[x], Mi[Rs] += tag[x], tag[x] = 0 ; 
	} 
} 
int Query( int x, int l, int r ) {
	if( l == r ) return l ;
	int mid = ( l + r ) >> 1 ; pushmark(x) ; 
	if( !Mi[Rs] ) return Query( Rs, mid + 1, r ) ;
	else return Query( Ls, l, mid ) ;
}
void Update( int x, int l, int r, int ql, int qr, int k ) {
	if( l > qr || r < ql || ql > qr ) return ; 
	if( ql <= l && r <= qr ) { tag[x] += k, Mi[x] += k ; return ; }
	int mid = ( l + r ) >> 1 ; pushmark(x) ; 
	Update( Ls, l, mid, ql, qr, k ), Update( Rs, mid + 1, r, ql, qr, k ) ;
	Mi[x] = min( Mi[Ls], Mi[Rs] ) ;
}
void Change( int x, int l, int r, int pos ) {
	if( l == r ) { Mi[x] = inf ; return ; }
	int mid = ( l + r ) >> 1 ; pushmark(x) ; 
	if( mid >= pos ) Change( Ls, l, mid, pos ) ;
	else Change( Rs, mid + 1, r, pos ) ;
	Mi[x] = min( Mi[Ls], Mi[Rs] ) ;
}
signed main()
{
	n = gi() ; rep( i, 1, n ) A[i] = gi() ; 
	build( 1, 1, n ) ;
	rep( i, 1, n ) {
		int l = Query( 1, 1, n ) ; 
		A[l] = i, Update( 1, 1, n, l + 1, n, -i ), Change( 1, 1, n, l ) ;
	}
	rep( i, 1, n ) printf("%I64d ", A[i] ) ;
	return 0 ;
}