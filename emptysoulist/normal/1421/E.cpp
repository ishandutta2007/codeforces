#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, a[N], dp[N][4][2][2] ; 
void cx(int &x, int y) { x = max(x, y) ; }
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	if( n == 1 ) { cout << a[1] << endl ; exit(0) ; }
	memset( dp, -63, sizeof(dp) ) ;
	dp[1][1][1][0] = a[1] ; 
	dp[1][2][0][0] = -a[1] ; 
	rep( i, 2, n ) {
		rep( j, 0, 2 ) rep( k, 0, 1 ) rep( l, 0, 1 ) {
			cx( dp[i][(j + 1) % 3][1][l | (k == 1)], dp[i - 1][j][k][l] + a[i] ) ; 
			cx( dp[i][(j + 2) % 3][0][l | (k == 0)], dp[i - 1][j][k][l] - a[i] ) ; 
		}
	}
	cout << max( dp[n][1][0][1], dp[n][1][1][1] ) << endl ; 
	return 0 ;
}