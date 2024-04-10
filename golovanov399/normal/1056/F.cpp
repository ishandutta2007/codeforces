#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

double dp[1111][111][111];
char used[1111][111][111];
char timer = 0;

double qw[1111];

void relax(int i, int j, int k, double val) {
	if (timer != used[i][j][k] || dp[i][j][k] > val) {
		used[i][j][k] = timer;
		dp[i][j][k] = val;
	}
}

void solve() {
	++timer;
	int n;
	cin >> n;
	double c, T;
	cin >> c >> T;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
	}
	sort(all(a));
	reverse(all(a));

	relax(0, 0, 0, 0);
	for (int i = 0; i < n; ++i) {
		for (int cnt = 0; cnt <= i; ++cnt) {
			for (int sc = cnt * 1; sc <= cnt * 10; ++sc) {
				if (used[sc][i][cnt] == timer) {
					relax(sc, i + 1, cnt, dp[sc][i][cnt]);
					relax(sc + a[i].second, i + 1, cnt + 1, dp[sc][i][cnt] + a[i].first * qw[cnt]);
				}
			}
		}
	}

	int ans = 0;
	for (int sc = 0; sc < 1111; ++sc) {
		for (int cn = 0; cn < 111; ++cn) {
			if (used[sc][n][cn] != timer) {
				continue;
			}

			double t = sqrt(dp[sc][n][cn] / c) - 1/c;
			if (t < 0) {
				t = 0;
			}
			if (t + 10 * cn + dp[sc][n][cn] / (1 + c * t) <= T) {
				// cerr << t + 10 * cn + dp[sc][n][cn] / (1 + c * t) << " !!\n";
				// cerr << ans << " -> " << sc << ": " << t << " (" << cn << ")\n";
				ans = max(ans, sc);
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);

	qw[0] = 1 / 0.9;
	for (int i = 1; i < 1111; ++i) {
		qw[i] = qw[i - 1] / 0.9;
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}