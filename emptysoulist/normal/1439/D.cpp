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
const int N = 500 + 5 ; 
int n, m, P, maxn, fac[N], inv[N], F[N][N], G[N][N], f[N], g[N] ;  
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int C(int x, int y) {
	if( x < y ) return 0 ; 
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
int S(int x) {
	return x * (x + 1) / 2 ; 
}
signed main()
{
	n = gi(), m = gi(), P = gi() ; 
	maxn = n + 1, fac[0] = inv[0] = 1 ; 
	rep( i, 1, maxn ) fac[i] = fac[i - 1] * i % P ; 
	rep( i, 1, maxn ) inv[i] = fpow( fac[i], P - 2 ) ;
	f[0] = 1 ; 
	rep( i, 1, m ) {
		for(re int j = 0; j < i; ++ j) 
			f[i] = (f[i] + f[j] * f[i - 1 - j] % P * C(i - 1, j) % P) % P, 
			g[i] = (g[i] + 
				( (g[j] * f[i - 1 - j] % P + f[j] * g[i - 1 - j] % P ) * (i + 1) % P 
				+ f[j] * f[i - 1 - j] % P * (S(j) + S(i - 1 - j)) % P) * C(i - 1, j) % P) % P ; 
		f[i] = f[i] * (i + 1) % P ;  
	}
	F[0][0] = 1 ; 
	rep( j, 0, n ) F[0][j] = 1 ; 
	rep( i, 1, m ) {
		F[i][i] = f[i], G[i][i] = g[i] ; 
		for(re int j = i + 1; j <= n; ++ j) {
			F[i][j] = F[i][j - 1], G[i][j] = G[i][j - 1] ; 
			for(re int l = 1; l <= i; ++ l) {
				F[i][j] = (F[i][j] + F[i - l][j - 1 - l] * f[l] % P * C(i, l) % P) % P,
				G[i][j] = (G[i][j] + (G[i - l][j - 1 - l] * f[l] % P + F[i - l][j - 1 - l] * g[l] % P) * C(i, l) % P) % P ; 
			}
		//	printf("QAQ (%lld %lld) %lld %lld\n", i, j, F[i][j], G[i][j] ) ; 
		} 
	}
	cout << G[m][n] << endl ; 
	return 0 ;
}