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
const int N = 3600 + 5 ; 
const int P = 998244353 ; 
int n, m, maxn, L1, L2, K, fac[N], f[N][N], g[N][N], c[N][N], A[N], B[N] ; 
void Over() { puts("0") ; exit(0) ; }
int C(int x, int y) {
	if( x < 0 || y < 0 ) return 0 ; 
	return c[x][y] ; 
}
signed main()
{
	n = gi(), m = gi(), K = gi(), maxn = max( n, m ) ; 
	int ax, ay, bx, by ; 
	rep( i, 1, K ) {
		ax = gi(), ay = gi(), bx = gi(), by = gi() ; 
		if( A[ax] || A[bx] || B[ay] || B[by] ) Over() ; 
		if( ax == bx ) A[ax] = 1, B[ay] = 1, B[by] = 1 ; 
		else A[ax] = 1, A[bx] = 1, B[by] = 1 ; 
	}
	rep( i, 1, n ) if( !A[i] ) ++ L1 ; 
	rep( i, 1, m ) if( !B[i] ) ++ L2 ; c[0][0] = 1 ; 
	rep( i, 1, maxn ) rep( j, 0, maxn ) c[i][j] = (!j) ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % P ; 
	fac[0] = 1 ; 
	rep( i, 1, maxn ) fac[i] = fac[i - 1] * i % P ;  
	f[0][0] = 1, A[0] = 1 ; 
	rep( i, 1, n ) {
		rep( j, 0, n ) f[i][j] = f[i - 1][j] ;  
		if( A[i] || A[i - 1] ) continue ; 
		rep( j, 1, n ) f[i][j] = ( f[i][j] + f[i - 2][j - 1] ) % P ; 
	}
	g[0][0] = 1, B[0] = 1 ; 
	rep( i, 1, m ) {
		rep( j, 0, m ) g[i][j] = g[i - 1][j] ;  
		if( B[i] || B[i - 1] ) continue ; 
		rep( j, 1, m ) g[i][j] = ( g[i][j] + g[i - 2][j - 1] ) % P ; 
	}
	int Ans = 0 ; 
	rep( i, 0, n ) rep( j, 0, n ) 
		Ans = ( Ans + f[n][i] * g[m][j] % P * C( L1 - 2 * i, j ) % P * 
						C( L2 - 2 * j, i ) % P * fac[j] % P * fac[i] % P ) % P ; 
	cout << Ans << endl ; 
	return 0 ;
}