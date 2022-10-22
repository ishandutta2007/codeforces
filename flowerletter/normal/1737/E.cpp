#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1e6 + 10, mod = 1e9 + 7;
int n, m, f[N], g[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		cin >> n;
		f[n + 1] = g[n + 1] = 1;
		g[n + 2] = 0;
		for(int i = n; i >= 1; i --) {
			f[i] = (g[i + 1] - g[min(n + 2, 2 * i + (2 * i == n + 1))] + mod) % mod;
			g[i] = (f[i] + g[i + 1]) % mod;
		}
		int cur = 1, inv = 1;
		for(int i = 1; i <= n; i ++) inv = 1ll * inv * ((mod + 1) / 2) % mod;
		for(int i = 1; i <= n; i ++) {
			if(i % 2 == 0) cur = 2ll * cur % mod;
			int ans = 1ll * cur * f[i] % mod;
			if(i == n) ans = (ans + cur) % mod;
			cout << 1ll * ans * inv % mod << '\n';
		}
	}
	return 0;
}