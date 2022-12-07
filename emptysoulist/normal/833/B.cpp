#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) x * 2
#define rs(x) x * 2 + 1
int gi() {
    int cn = 0, flus = 1 ; char cc = getchar() ;
    while( cc > '9' || cc < '0' ) cc = getchar() ;
    while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
    return cn * flus ; 
}
const int inf = 50000 + 5 ;
const int N = 35000 + 5 ; 
const int K = 50 + 5 ;
int n, m, col[N], bef[N], Ed[N], dp[N][K] ;
struct Tree {
    int mx, tag ;
} tr[N * 4] ;
void pushmark( int x ) {
    if( tr[x].tag ) {
        tr[ls(x)].mx += tr[x].tag, tr[rs(x)].mx += tr[x].tag,
        tr[ls(x)].tag += tr[x].tag, tr[rs(x)].tag += tr[x].tag,
        tr[x].tag = 0 ;
    }
}
void build( int x, int l, int r, int k ) {
    if( l == r ) { tr[x].mx = dp[l - 1][k]; return ; }
    int mid = ( l + r ) >> 1 ;
    build( ls(x), l, mid, k ), build( rs(x), mid + 1, r, k ) ; 
    tr[x].tag = 0, tr[x].mx = max( tr[ls(x)].mx, tr[rs(x)].mx ) ;
}
void Update( int x, int l, int r, int ql, int qr ) {
    if( l > qr || r < ql ) return ;
    if( ql <= l && r <= qr ) { ++ tr[x].tag, ++ tr[x].mx ; return ; } 
    int mid = ( l + r ) >> 1 ; pushmark(x) ;
    Update( ls(x), l, mid, ql, qr ), Update( rs(x), mid + 1, r, ql, qr ) ;
    tr[x].mx = max( tr[ls(x)].mx, tr[rs(x)].mx ) ;
}
int Query( int x, int l, int r, int ql, int qr ) {
    if( l > qr || r < ql ) return 0 ;
    if( ql <= l && r <= qr ) return tr[x].mx ; 
    int mid = ( l + r ) >> 1 ; pushmark(x) ;
    return max( Query( ls(x), l, mid, ql, qr ), Query( rs(x), mid + 1, r, ql, qr ) ) ; 
}
signed main() {
    n = gi(), m = gi() ; rep( i, 1, n ) col[i] = gi(), 
    bef[i] = Ed[col[i]], Ed[col[i]] = i ; 
    
	build( 1, 1, n, 0 ) ;
    rep( k, 1, m ) {
        rep( i, 1, n ) {
            Update( 1, 1, n, bef[i] + 1, i ) ;
            dp[i][k] = Query( 1, 1, n, 1, i ) ;
        } build( 1, 1, n, k ) ;
    }
    printf("%d\n", dp[n][m] ) ;
    return 0 ; 
}