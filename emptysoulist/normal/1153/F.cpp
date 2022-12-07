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
const int P = 998244353 ; 
const int Gi = 332748118 ; 
const int G = 3 ; 
const int N = 4e5 + 5 ; 
int n, W, L, limit, Inv, maxn, K, R[N], fac[N], inv[N], A[N], B[N] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ;  
	} return ans ; 
}
int C( int x, int y ) {
	if( y > x ) return 0 ; 
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
void init( int x ) {
	limit = 1, L = 0 ; while( limit < x ) limit <<= 1, ++ L ;
	for(re int i = 0; i < limit; ++ i) R[i] = ( R[i >> 1] >> 1 ) | ((i & 1) << (L - 1)) ;
	Inv = fpow( limit, P - 2 ) ; 
}
void NTT( int *a, int type ) {
	for( re int i = 0; i < limit; ++ i ) if( R[i] > i ) swap( a[i], a[R[i]] ) ; 
	for( re int k = 1; k < limit; k <<= 1 ) {
		int d = fpow( (type == 1) ? G : Gi, ( P - 1 ) / (k << 1) ) ;
		for( re int i = 0; i < limit; i += (k << 1) ) 
		for( re int j = i, g = 1; j < i + k; ++ j, g = g * d % P ) {
			int nx = a[j], ny = a[j + k] * g % P ; 
			a[j] = (nx + ny) % P, a[j + k] = (nx - ny + P) % P ; 
		}
	} if( !type ) rep( i, 0, limit ) a[i] = a[i] * Inv % P ; 
}
signed main()
{
	n = gi(), K = gi(), W = gi(), fac[0] = inv[0] = 1 ; 
	maxn = n * 2 + 1 ; 
	rep( i, 1, maxn ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ; 
	rep( i, K, n ) A[i] = inv[i] ; 
	rep( i, 0, n ) B[i] = (i & 1) ? P - inv[i] : inv[i] ;
	init(n + n + 5), NTT( A, 1 ), NTT( B, 1 ) ;
	rep( i, 0, limit ) A[i] = A[i] * B[i] % P ; 
	NTT( A, 0 ) ;
	int ans = 0 ; 
	rep( i, K, n ) {
		int x = fac[i] * fac[i] % P * fac[i] % P ; 
		x = x * inv[2 * i + 1] % P * fpow( 2, i ) % P * C(n, i) % P ; 
		ans = ( ans + x * A[i] % P ) % P ; 
	}
	cout << ans * W % P << endl ;
	return 0 ;
}