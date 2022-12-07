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
const int inf = 12345678900000 ;
const int N = 5e5 + 5 ; 
int a[N], D[N], n, m, k, Mi[N], Ans ; 
signed main() {
	n = gi(), m = gi(), k = gi() ;
	rep( i, 1, n ) a[i] = gi(), a[i] = a[i - 1] + a[i], D[i] = a[i] - k * ( i / m ) ;
	for( re int i = 0; i <= n; ++ i ) Mi[i] = inf ;
	D[0] = 0 ; 
	for( re int i = 1; i < m; ++ i ) {
		for( re int j = i - 1; j <= n; j += m ) { //Mi
			Mi[j] = D[j] ; if( j ) Mi[j] = min( Mi[j], Mi[j - 1] ) ;
			if( j >= m ) Mi[j] = min( Mi[j], Mi[j - m] ) ;
		}
		for( re int j = i; j <= n; j += m )
		Ans = max( Ans, D[j] - Mi[j - 1] - k ) ;
	}
	for( re int i = 0; i <= n; ++ i ) Mi[i] = inf ;
	for( re int i = m - 1; i >= 0; -- i ) {
		for( re int j = i; j <= n; j += m ) {
			Mi[j] = D[j] ; 
			if( j - i > 0 ) Mi[j] = min( Mi[j], Mi[j - i - 1] ) ;
			Ans = max( Ans, D[j] - Mi[j] ) ;
			if( j - i >= 0 ) Mi[j - i + m - 1] = min( Mi[j - i + m - 1], Mi[j] ) ;
		}
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}