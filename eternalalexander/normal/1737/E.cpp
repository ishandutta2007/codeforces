#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int maxn = 1e6 + 222;
const int inv2 = (mod + 1) / 2;;
using ll = long long;

int n,f[maxn],pw[maxn],s1[maxn],s2[maxn];

void solve() {
	scanf("%d",&n); // check 1
	f[n] = s1[n] = 1; s1[n + 1] = 0;
	for (int i = n - 1; i >= 1; i --) {
		f[i] = s1[i] = 0;
		f[i] = ( s1[i + 1] - s1[std::min(2 * i,n+1)] + mod) % mod;
		s1[i] = (s1[i + 1] + f[i]) % mod;
	}
	int inv = 1;
	pw[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		inv = (ll) inv * inv2 % mod;
		pw[i] = (ll) pw[i - 1] * 2 % mod;
		s2[i] = (s2[i - 1] + pw[i - 1]) % mod;
	}
	for (int i = 1; i <= n; ++ i) {
		int limj = i / 2;
		int sum = s2[limj];
		//for (int j = 1; j <= limj; ++ j) sum = (sum + pw[j - 1]) % mod;
		int ans = (ll) (1 + sum) * f[i] % mod * 2 % mod * inv % mod;
		printf("%d\n",ans);
	} 
}
			

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}