#include<bits/stdc++.h>
using namespace std ; 
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
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
		if(k & 1) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ;
}
const int N = 1000 + 5 ; 
int n, m, a[N] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; } 
signed main() {
	m = gi() ; int ans = 0 ; 
	rep( i, 1, m ) a[i] = gi(), n += a[i] ; 
	rep( i, 1, m ) {
		int pre = 1, f = 1, g = 1 ;
		for(int x = 1; x < a[i]; ++ x) {
			f = f * (n - x) % P,
			g = g * (n - x) % P,
			pre = pre * (2 * n - x) % P, 
			inc(f, pre) ; 
		}
		ans = (ans + f * fpow(g, P - 2)) % P ; 
	}
	int pre = 1, f = 1, g = 1 ;
	for(int x = 1; x < n; ++ x) {
		f = f * (n - x) % P,
		g = g * (n - x) % P,
		pre = pre * (2 * n - x) % P, 
		inc(f, pre) ; 
	}
	ans = (f * fpow(g, P - 2) + P - ans) % P ; 
	cout << ans * 2 % P << endl ; 
	return 0 ; 
}