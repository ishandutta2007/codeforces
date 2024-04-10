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
const int inf = 1e18 ; 
const int N = 1e6 + 5 ; 
int n, r1, r2, r3, d, a[N], f[N], mi[N], S[N], g[N] ; 
signed main()
{
	n = gi(), r1 = gi(), r2 = gi(), r3 = gi(), d = gi() ; 
	rep( i, 1, n ) a[i] = gi(), mi[i] = min( a[i] * r1 + min( r1 * 2, r3 ), r2 + r1 ) ; 
	rep( i, 1, n ) S[i] = S[i - 1] + mi[i] ; 
	memset( g, 63, sizeof(g) ) ; 
	memset( f, 63, sizeof(f) ) ;  
	g[0] = -d, f[0] = -d ; 
	for(re int i = 1; i <= n; ++ i ) {
		if( i > 1 ) f[i] = g[i - 2] + (i - 1) * 3 * d + S[i] ;
		f[i] = min( f[i], f[i - 1] + a[i] * r1 + r3 ), f[i] += d ; 
		g[i] = min( g[i - 1], f[i] - S[i] - i * 3 * d ) ; 
	}
	int tk = a[n] * r1 + r3 ; 
	for(re int i = 0; i < n; ++ i ) {
		if( i < n - 1 ) 
		f[n] = min( f[n], f[i] + d + S[n - 1] - S[i] + (n - i - 1) * 2 * d + tk ) ;
	}
	cout << f[n] << endl ; 
	return 0 ;
}