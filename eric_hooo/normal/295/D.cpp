#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int f[2010][2010], g[2010][2010];

int main () {
	int n, m; cin >> n >> m;
	for (int i = 2; i <= m; i++) {
		f[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		long long s1 = 0, s2 = 0;
		for (int j = 2; j <= m; j++) {
			s1 = (s1 + f[i - 1][j]) % mod, s2 = (s2 + 1ll * f[i - 1][j] * j) % mod;
			f[i][j] = ((j + 1) * s1 - s2 + mod) % mod;
		}
	}
	for (int j = 2; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			ans = (ans + 1ll * f[i][j] * g[n - i + 1][j] % mod * (m - j + 1)) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}