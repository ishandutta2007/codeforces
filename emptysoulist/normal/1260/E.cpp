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
const int N = 4e5 + 5 ; 
const int inf = 123456789000 ; 
int n, m, t, a[N], Inv[30], dp[N][30], Ans ; 
signed main()
{
	n = gi() ; rep( i, 1, n ) {
		a[i] = gi() ; if( a[i] == -1 ) m = i, a[i] = 0 ; 
	} Inv[0] = n ; 
	if( m == n ) { puts("0") ; exit(0) ; }
	rep( i, 1, 19 ) Inv[i] = Inv[i - 1] / 2 ; 
	rep( i, 2, 19 ) Inv[i] = Inv[i] + Inv[i - 1] ;
	memset( dp, 63, sizeof(dp) ), dp[n][1] = a[n] ;  
	for( re int i = n - 1; i > m; -- i ) {
		for( re int j = 1; j <= 19; ++ j ) {
			dp[i][j] = min( dp[i + 1][j], dp[i + 1][j - 1] + a[i] ) ;
			if( Inv[j] < n - i + 1 ) dp[i][j] = inf ; 
		}
	} Ans = inf ; 
	rep( j, 1, 19 ) Ans = min( Ans, dp[m + 1][j] ) ;
	printf("%lld\n", Ans ) ;
	return 0 ;
}