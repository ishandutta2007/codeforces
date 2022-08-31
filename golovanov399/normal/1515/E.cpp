#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 404;
int mod;
int inv[N];
int dp[2][N][N];

void add(int& x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int prod(int x, int y) {
	return 1ll * x * y % mod;
}

void solve() {
	int n = nxt();
	mod = nxt();
	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod;
	}
	dp[0][1][1] = 1;
	for (int i = 1; i < n; ++i) {
		int t = i % 2;
		memset(dp[t], 0, sizeof(dp[t]));
		for (int cnt = 1; cnt <= i; ++cnt) {
			for (int last = 0; last <= cnt; ++last) {
				add(dp[t][cnt + 1][last + 1], prod(dp[t ^ 1][cnt][last], prod((cnt + 1) * (last ? 2 : 1), inv[last + 1])));
				if (last) {
					add(dp[t][cnt][0], dp[t ^ 1][cnt][last]);
				}
			}
		}
	}
	int ans = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		for (int last = 1; last <= cnt; ++last) {
			add(ans, dp[(n - 1) % 2][cnt][last]);
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}