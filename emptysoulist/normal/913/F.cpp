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
const int N = 3000 + 5 ; 
const int P = 998244353 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, p, fv1[N], fv2[N], dp[N][N], h[N], g[N], f[N] ; 
void inc(int &x, int y) { x += y, x %= P ; }
signed main()
{
	n = gi() ; int a = gi(), b = gi() ;
	p = a * fpow(b, P - 2) % P, fv1[0] = fv2[0] = 1 ;
	rep( i, 1, n ) fv1[i] = fv1[i - 1] * p % P ;
	rep( i, 1, n ) fv2[i] = fv2[i - 1] * (1 - p + P) % P ; 
	dp[0][0] = 1 ;
	for(int i = 0; i < n; ++ i) {
		rep( j, 0, i ) 
			inc( dp[i + 1][j], dp[i][j] * fv1[j] % P ),
			inc( dp[i + 1][j + 1], dp[i][j] * fv2[i - j] % P ) ;
	}
	g[1] = 1, h[1] = f[1] = 0 ; 
	rep( i, 2, n ) {
		g[i] = 1 ; 
		for(re int k = 1; k < i; ++ k) 
			inc(g[i], P - g[k] * dp[i][k] % P) ; 
		int k = 1 - g[i] + P, c = (i * (i - 1) / 2) ; 
		k %= P, k = fpow(k, P - 2) ; 
		for(re int j = 1; j < i; ++ j)
		inc(c, g[j] * dp[i][j] % P * (f[j] + h[i - j]) % P) ; 
		f[i] = c * k % P ;
		for(re int j = 1; j <= i; ++ j)
		inc(h[i], g[j] * dp[i][j] % P * (f[j] + h[i - j]) % P) ; 
	}
	printf("%lld\n", f[n] ) ; 
	return 0 ;
}