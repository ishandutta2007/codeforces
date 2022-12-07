#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long 
#define ls(x) x * 2
#define rs(x) x * 2 + 1
#define inf 12345678900
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, a[N], col[N], s[N], top, Ans[N] ; 
struct Tr {
    int w ;
} tr[N * 3] ; 
int check( int x ) {
    int l = 1, r = top, ans = 1, mid ; 
    while( l <= r ) {
        mid = ( l + r ) >> 1 ; 
        if( a[s[mid]] <= x ) ans = mid, l = mid + 1 ; 
        else r = mid - 1 ; 
    }
    return s[ans] ; 
}
void build( int x, int l, int r ) {
	if( l == r ) { tr[x].w = col[l] ; return ; }
	int mid = ( l + r ) >> 1 ;
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
	tr[x].w = min( tr[ls(x)].w, tr[rs(x)].w ) ;
}
int Query( int x, int l, int r, int ql, int qr ) {
	if( ql > r || l > qr ) return inf ;
	if( ql <= l && r <= qr ) return tr[x].w ;
	int mid = ( l + r ) >> 1 ;
	return min( Query( ls(x), l, mid, ql, qr ), Query( rs(x), mid + 1, r, ql, qr ) ) ;
}
signed main()
{
    n = gi() ; int Mx = -inf, Mi = inf ;
    rep( i, 1, n ) a[i] = gi(), a[i + n] = a[i], a[i + 2 * n] = a[i], Mi = min( Mi, a[i] ), Mx = max( Mx, a[i] ) ; 
    if( ( Mx + 1 ) / 2 - 1 < Mi ) {
    	rep( i, 1, n ) printf("-1 ") ;
    	exit(0) ; 
	}
    n = n * 3, s[++ top] = n + 1 ; 
    for( re int i = n; i >= 1; -- i ) {
        col[i] = check( ( a[i] + 1 ) / 2 - 1 ) ;
        while( a[s[top]] >= a[i] ) -- top ; 
        s[++ top] = i ;
    }
    build( 1, 1, n ) ; n /= 3 ; 
    for( re int i = n; i >= 1; -- i ) {
    	Ans[i] = Query( 1, 1, 3 * n, i, 3 * n ) - i ;
	}
	rep( i, 1, n ) printf("%I64d ", Ans[i] ) ;
	return 0 ;
}