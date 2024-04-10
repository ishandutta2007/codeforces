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

const int N = 505;
const int mod = 998244353;

long long dp[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int i = 0; i <= n; ++i) {
		dp[i][i] = 1;
	}
	for (int len = 1; len <= n; ++len) {
		for (int l = 0; l + len <= n; ++l) {
			int r = l + len;
			int idx = min_element(a.begin() + l, a.begin() + r) - a.begin();

			long long t1 = 0, t2 = 0;
			for (int i = 0; i <= idx - l; ++i) {
				t1 += dp[l][l + i] * dp[l + i][idx] % mod;
			}
			for (int i = 0; i <= r - idx - 1; ++i) {
				t2 += dp[idx + 1][idx + 1 + i] * dp[idx + 1 + i][r] % mod;
			}
			t1 %= mod;
			t2 %= mod;
			// cerr << l << " " << r << ": " << idx << ", " << t1 << " " << t2 << "\n";
			dp[l][r] = t1 * t2 % mod;
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = i + 1; j <= n; ++j) {
	// 		cerr << dp[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	cout << dp[0][n] << "\n";

	return 0;
}