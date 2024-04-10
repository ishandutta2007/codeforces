#include <bits/stdc++.h>

using ll = long long;
const int lim = 1e5;
const int mod = 1e9 + 7;

int inv(int x) { return x == 1 ? 1 : (ll) (mod - mod / x) * inv(mod % x) % mod; }

int n,f[lim + 10],ans,s,a[2505];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	s = std::accumulate(a+1,a+n+1,0);
	f[1] = (ll) ( s - 1 ) * ( s - 1 ) % mod * inv(s) % mod;
	f[2] = ( (2ll * f[1] - 1) % mod + mod ) % mod;
	for (int i = 2; i <= lim && i < s; ++ i) {
		int Q = (ll) (s - 1 + mod) * inv((s - i + mod) % mod) % mod;
		f[i+1] = (( (2ll * f[i] - f[i-1]) % mod + mod) % mod - Q + mod) % mod;
	} for (int i = 1; i <= n; ++ i) ans = (ans + f[a[i]]) % mod;
	printf("%d",ans);
	return 0;
}