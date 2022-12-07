#include<bits/stdc++.h>
using namespace std ;
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
const int P = 998244353 ; 
const int Gi = 332748118 ;
const int G = 3 ; 
const int N = 8e5 + 5 ; 
int n, m, t, c[N], A[N] ; 
int limit, L, R[N], Inv ; 
int fpow( int x, int k ) { 
	int ans = 1, base = x % P ; 
	while( k ) { 
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
} 
void NTT( int *a, int type ) { 
	for( re int i = 0; i < limit; ++ i ) if( R[i] > i ) swap( a[i], a[R[i]] ) ; 
	for( re int k = 1; k < limit; k <<= 1 ) { 
		int d = fpow( ( type == 1 ) ? G : Gi, ( P - 1 ) / ( k << 1 ) ) ; 
		for( re int i = 0; i < limit; i += ( k << 1 ) ) 
		for( re int j = i, g = 1; j < i + k; ++ j, g = g * d % P ) { 
			int Nx = a[j], Ny = a[j + k] * g % P ; 
			a[j] = ( Nx + Ny ) % P, a[j + k] = ( Nx - Ny + P ) % P ; 
		} 
	} 
	if( type != 1 ) for( re int i = 0; i < limit; ++ i ) a[i] = a[i] * Inv % P ; 
} 
void init( int x ) { 
	limit = 1, L = 0 ; while( limit < x ) limit <<= 1, ++ L ; 
	rep( i, 0, limit ) R[i] = ( R[i >> 1] >> 1 ) | ( ( i & 1 ) << ( L - 1 ) ) ; 
	Inv = fpow( limit, P - 2 ) ; 
}
int H[N], F[N] ; 
void InvF( int *a, int x ) {
	memset( H, 0, sizeof(H) ), memset( F, 0, sizeof(F) ) ;
	H[0] = fpow( a[0], P - 2 ) ; int len = 1 ; limit = 1, L = 0 ;
	while( len < x ) {
		len <<= 1, init( len + len ) ;
		rep( i, 0, len - 1 ) F[i] = a[i] ; 
		NTT( F, 1 ), NTT( H, 1 ) ;
		rep( i, 0, limit ) H[i] = ( 2ll - F[i] * H[i] % P + P ) * H[i] % P ; 
		NTT( H, -1 ) ; rep( i, len, limit ) H[i] = 0 ; 
	}
}
int B[N], Gx[N] ;
void Sqrt( int *a, int x ) {
	B[0] = 1 ; int k = 1, I2 = fpow( 2, P - 2 ) ;
	while( k < x ) {
		k <<= 1 ; InvF( B, k ) ;
		rep( i, 0, k - 1 ) Gx[i] = a[i] ; 
		init( k + k ), NTT( Gx, 1 ), NTT( H, 1 ), NTT( B, 1 ) ;
		rep( i, 0, limit ) B[i] = I2 * ( B[i] % P + Gx[i] * H[i] % P ) % P ;
		NTT( B, -1 ) ; rep( i, k, limit ) B[i] = 0 ;
	}
}
signed main() 
{ 
	n = gi(), m = gi(), t = m + 1 ; 
	rep( i, 1, n ) c[i] = gi(), A[c[i]] = 1 ; 
	rep( i, 0, m ) A[i] = ( -4 * A[i] + P ) % P ;
	A[0] += 1, Sqrt( A, m + 1 ) ; B[0] += 1 ; 
	InvF( B, m + m + 1 ) ; 
	rep( i, 1, m ) printf("%lld\n", 2ll * H[i] % P ) ; 
	return 0 ;
}