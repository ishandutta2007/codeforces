#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int a[3010];
int dp[3010][3010];
int val[3010][3010], D[3010][3010];
int f[3010][512], nf[3010][512];
long long pw[3010], pinv[3010];
int n, m;

struct SEQ {
	int cnt[3010], zero;
	long long mul;
	void clear() {
		for (int i = 1; i <= m; i++) {
			cnt[i] = 0;
		}
		zero = m, mul = 0;
	}
	void add(int x) {
		if (zero == 0) {
			mul = mul * pinv[cnt[x]] % mod * (pw[cnt[x] + 1] - 1 + mod) % mod;
			cnt[x]++;
			return ;
		}
		cnt[x]++;
		if (cnt[x] == 1) zero--;
		if (zero == 0) {
			mul = 1;
			for (int i = 1; i <= m; i++) {
				mul = mul * (pw[cnt[i]] - 1 + mod) % mod;
			}
		}
	}
}seq;

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int ans[3010];

void add(int &x, int y) {
	x += y - mod, x += x >> 31 & mod;
}

int main() {
	pw[0] = 1;
	for (int i = 1; i <= 3005; i++) {
		pw[i] = pw[i - 1] * 2 % mod;
		pinv[i] = power(pw[i] - 1, mod - 2);
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m < 10) {
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int V = 1 << a[i] - 1;
			for (int j = 0; j <= n / m; j++) {
				for (int mask = 0; mask < (1 << m); mask++) {
					nf[j][mask] = f[j][mask];
				}
			}
			for (int j = 0; j <= n / m; j++) {
				for (int mask = 0; mask < (1 << m); mask++) {
					if (!f[j][mask]) continue;
					if ((mask | V) != (1 << m) - 1) add(nf[j][mask | V], f[j][mask]);
					else add(nf[j + 1][0], f[j][mask]);
				}
			}
			for (int j = 0; j <= n / m; j++) {
				for (int mask = 0; mask < (1 << m); mask++) {
					f[j][mask] = nf[j][mask];
				}
			}
		}
		for (int j = 0; j <= n; j++) {
			long long ans = 0;
			for (int mask = 0; mask < (1 << m); mask++) {
				ans = (ans + f[j][mask]) % mod;
			}
			if (!j) ans = (ans - 1 + mod) % mod;
			cout << ans << " ";
		}
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		seq.clear();
		for (int j = i; j <= n; j++) {
			seq.add(a[j]);
			D[i][j] = seq.mul * pinv[seq.cnt[a[j]]] % mod;
			val[i][j] = seq.mul;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!dp[i][j]) continue;
			for (int ni = i + 1; ni <= n; ni++) {
				dp[ni][j + 1] = (dp[ni][j + 1] + 1ll * dp[i][j] * D[i + 1][ni]) % mod;
			}
		}
	}
	for (int j = 0; j <= n; j++) {
		long long ans = dp[n][j];
		for (int i = 0; i < n; i++) {
			ans = (ans + 1ll * dp[i][j] * (pw[n - i] - val[i + 1][n] + mod)) % mod;
		}
		if (!j) ans = (ans - 1 + mod) % mod;
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}