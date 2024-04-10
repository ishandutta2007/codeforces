#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 2e5 + 5 ; 
const int maxn = 2e5 ; 
int n, m, f[N], fac[N], inv[N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
int C(int x, int y) { return fac[x] * inv[y] % P * inv[x - y] % P ; }
signed main() {
	int t = gi() ; fac[0] = 1 ; 
	rep( i, 1, maxn ) fac[i] = fac[i - 1] * i % P ; 
	rep( i, 0, maxn ) inv[i] = fpow(fac[i], P - 2) ; 
	while( t-- ) {
		n = gi(), m = gi() ; int ans = 1 ; 
		for(int i = 1; i <= n; ++ i) {
			int ret = n - i - (i - 1) * (m - 1) ; 
			if(ret < 0) break ; 
			int d = C(ret + i, i) * fpow(C(n, i), P - 2) % P ; 
			ans = (ans + d) % P ; 
		}
		cout << ans << endl ; 
	}
	return 0 ;
}