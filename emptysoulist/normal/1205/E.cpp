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
const int P = 1e9 + 7 ; 
const int I = 1e9 + 8 ; 
int n, K, Ans, f[N], g[N], fac[N], mu[N] ;
bool isp[N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
void init() {
	rep( i, 1, 2 * n ) fac[i] = fpow( K, i ) % P ; 
	rep( i, 1, n ) 
		f[i] = ( f[i - 1] + (i - 1) ) % P ; 
	rep( x, 1, n ) {
		int lim = (n - 1) / x + 1 ; 
		rep( i, 1, lim ) g[x] = (g[x] + (i - 1) * fac[i * x] % P) % P ;
	}
	rep( i, 1, n ) mu[i] = 1 ; 
	rep( i, 2, n ) {
		if(isp[i]) continue ; mu[i] = -1 ; int v = i * i ; 
		for(re int j = i * 2; j <= n; j += i) isp[j] = 1, mu[j] = -mu[j] ;
		for(re int j = v; j <= n; j += v) mu[j] = 0 ;
	}
	rep( i, 1, n ) mu[i] = (P + mu[i]) % P ; 
}
int gcd(int a, int b) {
	return (!a) ? b : gcd(b % a, a) ;  
}
signed main()
{
	n = gi(), K = gi() ; 
	init() ; 
	rep( i, 1, 2 * n ) {
		if( i <= n ) Ans = ( Ans + fpow(K, i) * (i - 1) ) % P ; 
		else Ans = ( Ans + fpow(K, i) * (2 * n - i + 1) ) % P ; 
	} 
	Ans = Ans * fpow( fpow( K, n ), P - 2 ) % P ;
	int dAns = 0 ;
	rep(d, 1, n) {
		int fK = fpow( K, d ) ; 
		rep(k, 1, n / d) { 
			int x = k * d ; 
			int lim = (n - 1) / x + 1 ; 
			int rim = (n + d - 1) / x ; 
			if( lim == rim ) dAns = ( dAns + mu[k] * g[x]) % P ; 
			else dAns = ( dAns + mu[k] * (g[x] - (lim - 1) * fac[lim * x] % P + P ) % P ) % P ; 
			Ans = ( Ans + mu[k] * f[rim] % P * fac[d] % P ) % P ; 
		}
	}
	dAns = dAns * fpow( fpow( K, n ), P - 2 ) % P ;
	Ans = ( Ans - dAns + P ) % P ; 
	rep(i, 1, n) Ans = ( Ans - ( 1 + (i != n) ) * fac[max(i, gcd(i, n))] + P ) % P ; 
	Ans %= P, Ans = ( Ans + P ) % P ; 
	cout << Ans * fpow( fac[n], P - 2 ) % P << endl ;  
	return 0 ;
}