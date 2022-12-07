#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define D long double
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
int n, c[N], m ;
D ans, t, f[N][10005] ; 
D Min(D x, D y) { return min(x, y) ; }
signed main()
{
	n = gi(), t = gi(), t /= 2.0 ; 
	rep( i, 1, n ) c[i] = gi(), m += c[i] ; f[0][0] = 1 ; 
	rep( i, 1, n ) drep( k, 1, i ) rep( j, c[i], m ) 
	f[k][j] = (f[k][j] + f[k - 1][j - c[i]] * k / (1.0 * (n - k + 1)) ) ;
	rep( k, 1, n ) rep( j, 0, m ) 
		ans = (ans + f[k][j] * Min( ((D)n / (D)k + 1) * t, (D)j / ((D)k)) ) ; 
	printf("%.10Lf\n", ans ) ; 
	return 0 ;
}