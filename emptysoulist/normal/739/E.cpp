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
const int N = 2000 + 5 ;
const double eps = 1e-6 ;
int n, A, B ;  
double p[N], q[N] ;
struct node {
	double w, k ;
	bool operator < ( const node& x ) const {
		return ( w == x.w ) ? k > x.k : w < x.w ;
	}
} dp[N][N] ; 
int check( double x ) {
	memset( dp, 0, sizeof(dp) ) ;
	for( re int i = 1; i <= n; ++ i ) {
		for( re int j = 0; j <= A; ++ j ) {
			dp[i][j].w = dp[i - 1][j].w, dp[i][j].k = dp[i - 1][j].k ;
		//	printf("%d %d %lf\n", i, j, dp[i][j].w ) ;
			if( j ) dp[i][j] = max( dp[i][j], (node){ dp[i - 1][j - 1].w + p[i], dp[i - 1][j - 1].k } ) ;
			if( j ) dp[i][j] = max( dp[i][j], (node){ dp[i - 1][j - 1].w + p[i] + q[i] - p[i] * q[i] + x, dp[i - 1][j - 1].k + 1 } ) ;
			
		//	printf("%d %d %lf\n", i, j, dp[i][j].w ) ;
			dp[i][j] = max( dp[i][j], (node){ dp[i - 1][j].w + x + q[i], dp[i - 1][j].k + 1 } ) ;
			
		//	printf("%d %d %lf\n", i, j, dp[i][j].w ) ;
		}
	}
//	printf("%lf %lf %d\n", x, dp[n][A].w - dp[n][A].k * B, (int)dp[n][A].k ) ;
	return (int)dp[n][A].k ;
}
signed main()
{
	n = gi(), A = gi(), B = gi() ; 
	rep( i, 1, n ) scanf("%lf", &p[i] ) ;
	rep( i, 1, n ) scanf("%lf", &q[i] ) ;
	double l = -2.0, r = +2.0, ans = 0 ;
	while( l < r - eps ) {
		double mid = ( l + r ) / 2.0 ;
		if( check(mid) <= B ) l = mid, ans = dp[n][A].w - B * mid ;
		else r = mid ; 
	}
	printf("%.8lf\n", ans ) ;
	return 0 ;
}