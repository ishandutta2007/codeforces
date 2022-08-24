#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 5555;
int dp[N][N][3];

// 0 -- nothing
// 1 -- is fucking neighbors
// 2 -- is fucked by the previous neighbor

void remin(int& x, int y) {
	x = min(x, y);
}

int dst(int fr, int to) {
	if (to > fr) {
		return 0;
	} else {
		return fr - to + 1;
	}
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int& x : a) {
		x = nxt();
	}
	a.push_back(-100000);
	a.insert(a.begin(), -100000);

	const int inf = 2e9;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[i][j][k] = inf;
			}
		}
	}

	memset(dp[0][0], 0, sizeof(dp[0][0]));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			// last guy did nothing
			remin(dp[i][j][0], dp[i - 1][j][0]);
			remin(dp[i][j + 1][1], dp[i - 1][j][0] + dst(a[i - 1], a[i]));
			// last guy fucked us
			if (i >= 1) {
				remin(dp[i][j][2], dp[i - 1][j][1] + dst(a[i], a[i - 1]));
			}
			// last guy is fucked anyway
			if (i >= 2) {
				remin(dp[i][j][0], dp[i - 1][j][2]);
				remin(dp[i][j + 1][1], dp[i - 1][j][2] + dst(min(a[i - 1], a[i - 2] - 1), a[i]));
			}
		}
	}

	vector<int> ans((n + 1) / 2 + 1);
	for (int i = 0; i <= (n + 1) / 2; ++i) {
		ans[i] = *min_element(dp[n][i], dp[n][i] + 3);
	}

	for (int i = 1; i <= (n + 1) / 2; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}