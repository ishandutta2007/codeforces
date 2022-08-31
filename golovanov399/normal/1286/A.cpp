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

const int N = 111;
int dp[N][N / 2][N / 2][3];

void remin(int& x, int y) {
	if (y == -1) {
		return;
	}
	if (x == -1 || x > y) {
		x = y;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int can_odd = (n + 1) / 2, can_even = n / 2;
	for (int x : a) {
		if (x) {
			if (x % 2) {
				--can_odd;
			} else {
				--can_even;
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[0][can_odd][can_even][2] = 0;
	for (int i = 0; i < n; ++i) {
		for (int co = 0; co <= can_odd; ++co) {
			for (int ce = 0; ce <= can_even; ++ce) {
				for (int p = 0; p < 3; ++p) {
					if (dp[i][co][ce][p] == -1) {
						continue;
					}
					if (a[i]) {
						remin(dp[i + 1][co][ce][a[i] % 2], dp[i][co][ce][p] + (a[i] % 2 != p));
					} else {
						if (co) {
							remin(dp[i + 1][co - 1][ce][1], dp[i][co][ce][p] + (1 != p));
						}
						if (ce) {
							remin(dp[i + 1][co][ce - 1][0], dp[i][co][ce][p] + (0 != p));
						}
					}
				}
			}
		}
	}

	int ans = -1;
	remin(ans, dp[n][0][0][0]);
	remin(ans, dp[n][0][0][1]);
	cout << ans - 1 << "\n";

	return 0;
}