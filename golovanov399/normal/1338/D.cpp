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

const int N = 111111;
vector<int> a[N];

int dp[N][2];

void remax(int& x, int y) {
	x = max(x, y);
}

int ans = 1;
void dfs(int v, int p) {
	int neigs = a[v].size();
	if (p > -1) {
		--neigs;
	}
	dp[v][0] = neigs;
	dp[v][1] = 1;
	int m2[2][2] = {{0, 0}, {0, 0}};
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		for (int j = 0; j < 2; ++j) {
			if (dp[x][j] > m2[j][0]) {
				m2[j][1] = m2[j][0];
				m2[j][0] = dp[x][j];
			} else if (dp[x][j] > m2[j][1]) {
				m2[j][1] = dp[x][j];
			}
		}
		remax(dp[v][0], neigs - 1 + dp[x][1]);
	}
	remax(dp[v][1], 1 + m2[0][0]);
	remax(ans, 1 + m2[0][0] + m2[0][1]);
	if (neigs >= 2) {
		remax(ans, neigs - 2 + m2[1][0] + m2[1][1] + (p > -1));
	} else if (neigs >= 1) {
		remax(ans, m2[1][0] + (p > -1));
	}
	remax(dp[v][1], dp[v][0]);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(0, -1);
	// for (int j = 0; j < n; ++j) {
	// 	for (int i = 0; i < 5; ++i) {
	// 		cerr << dp[j][i] << " (" << (int)can[j][i] << ") ";
	// 	}
	// 	cerr << "\n";
	// }
	cout << ans << "\n";

	return 0;
}