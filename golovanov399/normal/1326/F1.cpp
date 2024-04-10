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

const int L = 7;
const int M = 1 << (L - 1);
const int N = 1 << (L * 2);
long long dp[N][2 * L][M];
int rev[M];
long long ans[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int left = n / 2, right = (n + 1) / 2;
	const int nn = 1 << n;
	for (int mask = 1; mask < nn; ++mask) {
		int cn = __builtin_popcount(mask);
		if (cn == 1) {
			dp[mask][__builtin_ctz(mask)][0] = 1;
		}
		if (cn > right - 1) {
			continue;
		}
		for (int i = 0; i < n; ++i) {
			if (!(mask & (1 << i))) {
				continue;
			}
			for (int j = 0; j < n; ++j) {
				if (!(mask & (1 << j))) {
					for (int m = 0; m < (1 << (cn - 1)); ++m) {
						// if (dp[mask][i][m]) {
						// 	cerr << "dp[" << mask << "][" << i << "][" << m << "] = " << dp[mask][i][m] << "\n";
						// }
						dp[mask | (1 << j)][j][m * 2 + a[i][j] - '0'] += dp[mask][i][m];
					}
				}
			}
		}
	}
	for (int i = 0; i < (1 << (left - 1)); ++i) {
		for (int j = 0; j < left - 1; ++j) {
			if (i & (1 << j)) {
				rev[i] |= 1 << (left - 2 - j);
			}
		}
	}

	for (int mask_l = 0; mask_l < nn; ++mask_l) {
		if (__builtin_popcount(mask_l) != left) {
			continue;
		}
		int mask_r = (nn - 1) ^ mask_l;
		for (int i = 0; i < n; ++i) {
			if (mask_r & (1 << i)) {
				continue;
			}
			for (int j = 0; j < n; ++j) {
				if (mask_l & (1 << j)) {
					continue;
				}
				int c = ((int)(a[i][j] - '0')) << (left - 1);
				for (int m1 = 0; m1 < (1 << (left - 1)); ++m1) {
					for (int m2 = 0; m2 < (1 << (right - 1)); ++m2) {
						// if (dp[mask_l][i][m1] && dp[mask_r][j][m2]) {
						// 	cerr << "dp[" << mask_l << "][" << i << "][" << m1 << "] * dp[" << mask_r << "][" << j << "][" << m2 << "]\n";
						// }
						ans[rev[m1] | c | (m2 << left)] += dp[mask_l][i][m1] * dp[mask_r][j][m2];
					}
				}
			}
		}
	}

	for (int i = 0; i < nn / 2; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}