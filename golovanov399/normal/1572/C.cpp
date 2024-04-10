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

const int N = 3333;
int dp[N][N];
int dp_simple[N][N];

void solve() {
	int n = nxt();
	vector<int> a(n);
	vector<int> last(n, n);
	vector<int> nx(n, -1);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}
	for (int i = n - 1; i >= 0; --i) {
		nx[i] = last[a[i]];
		last[a[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dp[i][j] = dp_simple[i][j] = 1e9;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		int cur = 1;
		for (int same = i; same < n; same = nx[same]) {
			dp[i][same + 1] = min(dp[i][same + 1], dp_simple[i][same + 1] = cur);
			for (int j = same + 1; j < n; ++j) {
				dp[i][j + 1] = min(dp[i][j + 1], cur + dp[same + 1][j + 1]);
			}
			cur += dp[same + 1][nx[same]];
			for (int k = i; k != nx[same]; k = nx[k]) {
				cur = min(cur, dp_simple[i][k + 1] + dp[k + 1][nx[same]]);
			}
		}
		dp[i][n] = min(dp[i][n], dp_simple[i][n] = cur);
	}
	cout << dp[0][n] - 1 << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}