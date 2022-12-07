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
const int N = 2e6 + 5 ; 
int n, m, ans, fac[N], inv[N], f[N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ; 
	while(k) {
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
int C(int x, int y) {
	if(y < 0 || x < y) return 0 ; 
	return fac[x] * inv[y] % P * inv[x - y] % P ; 
}
signed main() {
	n = gi(), m = n * 2, fac[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ; 
	rep( i, 0, n ) inv[i] = fpow(fac[i], P - 2) ; 
	rep( i, 0, n / 2 ) {
		f[i] = (C(n - i - 1, i - 1) + C(n - i, i)) % P ; 
		if((i & 1) == (n & 1)) (ans += f[i] * 2 * fac[n - i] % P) %= P ; 
	}
	cout << ans << endl ; 
	return 0 ;
}