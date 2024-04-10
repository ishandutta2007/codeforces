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
const int P = 998244353 ; 
const int N = 2000 + 5 ; 
char s[N] ; 
int n, dp[N][N], sum[N], a[N] ;
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ;
	} return ans % P ; 
}
void inc( int &x, int y ) {
	( ( x += y ) > P ) && ( x -= P ) ;
}
void dec( int &x, int y ) {
	( ( x -= y ) < 0 ) && ( x += P ) ;
}
signed main()
{
	scanf("%s", s + 1 ), n = strlen( s + 1 ) ;
	rep( i, 1, n ) a[i] = ( s[i] == '(' ? 1 : ( s[i] == ')' ? -1 : 0 ) ), sum[i] = sum[i - 1] + ( a[i] == 0 ) ;
	memset( dp, 0, sizeof(dp) ) ;
	for( re int k = 2; k <= n; ++ k ) {
		for( re int i = 1; i <= n - k + 1; ++ i ) { 
			int j = i + k - 1 ;
			if( s[i] != '(' ) inc( dp[i][j], dp[i + 1][j] ) ; //
			if( s[j] != ')' ) inc( dp[i][j], dp[i][j - 1] ) ;
			if( s[i] != '(' && s[j] != ')' ) dec( dp[i][j], dp[i + 1][j - 1] ) ; //
			if( s[i] != ')' && s[j] != '(' ) inc( dp[i][j], ( fpow( 2, sum[j - 1] - sum[i] ) + dp[i + 1][j - 1] ) % P ) ; 
		}
	}
	printf("%lld\n", dp[1][n] ) ;
	return 0 ;
}