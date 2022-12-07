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
const int N = 1000 + 5 ; 
const int M = 10 + 5 ;
const int P = 1e9 + 7 ; 
int n, m, dp[N][N], sum[N][M], Ans ;
signed main()
{
	n = gi(), m = gi() ; sum[0][0] = 1 ; // [i][a][b]
	rep( i, 1, n ) dp[1][i] = 1 ;
	rep( i, 2, m ) rep( j, 1, n )
	rep( k, 1, j ) dp[i][j] = ( dp[i][j] + dp[i - 1][k] ) % P ;
	rep( i, 1, n ) rep( j, i, n )
	Ans = ( Ans + dp[m][i] * dp[m][n - j + 1] % P ) % P ;
	printf("%I64d\n", Ans % P ) ;
	return 0 ;
}