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
const int N = 4e5 + 5 ; 
const double Pi = acos(-1.0) ; 
int n, m, q, limit, L, R[N], A[N], B[N] ; 
int V1[N], V2[N], E1[N], E2[N], F1[N], F2[N] ; 
struct Complex {
	double x, y ; 
	Complex(double _x = 0, double _y = 0) { x = _x, y = _y ; }
} F[N], G[N], H[N], D[N], E[N], Q[N], Ans[N], A1[N], A2[N], A3[N], A4[N], A5[N], A6[N], A7[N] ;
Complex operator + (const Complex &x, const Complex &y) { return Complex(x.x + y.x, x.y + y.y) ; }
Complex operator * (const Complex &x, const Complex &y) { return Complex(x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x) ; }
Complex operator - (const Complex &x, const Complex &y) { return Complex(x.x - y.x, x.y - y.y) ; }
void init(int x) {
	L = 0, limit = 1 ; while(limit < x) limit <<= 1, ++ L ; 
	for(re int i = 0; i < limit; ++ i) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1)) ;
}
void FFT(Complex *a, int type) {
	for(re int i = 0; i < limit; ++ i) if( R[i] > i ) swap( a[i], a[R[i]] ) ;
	for(re int k = 1; k < limit; k <<= 1) {
		Complex dw = Complex(cos(Pi / k), type * sin(Pi / k)) ;
		for(re int i = 0; i < limit; i += (k << 1) ) {
			Complex w = Complex(1, 0) ;
			for(re int j = i; j < i + k; ++ j, w = w * dw ) {
				Complex nx = a[j], ny = a[j + k] * w ;
				a[j] = nx + ny, a[j + k] = nx - ny ; 
			}
		}
	} if( type != 1 ) for(re int i = 0; i < limit; ++ i ) a[i].x = (a[i].x / (1.0 * limit) + 0.5) ; 
}
void mul(Complex *a, Complex *b, Complex *c) {
	for(re int i = 0; i < limit; ++ i) a[i] = b[i] * c[i] ; FFT(a, -1) ;
}
signed main()
{
	n = gi(), m = gi(), q = gi() ; int maxn = 1e5 ; 
	rep( i, 1, n ) A[i] = gi(), ++ F[A[i]].x, maxn = max( maxn, A[i] ) ; 
	rep( i, 1, m ) B[i] = gi(), ++ G[B[i]].x, maxn = max( maxn, B[i] ) ; 
	rep( i, 2, n ) ++ H[min(A[i], A[i - 1])].x, ++ E[max(A[i], A[i - 1])].x ;
	rep( i, 2, m ) ++ D[min(B[i], B[i - 1])].x, ++ Q[max(B[i], B[i - 1])].x ; 
	init(maxn * 2 + 3), FFT(F, 1), FFT(G, 1), FFT(H, 1), FFT(D, 1), FFT(E, 1), FFT(Q, 1) ;
	mul(A1, F, G) ; //G1 and G2 idx
	mul(A4, F, Q), mul(A5, G, E) ; //G2 edge
	mul(A2, F, D), mul(A3, G, H) ; //G1 edge 
	mul(A6, H, D) ; //four G1
	mul(A7, E, Q) ; //four G2
	rep( i, 0, limit ) 
		V1[i] = (int)(A1[i].x), V2[i] = (int)(A1[i].x),
		E1[i] = (int)(A2[i].x) + (int)(A3[i].x),
		E2[i] = (int)(A4[i].x) + (int)(A5[i].x),
		F1[i] = (int)(A6[i].x), F2[i] = (int)(A7[i].x) ; 
	drep( i, 1, limit ) V1[i - 1] += V1[i], E1[i - 1] += E1[i], F1[i - 1] += F1[i] ; 
	rep( i, 1, limit ) V2[i] += V2[i - 1], E2[i] += E2[i - 1], F2[i] += F2[i - 1] ;
	while(q--) {
		int x = gi() ; 
		int ans = V1[x] - V2[x - 1] + F1[x] - F2[x - 1] - E1[x] + E2[x - 1] ;  
		cout << ans << endl ; 
	}
	return 0 ;
}