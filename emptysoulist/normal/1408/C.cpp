#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define double long double
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, a[N] ; 
double L[N], R[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), m = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		
		L[0] = 0, R[n + 1] = 0 ; 
		a[n + 1] = m ; 
		rep( i, 1, n + 1 ) L[i] = L[i - 1] + (1.0 * (a[i] - a[i - 1])) / (1.0 * i) ;
		drep( i, 0, n ) R[i] = R[i + 1] + (1.0 * (a[i + 1] - a[i])) / (1.0 * (n - i + 1)) ;
		double ans = m ; 
		for(re int i = 0; i <= n; ++ i) {
			double ll = i + 1, rr = n - i + 1 ; 
			double lt = L[i], rt = R[i + 1] ; 
			if( lt > rt ) {
				double dt = lt - rt ; 
				double s = rr * dt ; 
				double len = a[i + 1] - a[i] ;
				len -= s ; 
				if( len > 0 ) ans = min( ans, lt + len / (ll + rr) ) ;
				else ans = min( ans, lt ) ; 
			}
			else {
				double dt = rt - lt ; 
				double s = ll * dt ; 
				double len = a[i + 1] - a[i] ;
				len -= s ; 
				if( len > 0 ) ans = min( ans, rt + len / (ll + rr) ) ;
				else ans = min( ans, rt ) ; 
			}
		}
		printf("%.10Lf\n", ans ) ; 
	}
	return 0 ;
}