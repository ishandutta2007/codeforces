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

const int N = 101111;
int dp[N][2][2];

void remin(int& x, int y) {
	x = min(x, y);
}

void solve() {
	string s;
	cin >> s;
	const int n = s.size();
	dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int x : {0, 1}) {
			for (int y : {0, 1}) {
				dp[i + 1][x][y] = 1e9;
			}
		}
		for (int x : {0, 1}) {
			for (int y : {0, 1}) {
				for (int z : {0, 1}) {
					if (!(!x && !y && i - 2 >= 0 && s[i - 2] == s[i - 1]) &&
						!(!x && !z && i - 2 >= 0 && s[i - 2] == s[i - 0]) &&
						!(!y && !z && i - 1 >= 0 && s[i - 1] == s[i - 0])) {
						remin(dp[i + 1][y][z], dp[i][x][y] + z);
					}
				}
			}
		}
	}
	cout << min({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}