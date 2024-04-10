#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const itn N = 1011111;
const int K = 2;

int dp[N][3 * K + 1][3 * K + 1];
int cnt[N];

void remax(int& x, int y) {
	x = max(x, y);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		cnt[nxt() - 1] += 1;
	}

	memset(dp, -1, sizeof(dp));

	m += 10;

	dp[0][0][0] = dp[1][0][0] = 0;
	for (int i = 2; i < m; ++i) {
		for (int i1 = 0; i1 <= 3 * K; ++i1) {
			for (int j1 = 0; j1 <= 3 * K; ++j1) {
				if (dp[i - 1][i1][j1] < 0) {
					continue;
				}
				for (int k = 0; k <= K; ++k) {
					if (k > cnt[i]) continue;
					if (j1 + k > cnt[i - 1]) continue;
					if (i1 + k > cnt[i - 2]) continue;
					remax(dp[i][j1 + k][k], dp[i - 1][i1][j1] + (cnt[i - 2] - i1 - k) / 3 + k);
				}
			}
		}
	}

	cout << dp[m - 1][0][0] << "\n";

	return 0;
}