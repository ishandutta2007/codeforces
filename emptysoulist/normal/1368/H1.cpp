#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ;
int n, m, Ans, q, ll, rr, dd, uu, L[N], R[N], D[N], U[N], dp[N][2] ; 
char s[N] ; 
signed main()
{
	n = gi(), m = gi(), q = gi() ; Ans = n + m ; 
	scanf("%s", s + 1 ) ;
	rep( i, 1, n ) if(s[i] == 'R') L[i] = 1, ++ ll ;
	scanf("%s", s + 1 ) ;
	rep( i, 1, n ) if(s[i] == 'R') R[i] = 1, ++ rr ;
	scanf("%s", s + 1 ) ;
	rep( i, 1, m ) if(s[i] == 'R') U[i] = 1, ++ uu ;
	scanf("%s", s + 1 ) ;
	rep( i, 1, m ) if(s[i] == 'R') D[i] = 1, ++ dd ;
	dp[0][1] = n - ll,
	dp[0][0] = ll ; 
	rep( i, 1, m ) {
		dp[i][0] = min(dp[i - 1][1] + n, dp[i - 1][0]) + U[i] + D[i] ;
		dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + n) + (U[i] ^ 1) + (D[i] ^ 1) ;
	}
	dp[m][0] += rr, Ans = min( Ans, dp[m][0] ) ;
	dp[m][1] += (n - rr), Ans = min( Ans, dp[m][1] ) ; 
	memset( dp, 0, sizeof(dp) ) ;
	dp[0][1] = m - uu ;
	dp[0][0] = uu ;
	rep( i, 1, n ) {
		dp[i][0] = min(dp[i - 1][1] + m, dp[i - 1][0]) + L[i] + R[i] ;
		dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + m) + (L[i] ^ 1) + (R[i] ^ 1) ;
	}
	dp[n][0] += dd, Ans = min( Ans, dp[n][0] ) ;
	dp[n][1] += (m - dd), Ans = min( Ans, dp[n][1] ) ; 
	cout << Ans << endl ; 
	return 0 ;
}