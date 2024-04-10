#include<bits/stdc++.h>
using namespace std ;
#define drep( i, s, t ) for( register int i = t; i >= s; -- i )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
const int P = 998244353 ;
const int Gi = 332748118 ;
const int G = 3 ; 
const int M = 15 ; 
int n, m, q[N], a[N], b[M], Ans[N], fac[N], Inv[N], vis[N], Mx ; 
int T, cnt, num, Tw[N], A[N << 1], B[N << 1], limit, R[N << 1], L, fInv ;
int fpow( int x, int k ) {
	int ans = 1, base = x % P ; 
	while( k ) {
		if( k & 1 ) ans = ( ans * base ) % P ; 
		base = ( base * base ) % P, k >>= 1 ; 
	} return ans ;
}
int C( int x, int y ) {
	if( y > x ) return 0 ;
	return ( ( 1ll * fac[x] * Inv[y] ) % P * Inv[x - y] ) % P ;
}
int Get( int x ) {
	int ans = 0 ;
	for( re int k = 0; k <= x; ++ k ) {
		int ru = ( Tw[k] * C( cnt, k ) ) % P * C( 2 * num, x - k ) % P ;
		ans = ( ans + ru ) % P ; 
	} return ( ans + P ) % P ; 
}
void Init( int x ) {
	limit = 1, L = 0 ; 
	while( limit <= x ) limit <<= 1, ++ L ; 
	rep( i, 0, limit - 1 ) R[i] = ( R[i >> 1] >> 1 ) | ( ( i & 1 ) << ( L - 1 ) ) ;
	fInv = fpow( limit, P - 2 ) ;
}
void NTT( int *a, int type ) {
	for( re int i = 0; i < limit; ++ i ) if( R[i] > i ) swap( a[i], a[R[i]] ) ;
	for( re int k = 1; k < limit; k <<= 1 ) {
		int d = fpow( ( type == 1 ) ? G : Gi, ( P - 1 ) / ( k << 1 ) ) ;
		for( re int i = 0; i < limit; i += ( k << 1 ) )
			for( re int j = i, g = 1; j < i + k; ++ j, g = ( g * d ) % P ) {
				int Nx = a[j], Ny = a[j + k] * g % P ;
				a[j] = ( Nx + Ny ) % P, a[j + k] = ( Nx - Ny + P ) % P ;
			}
	}
	if( type != 1 ) for( re int i = 0; i < limit; ++ i ) a[i] = a[i] * fInv % P ; 
}
int solve( int x ) {
	cnt = 0, num = 0 ;
	rep( i, 1, x - 1 ) {
		if( vis[i] == 1 ) ++ cnt ;
		if( vis[i] > 1 ) ++ num ; 
	}
	memset( A, 0, sizeof(A) ), memset( B, 0, sizeof(B) ) ;
	rep( i, 0, cnt ) A[i] = Tw[i] * C( cnt, i ) % P ;
	rep( i, 0, 2 * num ) B[i] = C( 2 * num, i ) ;
	Init( cnt + 2 * num ), NTT( A, 1 ), NTT( B, 1 ) ;
	rep( i, 0, limit ) A[i] = ( A[i] * B[i] ) % P ; NTT( A, -1 ) ;
	rep( i, 1, T ) {
		int u = q[i] / 2 - x - 1 ;
		if( u < 0 ) continue ;
		Ans[i] = ( Ans[i] + A[u] ) % P ;
	}
}
void Init() {
	Inv[0] = fac[0] = Tw[0] = 1 ; 
	rep( i, 1, n ) fac[i] = ( fac[i - 1] * i ) % P, Tw[i] = ( Tw[i - 1] * 2ll ) % P ;
	Inv[n] = fpow( fac[n], P - 2 ) ;
	drep( i, 1, n ) Inv[i - 1] = ( Inv[i] * i ) % P ; 
}
signed main()
{
	n = gi(), m = gi(), Init() ;
	rep( i, 1, n ) a[i] = gi(), ++ vis[a[i]] ;
	rep( i, 1, m ) b[i] = gi() ; 
	T = gi() ;
	rep( i, 1, T ) q[i] = gi() ; 
	rep( i, 1, m ) solve( b[i] ) ;
	rep( i, 1, T ) printf("%I64d\n", Ans[i] % P ) ;
	return 0 ;
}