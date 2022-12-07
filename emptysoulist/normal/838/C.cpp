#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define Rep( i, s, t ) for( register int i = (s); i < (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = ( 1 << 18 ) + 5 ; 
const int M = 25 ; 
int n, L, K, P, limit, iv[N], bit[N], inv[N], dp[N], g[M][N], f[M][N], Ans[N], fac[N] ; 
void Mod( int *a ) { rep( i, 0, limit ) a[i] = ( a[i] % P + P ) % P ; }
void FWT( int *a ) { for( re int k = 1; k < limit; k <<= 1 ) Rep(i, 0, limit) if(i & k) a[i] += a[i ^ k], a[i] %= P ; }
void IFWT( int *a ) { for( re int k = 1; k < limit; k <<= 1 ) Rep(i, 0, limit) if(i & k) a[i] = ( a[i] - a[i - k] + P ) % P; }
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
int A[M], B[M], Fp[M], Fm[M] ; 
void dec( int &x, int y ) {
	x -= y, x += P, x %= P ; 
} 
void Inv( int *a ) {
	rep( j, 0, L ) Fp[j] = 0 ; 
	Fp[0] = 1 ; 
	rep( j, 1, L ) Rep( k, 0, j ) 
		dec( Fp[j], Fp[k] * A[j - k] % P ) ;  
	rep( j, 0, L ) a[j] = Fp[j] ; 
}
void PolyInt( int *a ) {
	drep( i, 1, L ) a[i] = iv[i] * a[i - 1] % P ; a[0] = 0 ; 
}
void Polydiv( int *a ) {
	rep( i, 1, L ) a[i - 1] = i * a[i] % P ; 
}
void Mul( int *a, int *b ) {
	rep( j, 0, L ) Fm[j] = 0 ; 
	rep( j, 0, L ) rep( k, 0, j ) Fm[j] = ( Fm[j] + a[k] * b[j - k] % P ) % P ; 
	rep( j, 0, L ) a[j] = Fm[j] ;
}
void Polyexp(int *a) {
	rep( j, 0, L ) Fp[j] = 0 ; 
	Polydiv(a), Fp[0] = 1 ; 
	rep( j, 1, L ) {
		Rep( k, 0, j ) 
			Fp[j] = (Fp[j] + Fp[k] * a[j - k - 1] % P) % P ; 
		Fp[j] = iv[j] * Fp[j] % P ; 
	}
	rep( j, 0, L ) a[j] = Fp[j] ; 
}
signed main()
{
	n = gi(), K = gi(), P = gi(), limit = 1 ; 
	if( n & 1 ) { printf("%lld\n", fpow( K, n ) ) ; exit(0) ; }
	while( limit <= n ) limit <<= 1, ++ L ; fac[0] = inv[0] = 1 ; ++ L ; 
	rep( i, 1, limit ) {
		fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ), iv[i] = fpow( i, P - 2 ) ; 
	}
	Rep( i, 1, limit ) bit[i] = bit[i ^ (i & (-i))] + 1 ; 
	Rep( i, 0, limit ) f[bit[i]][i] = g[bit[i]][i] = inv[i] ; 
	Rep( i, 0, L ) FWT( f[i] ) ; 
	Rep( i, 0, limit ) {
		rep( j, 0, L ) B[j] = A[j] = f[j][i] ; 
		Polydiv(B), Inv(A), Mul( A, B ), PolyInt(A) ; 
		rep( j, 0, L ) A[j] = A[j] * K % P ; 
		Polyexp(A), Ans[i] = A[bit[n]] ; 
	} 
	IFWT( Ans ) ; 
	int ans = fpow( K, n ) ; 
	int uans = fac[n] * Ans[n] % P ; 
	cout << (ans - uans + P) % P << endl ; 
	return 0 ;
}