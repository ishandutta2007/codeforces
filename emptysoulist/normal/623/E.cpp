#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
#define double long double 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4e5 + 5 ;
const int P = 1e9 + 7 ; 
const double Pi = acos( -1.0 ) ; 
int n, m, cnt, num, maxn, limit, nAns, L, R[N], Ans[N], Base[N], G[N], base[N], fac[N], inv[N] ; 
struct Complex {
	double x, y ; 
	Complex( double xx = 0, double yy = 0 ) { x = xx, y = yy ; }
	void init() { x = 0, y = 0 ; }
} F[N], Q[N], C[N], A1[N], A2[N], B1[N], B2[N] ; 
Complex Conj( Complex x ) { return Complex( x.x, -x.y ) ; }
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
Complex operator * ( Complex x, Complex y ) { return Complex( x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x ) ; }
Complex operator + ( Complex x, Complex y ) { return Complex( x.x + y.x, x.y + y.y ) ; }
Complex operator - ( Complex x, Complex y ) { return Complex( x.x - y.x, x.y - y.y ) ; }
Complex operator / ( Complex x, double y ) { return Complex(x.x / y, x.y / y ) ; }
void FFT( Complex *a, int type ) {
	for( int i = 0; i < limit; ++ i ) if( R[i] > i ) swap( a[R[i]], a[i] ) ;
	for( int k = 1; k < limit; k <<= 1 ) {
		Complex Dw = Complex( cos( Pi / k ), type * sin( Pi / k ) );	
		for( int i = 0; i < limit; i += ( k << 1 ) ) {
			Complex w = Complex( 1, 0 ) ;
			for( int j = i; j < i + k; ++ j, w = w * Dw ) {
				Complex Ny = w * a[j + k], Nx = a[j] ;
				a[j + k] = Nx - Ny,	a[j] = Nx + Ny ; 
			} 
		}
	}	
	if( type != 1 ) rep( i, 0, limit ) a[i] = a[i] / (double)limit ;
}
void init( int x ) {
	limit = 1, L = 0 ; 
	while( limit < x ) limit <<= 1, ++ L ;
	rep( i, 0, limit ) R[i] = ( R[i >> 1] >> 1 ) | ( ( i & 1 ) << ( L - 1 ) ) ;
}
void Mul( int *a, int *b, int l ) {
	rep( i, 0, l ) A1[i].x = a[i] / cnt, A2[i].x = a[i] % cnt ; 
	rep( i, 0, l ) B1[i].x = b[i] / cnt, B2[i].x = b[i] % cnt ; 
	FFT( A1, 1 ), FFT( A2, 1 ), FFT( B1, 1 ), FFT( B2, 1 ) ; 
	rep( i, 0, limit ) F[i] = A1[i] * B1[i], Q[i] = ( A1[i] * B2[i] + A2[i] * B1[i] ), C[i] = A2[i] * B2[i] ; 
	FFT( F, -1 ), FFT( Q, -1 ), FFT( C, -1 ) ;
	rep( i, 0, limit ) 
		a[i] = ( (int)(F[i].x + 0.5) % P * num % P + ( (int)(Q[i].x + 0.5) % P * cnt ) % P + (int)(C[i].x + 0.5) % P ) % P,
		F[i].init(), Q[i].init(), C[i].init(), A1[i].init(), A2[i].init(), B1[i].init(), B2[i].init() ; 
	for( re int i = l + l + 1; i <= limit; ++ i ) a[i] = 0 ;
} 
int A[N], B[N] ; 
void Mull( int *a, int *b, int k ) {
	int fs = fpow( 2, k ) ;
	rep( i, 0, limit ) A[i] = a[i] * fpow( fs, i ) % P ; 
	rep( i, 0, limit ) B[i] = b[i] ; 
	Mul( A, B, n ) ;
	rep( i, 0, limit ) a[i] = A[i] % P ; 
	rep( i, n + 1, limit ) a[i] = 0 ; 
	rep( i, 0, limit ) A[i] = 0, B[i] = 0 ;
}
int CC( int x, int y ) {
	return ( y > x ) ? 0 : fac[x] * inv[y] % P * inv[x - y] % P ; 
}
signed main()
{
	m = gi(), n = gi() ; maxn = n + m ; 
	if( m > n ) { puts("0") ; exit(0) ; }
	cnt = 32768, num = cnt * cnt % P ; 
	fac[0] = inv[0] = 1, init(n + n + 1) ; 
	rep( i, 1, limit ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ;
	Ans[0] = 1 ; rep( i, 1, limit ) Base[i] = P - inv[i] ; 
	int k = 1, uk = m ; 
	while(m) {
		if( m & 1 ) Mull( Ans, Base, k ) ;
		rep( i, 0, limit ) G[i] = Base[i] ; 
		Mull( Base, G, k ), m >>= 1 ; 
		rep( i, 0, limit ) G[i] = 0 ;  k <<= 1 ; 
	}
	rep( i, 0, n ) nAns = ( nAns + fac[i] * Ans[i] % P * CC( n, i ) % P ) % P ;
	if( uk & 1 ) nAns = P - nAns ; 
	printf("%lld\n", nAns ) ;
	return 0 ;
}