#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define ls(x) ( x << 1 ) 
#define rs(x) ( x << 1 | 1 )
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ;
const int inf = 1e9 + 7 ; 
int n, a[N], Mi[N << 2], sum[N << 2], mark[N << 2], st1[N], top1, st2[N], top2, mx[N], mi[N] ;
void pushup( int x ) {
	Mi[x] = min( Mi[ls(x)], Mi[rs(x)] ), sum[x] = 0 ;
	if( Mi[x] == Mi[ls(x)] ) sum[x] += sum[ls(x)] ;
	if( Mi[x] == Mi[rs(x)] ) sum[x] += sum[rs(x)] ; 
}
void pushmark( int x ) {
	if( !mark[x] ) return ;
	mark[ls(x)] += mark[x], mark[rs(x)] += mark[x],
	Mi[ls(x)] += mark[x], Mi[rs(x)] += mark[x], mark[x] = 0 ; 
}
void update( int x, int l, int r, int ql, int qr, int k ) {
	if( qr < l || r < ql ) return ; 
	if( ql <= l && r <= qr ) { Mi[x] += k, mark[x] += k ; return ; }
	int mid = ( l + r ) >> 1 ; pushmark(x) ;
	update( ls(x), l, mid, ql, qr, k ), update( rs(x), mid + 1, r, ql, qr, k ), pushup(x) ;
}
void build( int x, int l, int r ) {
	Mi[x] = inf, sum[x] = 0 ; if( l == r ) return ; 
	int mid = ( l + r ) >> 1 ; 
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
}
void change( int x, int l, int r, int w, int k ) {
	if( l == r ) { Mi[x] = 0, mark[x] = 0, sum[x] = 1 ; return ; }
	int mid = ( l + r ) >> 1 ; 	pushmark(x) ; 
	if( mid >= w ) change( ls(x), l, mid, w, k ) ;
	else change( rs(x), mid + 1, r, w, k ) ;
	pushup(x) ; 
}
signed main()
{
	n = gi() ; int x, Ans = 0, fl ; 
	rep( i, 1, n ) x = gi(), a[x] = gi() ; 
	build( 1, 1, n ), memset( mi, 63, sizeof(mi) ) ;
	rep( i, 1, n ) {
		if( i > 1 ) update( 1, 1, n, 1, i - 1, -1 ) ; change( 1, 1, n, i, 0 ) ; 
		fl = 0 ; while( top1 && a[i] > mx[st1[top1]] ) 
			update( 1, 1, n, st1[top1], i - 1, a[i] - mx[st1[top1]] ), -- top1, fl = 1 ; 
		( fl ) ? ++ top1, mx[st1[top1]] = a[i] : st1[++ top1] = i, mx[i] = a[i] ;
		
		fl = 0 ; while( top2 && a[i] < mi[st2[top2]] ) 
			update( 1, 1, n, st2[top2], i - 1, mi[st2[top2]] - a[i] ), -- top2, fl = 1 ; 
		( fl ) ? ++ top2, mi[st2[top2]] = a[i] : st2[++ top2] = i, mi[i] = a[i] ;
		Ans += sum[1] ; 
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}