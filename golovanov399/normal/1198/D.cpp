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

const int N = 55;
int dp[N][N][N][N];
int a[N][N];

inline int getcnt(int x1, int y1, int x2, int y2) {
	return a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1];
}

int rec(int x1, int y1, int x2, int y2) {
	if (dp[x1][y1][x2][y2] > -1) {
		return dp[x1][y1][x2][y2];
	}
	if (x1 >= x2 || y1 >= y2) {
		return 0;
	}
	int& res = dp[x1][y1][x2][y2] = max(x2 - x1, y2 - y1);
	if (x2 - x1 > y2 - y1) {
		for (int i = x1; i < x2; ++i) {
			if (getcnt(i, y1, i + 1, y2) == 0) {
				res = min(res, rec(x1, y1, i, y2) + rec(i + 1, y1, x2, y2));
			}
		}
	} else {
		for (int i = y1; i < y2; ++i) {
			if (getcnt(x1, i, x2, i + 1) == 0) {
				res = min(res, rec(x1, y1, x2, i) + rec(x1, i + 1, x2, y2));
			}
		}
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<string> field(n);
	for (int i = 0; i < n; ++i) {
		cin >> field[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i + 1][j + 1] = a[i][j + 1] + a[i + 1][j] - a[i][j] + (field[i][j] == '#');
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0, n, n) << "\n";

	return 0;
}