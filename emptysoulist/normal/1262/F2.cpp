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
const int P = 998244353 ;
const int Gi = 332748118 ;
const int G = 3 ; 
const int N = 4e5 + 5 ; 
const int M = 8e5 + 5 ; 
int n, m, Ans, T, t, h[N], fac[N], inv[N] ; 
int A[M], R[M], L, Inv, limit ; 
int fpow( int x, int k ) {
	int ans = 1, base = x % P ;
	while( k ) {
		if( k & 1 ) ans = ( ans * base ) % P ;
		base = ( base * base ) % P, k >>= 1 ;
	} return ans ; 
}
void init( int x ) {
	limit = 1, L = 0 ;
	while( limit < x ) limit <<= 1, ++ L ; 
	rep( i, 0, limit ) R[i] = ( R[i >> 1] >> 1 ) | ( ( i & 1 ) << ( L - 1 ) ) ;
	Inv = fpow( limit, P - 2 ) ;
}
inline void NTT( int *a, int type ) {
	for( re int i = 0; i < limit; ++ i ) if( R[i] > i ) swap( a[i], a[R[i]] ) ; 
	for( re int k = 1; k < limit; k <<= 1 ) {
		int d = fpow( ( type == 1 ) ? G : Gi, ( P - 1 ) / ( k << 1 ) ) ;
		for( re int i = 0; i < limit; i += ( k << 1 ) )
		for( re int j = i, g = 1 ; j < i + k; ++ j, g = ( g * d ) % P ) {
			int Nx = a[j], Ny = ( a[j + k] * g ) % P ; 
			a[j] = ( Nx + Ny ) % P, a[j + k] = ( Nx - Ny + P ) % P ; 
		}
	} 
	if( type != 1 ) for( re int i = 0; i < limit; ++ i ) a[i] = a[i] * Inv % P ; 
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) h[i] = gi() ; 
	rep( i, 1, n ) {
		if( h[i] == h[i % n + 1] ) ++ T ; 
		else ++ t ; 
	} inv[0] = fac[0] = 1 ;
	rep( i, 1, t ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ;
	if( m == 1 ) { puts("0") ; exit(0) ; }
	rep( i, 0, t ) A[i] = inv[i] ; 
	init( t + t + 1 ), NTT( A, 1 ) ;
	rep( i, 0, limit ) A[i] = A[i] * A[i] % P ; 
	NTT( A, -1 ) ; int Iv = fpow( 2, P - 2 ) ;
	rep( i, 0, limit ) if( i % 2 == 0 ) A[i] = ( A[i] - inv[i / 2] * inv[i / 2] % P + P ) % P ; 
	rep( i, 0, limit ) A[i] = A[i] * Iv % P ; 
	for( re int i = 1; i <= t; ++ i ) {
		int k = fpow( m - 2, t - i ) * inv[t - i] % P ; 
		Ans = ( Ans + k * A[i] % P ) % P ; 
	}
	printf("%I64d\n", Ans * fpow( m, T ) % P * fac[t] % P ) ;
	return 0 ;
}