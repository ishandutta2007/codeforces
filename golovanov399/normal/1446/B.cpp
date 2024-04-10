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

const int N = 5055;
int dp[N][N];

void remax(int& x, int y) {
	x = max(x, y);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	string s, t;
	cin >> s >> t;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i + 1][j + 1] = 4 * (int)(s[i] == t[j]) - 2;
			if (i) {
				remax(dp[i + 1][j + 1], dp[i][j + 1] - 1);
			}
			if (j) {
				remax(dp[i + 1][j + 1], dp[i + 1][j] - 1);
			}
			if (i && j) {
				remax(dp[i + 1][j + 1], dp[i][j] - 2);
				if (s[i] == t[j]) {
					remax(dp[i + 1][j + 1], dp[i][j] + 2);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";

	return 0;
}