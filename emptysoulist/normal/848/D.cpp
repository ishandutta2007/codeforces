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
const int P = 1e9 + 7 ; 
const int N = 50 + 5 ; 
int n, m, g[N][N], f[N][N], fac[N], inv[N], D[N][N][N] ;
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ;
	} return ans ;
}
void inc(int &x, int y) {
	((x += y) >= P) && (x -= P) ; 
}
int C(int x, int y) {
	int ans = 1 ;
	rep( i, 1, y ) ans = ans * (x - i + 1) % P ; 
	return ans * inv[y] % P ; 
}
signed main()
{
	n = gi(), m = gi() ; fac[0] = inv[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ; 
	g[0][0] = f[0][0] = 1 ; 
	for(re int i = 1; i <= n; ++ i) {
		for(re int u = 0; u < i; ++ u) { 
			int v = i - u - 1 ; 
			rep( l, 0, u ) rep( r, 0, v )
				inc( g[i][min(l, r) + 1], f[u][l] * f[v][r] % P ) ; 
		}
		rep( k, 1, n / i ) rep( j, 1, i ) D[k][i][j] = C(g[i][j] + k - 1, k) ; 
		rep( j, 1, i ) drep( x, i, n ) rep( k, 1, x / i )  {
			int d = D[k][i][j] ; 
			rep( li, k * j, x ) inc( f[x][li], f[x - i * k][li - k * j] * d % P ) ;
		}
	}
	cout << f[n][m - 1] << endl ; 
	return 0 ;
}