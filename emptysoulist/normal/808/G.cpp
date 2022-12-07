#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
char s[N], t[N] ;
int n, m, dp[2][N], kmp[N], Go[N][30], Ans ; 
signed main()
{
	scanf("%s", s + 1 ), n = strlen( s + 1 ), 
	scanf("%s", t + 1 ), m = strlen( t + 1 ) ;
	if( m > n ) { puts("0") ; exit(0) ; }
	int L = 0 ; kmp[1] = 0 ;
	for( re int i = 2; i <= m; ++ i ) {
		while( L != 0 && t[L + 1] != t[i] ) L = kmp[L] ;
		if( t[L + 1] == t[i] ) ++ L ; kmp[i] = L ;
	}
	rep( i, 0, m ) dp[0][i] = dp[1][i] = -n ;
	dp[0][0] = 0 ; 
	for( re int j = 'a'; j <= 'z'; ++ j )
		rep( i, 0, m ) {
			int u = i ; while( u != 0 && t[u + 1] != j ) u = kmp[u] ;
			if( t[u + 1] == j ) ++ u ; Go[i][j - 'a'] = u ; 
		}
	for( re int i = 1; i <= n; ++ i ) {
		rep( j, 0, m ) dp[i & 1][j] = -n ; 
		if( s[i] != '?' ) rep( j, 0, m ) {
			int u = Go[j][s[i] - 'a'] ;
			dp[i & 1][u] = max( dp[i & 1][u], dp[(i - 1) & 1][j] + ( u == m ) ) ;
		}
		else {
			rep( k, 0, 25 ) rep( j, 0, m ) {
				int u = Go[j][k] ; 
				dp[i & 1][u] = max( dp[i & 1][u], dp[(i - 1) & 1][j] + ( u == m ) ) ;
			}
		}	
	}
	for( re int j = 0; j <= m; ++ j ) Ans = max( Ans, dp[n & 1][j] ) ;
	printf("%d\n", Ans ) ;
	return 0 ;
}