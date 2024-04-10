#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 300 + 5 ; 
int n, m, a[N], num[N], g[N][N], dp[N][N], C[N][N] ; 
void inc( int &x, int y ) {
	x += y, x %= P ; 
}
signed main()
{
	n = gi() ; int x, sum = 0 ;
	rep( i, 1, n ) {
		x = gi() ; int type = 0 ;
		rep( j, 1, m ) {
			int u = a[j] * x, v = sqrt(u) ; 
			if( 1ll * v * v == u ) { ++ num[j], type = 1 ; break ; }
		}
		if( !type ) a[++ m] = x, num[m] = 1 ; 
	}  g[0][0] = dp[0][0] = 1 ; 
	rep( i, 0, n ) rep( j, 0, i ) C[i][j] = ( j == 0 ) ? 1 : ( C[i - 1][j - 1] + C[i - 1][j] ) % P ; 
	rep( i, 1, n ) rep( j, 1, i ) 
	g[i][j] = ( g[i - 1][j] * ( i + j - 1 ) % P + ( j * g[i - 1][j - 1] ) % P ) % P ; 
	rep( i, 1, m ) {
		rep( j, 0, sum ) rep( k, 1, num[i] ) rep( l, 0, j )
		inc( dp[i][j + (num[i] - k) - l], ( ( ( dp[i - 1][j] * g[num[i]][k] ) % P * C[j][l] ) % P * C[sum + 1 - j][k - l] ) % P ) ;
		sum += num[i] ; 
	}
	printf("%lld\n", dp[m][0] ) ;
	return 0 ;
}