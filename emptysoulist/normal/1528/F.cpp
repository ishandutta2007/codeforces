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
const int P = 998244353 ;
const int Gi = (P + 1) / 3 ;
const int G = 3 ; 
const int N = 8e5 + 5 ; 
int n, m, limit, L, R[N], f[N], g[N], fac[N], Inv ; 
int fpow( int x, int k ) {
	int ans = 1, base = x % P ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ;
	} return ans % P ; 
} 
void init( int x ) {
	limit = 1, L = 0 ; while( limit <= x ) limit <<= 1, ++ L ;
	rep( i, 0, limit ) R[i] = ( R[i >> 1] >> 1 ) | ( ( i & 1 ) << ( L - 1 ) ) ; 
	Inv = fpow( limit, P - 2 ) ;
}
void NTT( int *a, int type ) {
	rep( i, 0, limit - 1 ) if( i < R[i] ) swap( a[i], a[R[i]] ) ;
	for( re int k = 1; k < limit; k <<= 1 ) {
		int d = fpow( ( type == 1 ) ? G : Gi, ( P - 1 ) / ( k << 1 ) ) ; 
		for( re int i = 0; i < limit; i += ( k << 1 ) )
		for( re int j = i, g = 1; j < i + k; g = ( g * d ) % P, ++ j ) {
			int Nx = a[j], Ny = ( a[j + k] * g ) % P ;
			a[j] = ( Nx + Ny ) % P, a[j + k] = ( Nx - Ny + P ) % P ; 
		}
	}
	if( type != 1 ) rep( i, 0, limit - 1 ) a[i] = ( a[i] * Inv ) % P ; 
}
int ud[N] ; 
signed main()
{
	m = gi(), n = gi(), fac[0] = 1 ; rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ;
	rep( i, 0, n ) g[i] = fpow( i, n ) * fpow( fac[i], P - 2 ) % P ;
	rep( i, 0, n ) f[i] = ( i & 1 ) ? ( P - fpow( fac[i], P - 2 ) ) : fpow( fac[i], P - 2 ) ;
	init( n + n ), NTT( f, 1 ), NTT( g, 1 ) ;
	rep( i, 0, limit ) f[i] = f[i] * g[i] % P ; NTT( f, 0 ) ;
	ud[0] = 1 ; int ans = 0 ; 
	rep( i, 1, min(n, m) ) ud[i] = ud[i - 1] * (m - i + 1) % P ; 
	rep( i, 0, min(n, m) ) ans = (ans + f[i] * ud[i] % P * fpow(m + 1, m - i) % P) % P ; 
	cout << ans << endl ; 
	return 0 ;
}