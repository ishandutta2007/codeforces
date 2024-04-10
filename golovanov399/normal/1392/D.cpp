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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 222222;
int dp[N][2][2];

void relax(int& x, int y) {
	if (x == -1) {
		x = y;
	} else {
		x = min(x, y);
	}
}

void fill_dp(const vector<int>& a, int c) {
	const int n = a.size();
	memset(dp[1], -1, sizeof(dp[1]));
	dp[1][c][0] = (c != a[0]);
	for (int i = 1; i < n; ++i) {
		memset(dp[i + 1], -1, sizeof(dp[i + 1]));
		for (int p : {0, 1}) {
			for (int cn : {0, 1}) {
				if (dp[i][p][cn] == -1) {
					continue;
				}
				for (int nw : {0, 1}) {
					if (p == nw && cn) {
						continue;
					}
					relax(dp[i + 1][nw][p == nw ? cn + 1 : 0], dp[i][p][cn] + (nw != a[i]));
					// cerr << "dp[" << i + 1 << "][" << nw << "][" << (p == nw ? cn + 1 : 0) << "] = " << dp[i + 1][nw][p == nw ? cn + 1 : 0] << "\n";
				}
			}
		}
	}
}

void solve() {
	int n = nxt();
	string s;
	cin >> s;
	int ans = n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (s[i] == 'R');
	}
	for (int c : {0, 1}) {
		for (int lcnt : {0, 1}) {
			for (int rcnt : {0, 1}) {
				if (lcnt && rcnt) {
					continue;
				}
				auto b = a;
				b.erase(b.begin());
				int cur = (c != a[0]);
				if (rcnt) {
					cur += (c != b[0]);
					b.erase(b.begin());
				}
				if (lcnt) {
					cur += (c != b.back());
					b.pop_back();
				}

				fill_dp(b, !c);
				int tmp = -1;
				if (~dp[n - 1 - lcnt - rcnt][!c][0]) {
					relax(tmp, dp[n - 1 - lcnt - rcnt][!c][0]);
				}
				if (~dp[n - 1 - lcnt - rcnt][!c][1]) {
					relax(tmp, dp[n - 1 - lcnt - rcnt][!c][1]);
				}
				cur += tmp;

				ans = min(ans, cur);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// fill_dp({0, 1, 0, 0}, 1);
	// cerr << dp[4][0][0] << "\n";
	// return 0;

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}