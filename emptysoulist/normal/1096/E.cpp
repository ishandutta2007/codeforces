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
const int N = 1e4 + 5 ; 
int n, m, S, maxn, fac[N], inv[N], iv[N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int C(int x, int y) {
	if(x < 0 || y < 0 || x < y) return 0 ;
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
int F(int a, int b, int c) {
	if( b == 0 && c == 0 ) return 1 ; 
	if( a < 0 || b <= 0 || c < 0 ) return 0 ; 
	int ans = 0, lim = min(b, (c + b) / (a + 1)) ; 
	for(re int i = 0; i <= lim; ++ i) {
		if(i & 1) ans = (ans - C(b, i) * C(c - i * (a + 1) + b - 1, b - 1) % P + P) % P ; 
		else ans = (ans + C(b, i) * C(c - i * (a + 1) + b - 1, b - 1) % P) % P ; 
	}
	return ans ; 
}
signed main()
{
	n = gi(), S = gi(), m = gi() ; 
	if( n == 1 ) { puts("1") ; exit(0) ; }
	maxn = max( S, n ) * 2, fac[0] = inv[0] = 1 ; 
	rep( i, 1, maxn ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ) ; 
	rep( i, 1, maxn ) iv[i] = fpow(i, P - 2) ; 
	-- n ; int ans = 0, fm = 0 ; 
	for(re int x = m; x <= S; ++ x) {
		for(re int i = 0; i <= n; ++ i) 
		ans = (ans + C(n, i) * iv[i + 1] % P * F(x - 1, n - i, S - (i + 1) * x)) % P ; 
		fm = (fm + C(n + S - x - 1, n - 1)) % P ; 
	}
	cout << ans * fpow( fm, P - 2 ) % P << endl ; 
	return 0 ;
}