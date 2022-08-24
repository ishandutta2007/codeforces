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

struct Restriction {
	int l, r, x, c;

	bool operator <(const Restriction& ot) const {
		return x < ot.x;
	}
};

void remax(int& x, int y) {
	x = max(x, y);
}

const int N = 55;
int dp[N][N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), h = nxt(), m = nxt();
	vector<Restriction> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i].l >> a[i].r >> a[i].x >> a[i].c;
		a[i].l -= 1;
	}
	sort(all(a));

	for (int len = 1; len <= n; ++len) {
		for (int l = 0; l + len <= n; ++l) {
			int r = l + len;
			for (int hh = h; hh >= 0; --hh) {
				for (int i = l; i < r; ++i) {
					for (int h1 = 0; h1 <= hh; ++h1) {
						int penalty = 0;
						for (const auto& res : a) {
							if (res.x >= h1) {
								break;
							} else if (i >= res.l && i < res.r && res.l >= l && res.r <= r) {
								penalty += res.c;
							}
						}
						remax(dp[l][r][hh], dp[l][i][h1] + dp[i + 1][r][h1] + h1 * h1 - penalty);
					}
				}
			}
		}
	}

	cout << dp[0][n][h] << "\n";

	return 0;
}