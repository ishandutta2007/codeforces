#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3000 + 5 ; 
const int P = 998244353 ; 
int m, n, dp[N][N] ; 
char s[N], t[N], a[N] ; 
signed main()
{
	scanf("%s", s + 1 ), n = strlen( s + 1 ) ;
    scanf("%s", t + 1 ), m = strlen( t + 1 ) ;
    rep( i, 1, n ) if( s[1] == t[i] || i > m ) dp[i][i] = 2 ;
    for( re int i = 2; i <= n; ++ i ) {
        for( re int l = 1, r = i; r <= n; ++ l, ++ r ) {
            if( ( l > m ) || ( s[i] == t[l] ) ) dp[l][r] = (dp[l][r] + dp[l + 1][r]) % P ;
            if( ( r > m ) || ( s[i] == t[r] ) ) dp[l][r] = ( dp[l][r] + dp[l][r - 1] ) % P ;
        }
    }
    int Ans = 0 ;
    rep( j, m, n ) Ans = ( Ans + dp[1][j] ) % P ;
    cout << Ans << endl ; 
	return 0 ; 
}