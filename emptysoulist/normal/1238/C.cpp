#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, H, a[N], dp[N] ; 
int solve() {
	int ans = 0, r = 1 ; 
	for( re int i = 2; i <= n; ++ i ) {
		if( a[i - 1] != a[i - 2] + 1 ) dp[i] = dp[i - 1] + 1 ;
		else dp[i] = dp[i - 2] ;  
	}
	return dp[n] ; 
}
signed main()
{
	int T = gi() ;  
	while( T-- ) {
		H = gi(), n = gi() ; 
		rep( i, 1, n ) a[n - i + 1] = gi() ; 
		printf("%d\n", solve() ) ;
	}
	return 0 ;
}