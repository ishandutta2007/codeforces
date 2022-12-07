#include<bits/stdc++.h>

using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i ) 
#define re register
#define int long long
int gi() {
    int cn = 0 ; char cc = getchar() ;
    while( cc > '9' || cc < '0' ) cc = getchar() ;
    while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
    return cn ; 
}
const int P = 1e9 + 7 ;
const int N = 250 + 5 ; 
int n, m, C[N][N], dp[N][N], inv[N], fac[N] ;
signed main(){
    n = gi(), m = gi() ; C[0][0] = 1, fac[0] = inv[0] = 1 ;
    rep( i, 1, n ) {
          C[i][0] = 1, inv[i] = ( inv[i - 1] * m ) % P, fac[i] = ( fac[i - 1] * ( m - 1 ) ) % P ; 
          rep( j, 1, n ) C[i][j] = ( C[i - 1][j] + C[i - 1][j - 1] ) % P;
    }
    dp[0][0] = 1 ;
    rep( i, 1, n ) {
        rep( j, 1, n ) {
            dp[i][j] = dp[i - 1][j] * fac[n - j] % P * ( inv[j] - fac[j] + P ) % P ; 
            rep( k, 0, j - 1 ) {
                dp[i][j] = ( dp[i][j] + dp[i - 1][k] * ( C[n - k][j - k] ) % P * 
                inv[k] % P * fac[n - j] % P ) % P ;
            //    printf("%d %d %d %d (%d %d)\n", i, j, dp[i][j], dp[i - 1][k], i - 1, k ) ;
            }
            //printf("End: %d (%d %d)\n", dp[i][j], i, j ) ;
        }
    }
    printf("%I64d\n", dp[n][n] % P ) ;
    return 0 ;
}