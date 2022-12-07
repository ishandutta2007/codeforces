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
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
const int N = 3e5 + 5 ; 
int m, n, a[N], fac[N], inv[N] ; 
int C(int x, int y) {
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
signed main()
{
	m = gi(), n = m * 2 ; 
	rep( i, 1, n ) a[i] = gi() ; 
	sort(a + 1, a + n + 1) ; 
	fac[0] = inv[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ;  
	rep( i, 1, n ) inv[i] = fpow( fac[i], P - 2 ) ; 
	int ans = 0 ; 
	rep( i, 1, n ) {
		int z = a[i] * C(n - 1, m - 1) ;
		if( i <= m ) ans = (ans - z + P) % P ; 
		else ans = (ans + z + P) % P ; 
	}
	cout << ans * 2 % P << endl ; 
	return 0 ;
}