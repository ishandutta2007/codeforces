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
int T, a, b, c, d ; 
int get(int x) {
	return (x + 1) * a - x * (x + 1) / 2 * b * d ; 
}
signed main()
{
	T = gi() ; 
	while( T-- ) {
		a = gi(), b = gi(), c = gi(), d = gi() ; 
		if( a > b * c ) puts("-1") ; 
		else {
			if( d >= c ) {
				printf("%lld\n", a ) ; 
			}
			else {
				long double aa = b * d ;
				long double bb = a - 0.5 * b * d ; 
				long double cc = a ; 
				long double delta = bb * bb - 4 * aa * cc ;
				if( delta < 0 ) delta = 0 ; 
				delta = sqrt(delta) ;
				bb += delta ;
				bb /= aa ; 
				int t = (int)bb ; t /= 2 ; 
				int l = max( 0ll, t - 100 ) ;
				int r = t + 100, ans = 0 ; 
				int ip = 0 ;
				for(re int i = l; i <= r; ++ i) {
					ans = max( ans, get(i) ), ip = i ;
				}
				printf("%lld\n", ans ) ; 
			}
		}
	}
	return 0 ;
}