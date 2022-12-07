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
const int P = 1e9 + 7 ; 
const int Iv2 = 5e8 + 4 ;
const int N = 1e6 + 5 ; 
const int M = 3e5 + 5 ; 
const int W = 22 ; 
int n, maxn, F[M], w[M], s[N], A[N], B[N], C[N], f[W][M], g[W][M], limit ; 
void FWT_xor( int *a, int type )  {
	for( re int k = 1; k < limit; k <<= 1 ) {
		for( re int i = 0; i < limit; i = ( i + ( k << 1) ) )
		for( re int j = i; j < i + k; ++ j ) {
			int nx = a[j], ny = a[j + k] ;
			( type == 1 ) ? ( a[j] = ( nx + ny ) % P, a[j + k] = ( nx - ny + P ) % P ) : ( a[j] = ( nx + ny ) * Iv2 % P, 
				a[j + k] = ( nx - ny + P ) * Iv2 % P ) ; 
		}
	}
}
void FWT_or( int *a, int type ) {
	for( re int k = 1; k < limit; k <<= 1 ) {
		for( re int i = 0; i < limit; i = ( i + ( k << 1) ) )
		for( re int j = i; j < i + k; ++ j ) {
			( type == 1 ) ? ( a[j + k] = ( a[j + k] + a[j] ) % P ) : ( a[j + k] = ( a[j + k] - a[j] + P ) % P ) ; 
		}
	}
}
void FWT_and( int *a, int type ) {
	for( re int k = 1; k < limit; k <<= 1 ) {
		for( re int i = 0; i < limit; i = ( i + ( k << 1) ) )
		for( re int j = i; j < i + k; ++ j ) {
			( type == 1 ) ? ( a[j] = ( a[j + k] + a[j] ) % P ) : ( a[j] = ( -a[j + k] + a[j] + P ) % P ) ; 
		}
	}
}
int lowbit( int x ) {
    return __builtin_popcountll(x) ;
}
signed main()
{
	n = gi(), maxn = 0 ;
	rep( i, 1, n ) s[i] = gi(), maxn = max( maxn, s[i] ), ++ w[s[i]] ;
	limit = 1 ; while( limit <= maxn ) limit <<= 1 ; 
	rep( i, 0, limit ) C[i] = w[i], B[i] = w[i], f[lowbit(i)][i] = w[i] ; F[0] = 0, F[1] = 1 ; 
	rep( i, 2, limit ) F[i] = ( F[i - 1] + F[i - 2] ) % P ; 
	
	FWT_xor( C, 1 ) ;
	rep( i, 0, limit ) C[i] = C[i] * C[i] % P ;
	FWT_xor( C, 0 ) ;
	rep( i, 0, limit ) C[i] = C[i] * F[i] % P, B[i] = B[i] * F[i] % P ; 
	
	rep( i, 0, 17 ) FWT_xor( f[i], 1 ) ;
	rep( i, 0, limit ) {
		rep( j, 0, 17 ) rep( k, 0, j ) 
		g[j][i] = ( g[j][i] + f[k][i] * f[j - k][i] % P ) % P ; 
	}
	rep( i, 0,17 ) FWT_xor( g[i], 0 ) ;
	rep( i, 0, limit ) A[i] = F[i] * g[lowbit(i)][i] % P ; 
	FWT_and( C, 1 ), FWT_and( B, 1 ), FWT_and( A, 1 ) ;
	rep( i, 0, limit ) A[i] = A[i] * B[i] % P * C[i] % P ; 
	FWT_and( A, 0 ) ;
	int Ans = 0 ;
	rep( i, 0, 17 ) Ans = ( Ans + A[1 << i] ) % P ; 
	printf("%lld\n", Ans ) ; 
	return 0 ;
}