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
const int N = 2e6 + 5 ; 
const int P = 998244353 ; 
int n, m, Ex, fac[N], inv[N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
} 
signed main()
{
	n = gi(), m = gi(), inv[0] = fac[0] = 1 ; 
	Ex = (1 + fpow(m + 1, P - 2) * n % P) % P ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ; 
	inv[n] = fpow( fac[n], P - 2 ) ;
	drep( i, 1, n ) inv[i - 1] = inv[i] * i % P ; 
	int ans = 0 ;
	rep( i, 1, n ) {
		int d = fac[n] * inv[i] % P * inv[n - i] % P * (m + i) % P * inv[i] % P * fac[i - 1] % P ;
		if(i & 1) ans = (ans + d) % P ;
		else ans = (ans - d + P) % P ; 
	}
	cout << ans * Ex % P << endl ; 
	return 0 ;
}