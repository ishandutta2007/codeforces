#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;
const int N = 3844;
long long dp[2][N][N];
char banned[2][N];

void fill_dp(int t, int n) {
	dp[t][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		memcpy(dp[t][i], dp[t][i - 1], sizeof(long long) * (n + 1));
		if (i > 1 && !banned[t][i] && !banned[t][i - 1]) {
			for (int j = 0; j < n; ++j) {
				dp[t][i][j + 1] += dp[t][i - 2][j];
				if (dp[t][i][j + 1] >= mod) {
					dp[t][i][j + 1] -= mod;
				}
			}
		}
	}
}

long long inv[N], fact[N], invfact[N];

long long notC(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return fact[n] * invfact[n - k] % mod;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	int h = nxt(), w = nxt();
	int n = nxt();
	for (int i = 0; i < 2 * n; ++i) {
		int x = nxt(), y = nxt();
		banned[0][x] = banned[1][y] = 1;
	}
	int not_banned[2] = {0, 0};
	for (int i = 0; i < h; ++i) {
		not_banned[0] += !banned[0][i + 1];
	}
	for (int i = 0; i < w; ++i) {
		not_banned[1] += !banned[1][i + 1];
	}

	fill_dp(0, h);
	fill_dp(1, w);

	long long ans = 0;
	for (int a = 0; a <= h; ++a) {
		for (int b = 0; b <= w; ++b) {
			ans += dp[0][h][a] * dp[1][w][b] % mod * notC(not_banned[0] - 2 * a, b) % mod * notC(not_banned[1] - 2 * b, a) % mod;
			// if (dp[0][h][a] * dp[1][w][b] % mod * notC(not_banned[0] - 2 * a, b) % mod * notC(not_banned[1] - 2 * b, a) % mod) {
			// 	cerr << a << " " << b << ": " << dp[0][h][a] * dp[1][w][b] % mod * notC(not_banned[0] - 2 * a, b) % mod * notC(not_banned[1] - 2 * b, a) % mod << " " <<
			// 			dp[0][h][a] << " " << dp[1][w][b] << " " << notC(not_banned[0] - 2 * a, b) << " " << notC(not_banned[1] - 2 * b, a) << "\n";
			// }
		}
	}

	cout << ans % mod << "\n";

	return 0;
}