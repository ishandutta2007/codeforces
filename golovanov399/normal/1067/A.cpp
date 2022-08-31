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
const int N = 111111;
const int M = 200;
long long dp[2][M + 1][2];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	if (a[0] == -1) {
		for (int i = 1; i <= M; ++i) {
			dp[0][i][0] = 1;
		}
	} else {
		dp[0][a[0]][0] = 1;
	}

	int t = 1;
	for (int i = 1; i < n; ++i) {
		long long cur = 0;
		for (int j = 1; j <= M; ++j) {
			dp[t][j][0] = (a[i] == -1 || a[i] == j) ? cur : 0;
			cur += dp[t ^ 1][j][0] + dp[t ^ 1][j][1];
			while (cur >= mod) {
				cur -= mod;
			}
		}
		cur = 0;
		for (int j = M; j >= 1; --j) {
			cur += dp[t ^ 1][j][1];
			while (cur >= mod) {
				cur -= mod;
			}
			dp[t][j][1] = (a[i] == -1 || a[i] == j) ? cur + dp[t ^ 1][j][0] : 0;
			if (dp[t][j][1] >= mod) {
				dp[t][j][1] -= mod;
			}
		}
		t ^= 1;
	}
	t ^= 1;
	long long ans = 0;
	for (int i = 1; i <= M; ++i) {
		ans += dp[t][i][1];
	}
	cout << ans % mod << "\n";

	return 0;
}