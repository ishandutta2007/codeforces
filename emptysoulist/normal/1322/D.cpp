#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
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
const int N = 4000 + 5 ; 
const int M = 2200 ; 
const int inf = 1e8 + 7 ; 
int n, m, a[N], s[N], c[N], dp[N][M], f[N], Dp[N] ; 
signed main()
{
    n = gi(), m = gi() ; 
    rep( i, 1, n ) a[i] = gi() ; 
    rep( i, 1, n ) s[i] = gi() ; 
    rep( i, 1, n + m ) c[i] = gi() ; 
    m += 50 ; 
    rep( i, 1, m ) rep( j, 1, n ) dp[i][j] = -inf ;
    for( re int i = n; i >= 1; -- i ) {
        for( re int k = n; k >= 1; -- k )
            dp[a[i]][k] = max( dp[a[i]][k], dp[a[i]][k - 1] - s[i] ) ;
        rep( j, 0, n ) Dp[j] = dp[a[i]][j] ;
        int l = n ; 
        for( re int o = 1; o <= n; ++ o ) {
            rep( j, 0, l ) f[j] = Dp[j] + j * c[a[i] + o - 1], Dp[j] = - inf ; 
            rep( j, 0, l ) Dp[j / 2] = max( Dp[j / 2], f[j] ) ; 
            l /= 2 ; 
            rep( j, 0, l ) dp[a[i] + o][j] = max( dp[a[i] + o][j], Dp[j] ) ; 
        }
    }
    int Ans = 0 ; 
    for( re int i = 1; i <= m; ++ i ) {
        Ans = max( Ans, dp[i][0] ) ;
        rep( j, 0, n ) dp[i + 1][j / 2] = max( dp[i + 1][j / 2], dp[i][j] + c[i] * j ) ; 
    }
    printf("%lld\n", Ans ) ;
	return 0 ;
}