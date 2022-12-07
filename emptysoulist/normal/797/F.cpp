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
const int inf = 1234567890000 ;
const int N = 5000 + 10 ; 
int n, m, X[N], dp[N][N], Sum[N], q[N], he, ta ;
struct P {
	int p, c ; 	
} p[N] ;
bool cmp( P x, P y ) {
	return x.p < y.p ; 
}
signed main()
{
	n = gi(), m = gi() ; int ubt = 0 ;
	rep( i, 1, n ) X[i] = gi() ;
	rep( i, 1, m ) p[i].p = gi(), p[i].c = gi(), ubt += p[i].c ;
	if( ubt < n ) { puts("-1") ; exit(0) ; }
	sort( p + 1, p + m + 1, cmp ) ;
	sort( X + 1, X + n + 1 ) ;
	memset( dp, 63, sizeof(dp) ) ;
	dp[0][0] = 0 ;
	rep( i, 1, m ) {
		he = 1, ta = 1, q[he] = 0, dp[i][0] = 0 ;
		memset( Sum, 0, sizeof(Sum) ) ;
		rep( j, 1, n ) Sum[j] = Sum[j - 1] + abs( X[j] - p[i].p ) ;
		rep( j, 1, n ) {
			while( he <= ta && dp[i - 1][q[ta]] - Sum[q[ta]] >= dp[i - 1][j] - Sum[j] ) -- ta ; 
			q[++ ta] = j ;
			while( he <= ta && ( j - q[he] ) > p[i].c ) ++ he ;
			if( he > ta ) dp[i][j] = inf ;
			else dp[i][j] = dp[i - 1][q[he]] - Sum[q[he]] + Sum[j] ;
		}
	}
	printf("%I64d\n", dp[m][n] ) ;
	return 0 ;
}