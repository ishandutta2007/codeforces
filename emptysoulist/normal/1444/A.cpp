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
const int N = 100 + 5 ; 
int T, top, w[N], c[N] ; 
int gcd(int x, int y) {
	return (!x) ? y : gcd(y % x, x) ;
}
signed main()
{
	T = gi() ; 
	while( T-- ) {
		int p = gi(), q = gi() ; 
		int g = gcd(p, q), d = q ; 
		top = 0 ; 
		for( re int i = 2; i <= sqrt(q); ++ i) {
			if( q % i ) continue ; 
			w[++ top] = i ;
			while( q % i == 0 ) q /= i, ++ c[top] ; 
		}
		if( q != 1 ) w[++ top] = q, ++ c[top] ; 
		int ans = 1 ; 
		for(re int i = 1; i <= top; ++ i) {
			int x = p, z = 0, lim = c[i] - 1 ; 
			while( x % w[i] == 0 ) x /= w[i], ++ z ;
			lim = min( lim, z ) ;
			rep( j, 1, lim ) x = x * w[i] ; 
			ans = max( ans, x ) ;
		}
		rep( i, 1, top ) c[i] = w[i] = 0 ; 
		cout << ans << endl ; 
	}
	return 0 ;
}