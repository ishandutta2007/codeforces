#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const int P = 998244353 ; 
const int inv = 499122177 ;
const int M = 100 + 5 ; 
int n, m, K, tot, A, a[N], p[M], w[M], st[M], ans[M], vis[M], c[M][M], d[M][M], Ans = 1 ;
int lowbit( int x ) {
    return __builtin_popcountll(x) ;
}
void dfs( int x, int S ) {
    if( x == K + 1 ) { ++ ans[lowbit(S)] ; return ; }
    dfs( x + 1, S ), dfs( x + 1, S ^ st[x] ) ;
}
void dfs2( int x, int S ) {
    if( x == K + 1 ) { ++ w[lowbit(S)] ; return ; }
    dfs2( x + 1, S ), dfs2( x + 1, S ^ st[x] ) ;
}
signed main()
{
    n = gi(), m = gi() - 1 ; int x ;
    rep( i, 1, n ) {
        x = gi() ; 
        drep( j, 0, m )
            if( x & ( 1ll << j ) ) ( p[j] != 0 ) ? ( x ^= p[j] ) : ( p[j] = x, x = 0 ) ; 
    }
    drep( i, 0, m ) drep( j, 0, m )
        if( ( p[j] & ( 1ll << i ) ) && ( i != j ) ) p[j] ^= p[i] ; 
    drep( i, 0, m ) if(p[i]) st[++ K] = p[i], vis[i] = 1 ;
    rep( i, 1, n - K ) Ans = Ans * 2 % P ; 
    ++ m ;
    if( K <= 26 ) dfs( 1, 0 ) ;
    else {
        int Inv = 1 ; rep( i, 1, m - K ) Inv = Inv * inv % P ; tot = K, K = 0 ;
        drep( i, 0, m - 1 ) {
            if( vis[i] ) continue ; int k = ( 1ll << i ) ;
            rep( j, i + 1, m ) if( ( p[j] & k ) ) k = ( k | ( 1ll << j ) ) ;
            st[++ K] = k ; 
        } c[0][0] = 1 ; 
        rep( i, 1, m ) rep( j, 0, m ) ( j == 0 ) ? c[i][j] = 1 : c[i][j] = ( c[i - 1][j] + c[i - 1][j - 1] ) % P ; 
        dfs2( 1, 0 ) ;
        rep( i, 0, m ) rep( j, 0, m ) rep( k, 0, i ) {
            int t = c[j][k] * c[m - j][i - k] % P ;
            ( k & 1 ) ? d[i][j] = ( d[i][j] + P - t ) % P : d[i][j] = ( d[i][j] + t ) % P ; 
        }
        rep( j, 0, m ) rep( i, 0, m ) ans[i] = ( ans[i] + d[i][j] * w[j] % P ) % P ;
        rep( i, 0, m ) ans[i] = ans[i] * Inv % P ; 
    }
    rep( i, 0, m ) printf("%I64d ", ans[i] * Ans % P ) ; 
	return 0 ; 
}