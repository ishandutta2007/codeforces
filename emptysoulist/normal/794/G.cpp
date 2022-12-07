#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define int long long
const int P = 1e9 + 7 ; 
const int N = 6e5 + 5 ; 
char s[N], t[N] ; 
int n, f[N], fac[N], inv[N], mu[N], isp[N] ; 
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
int Get(int dA, int dB) {
	if(dA * dB < 0) return 0 ; 
	if(dA * dB == 0) {
		if(dA != 0 || dB != 0) return 0 ; 
		int p = 1, ans = 0 ; 
		rep( d, 1, n ) {
			p = p * 2 % P ; int o = 0 ; 
			rep( k, 1, n / d ) 
				o += mu[k] * (n / (k * d)) % P * (n / (k * d)) % P ;
			o %= P, ans = (ans + p * o) % P ; 
		} return ans ; 
	}
	dA = abs(dA), dB = abs(dB) ; 
	int d = __gcd(dA, dB) ; 
	return f[n * d / max(dA, dB)] ; 
}
signed main() {
	cin >> s + 1 >> t + 1 >> n ; 
	int lS = strlen(s + 1), lT = strlen(t + 1) ; 
	int maxn = max(max(lS, lT), n) * 2 ; fac[0] = inv[0] = 1 ; 
	rep( i, 1, maxn ) fac[i] = fac[i - 1] * i % P ; 
	rep( i, 1, maxn ) inv[i] = fpow(fac[i], P - 2) ; 
	rep( i, 1, n ) mu[i] = 1 ;  
	rep( i, 2, n ) if(!isp[i]) {
		for(int j = i; j <= n; j += i) mu[j] = P - mu[j], isp[j] = 1 ; 
		for(int j = i * i; j <= n; j += i * i) mu[j] = 0 ; 
	} f[0] = 1 ; 
	rep( i, 1, n ) f[i] = f[i - 1] * 2 % P ; f[0] = 0 ; 
	rep( i, 2, n ) f[i] = (f[i - 1] + f[i]) % P ; 
	int a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0 ; 
	rep( i, 1, lS ) {
		if(s[i] == '?') ++ c1 ; 
		if(s[i] == 'A') ++ a1 ; 
		if(s[i] == 'B') ++ b1 ; 
	}
	rep( i, 1, lT ) { 
		if(t[i] == '?') ++ c2 ;
		if(t[i] == 'A') ++ a2 ; 
		if(t[i] == 'B') ++ b2 ; 
	}
	int ans = 0 ; 
	for(int dA = -lT; dA <= lS; ++ dA) {
		int dB = dA + lT - lS ; 
		ans = (ans + C(c1 + c2, dA + a2 - a1 + c2) * Get(dA, dB)) % P ; 
	}
	if(lT == lS) {
		c1 = c2 = a1 = a2 = b1 = b2 = 0 ; 
		rep( i, 1, lT ) {
			if(t[i] == 'A' || s[i] == 'A') ++ a1, ++ a2 ;
			if(t[i] == 'B' || s[i] == 'B') ++ b1, ++ b2 ; 
			if(t[i] == '?' && s[i] == '?') ++ c1, ++ c2 ; 
		}
		if((a1 + b1 + c1) == lT) {
			int dA = a1 - a2, dB = b2 - b1 ; 
			ans = (ans + fpow(2, c1) * (f[n] * f[n] % P - Get(dA, dB) + P)) % P ; 
		}
	}
	cout << ans << endl ; 
	return 0 ; 
}