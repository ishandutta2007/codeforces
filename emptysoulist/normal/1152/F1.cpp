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
const int N = 1e5 + 5 ; 
const int K = 15 ; 
const int M = 1 << 6 ; 
const int P = 1e9 + 7 ; 
int n, k, m, dp[3][K][M], Ans ; 
void inc( int &x, int y ) {
	( ( x += y ) >= P ) && ( x -= P ) ;
}
int sz( int x ) {
	int cnt = 0 ;
	if( x & 1 ) ++ cnt ;
	if( ( x >> 1 ) & 1 ) ++ cnt ;
	if( ( x >> 2 ) & 1 ) ++ cnt ;
	if( ( x >> 3 ) & 1 ) ++ cnt ;
	if( ( x >> 4 ) & 1 ) ++ cnt ;
	return cnt ;
}
signed main()
{
	n = gi(), k = gi(), m = gi() ; 
	dp[0][0][0] = 1 ; int maxn = ( 1 << ( m + 1 ) ) - 1 ; /// 
	int x = 1 << ( m ) ;
	for( re int i = 1; i <= n; ++ i ) {
		for( re int j = 0; j <= k; ++ j )
		for( re int r = 0; r <= maxn; ++ r ) dp[i & 1][j][r] = 0 ;
		for( re int j = 0; j <= k; ++ j ) {
			for( re int r = 0; r <= maxn; ++ r ) {
				inc( dp[i & 1][j][r >> 1], dp[(i - 1) & 1][j][r] ) ; 
				if( j != k ) inc( dp[i & 1][j + 1][x | (r >> 1)], sz(x | (r >> 1)) * dp[(i - 1) & 1][j][r] % P ) ;
			}
		}
	}
	rep( r, 0, maxn ) inc( Ans, dp[n & 1][k][r] ) ;
	cout << Ans % P << endl ; 
	return 0 ;
}