#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ld float
#define all(a) (a).begin(), (a).end()

struct point {
	ld x, y;
	point() {}
	point(ld x_, ld y_) {
		x = x_;
		y = y_;
	}
	point(point a, point b, int ma, int mb) {
		x = (a.x * ma + b.x * mb) / (ma + mb);
		y = (a.y * ma + b.y * mb) / (ma + mb);
	}
};

const ld eps = 1e-5;

bool operator<(point a, point b) {
	if (abs(a.x - b.x) < eps) {
		return a.y < b.y;
	} else {
		return a.x < b.x;
	}
}

bool operator==(point a, point b) {
	return abs(a.x - b.x) < eps && abs(a.y - b.y) < eps;
}

const int maxn = 37;
// 748
const int maxm = 650;

vector<point> dp[maxn][maxn][maxm];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0][0][0] = {point(0, 0)};

	int n;
	cin >> n;

	ld x, y;
	cin >> x >> y;
	point ans = point(x, y);


	for (int i = 0; i < n; i++) {
		for (int b = 0; b <= n / 2; b++) {
			for (int m = 0; m < maxm; m++) {
				sort(all(dp[i][b][m]));
				dp[i][b][m].resize(unique(all(dp[i][b][m])) - dp[i][b][m].begin());

				if (b > 0) {
					point p1 = point(point(i + (ld)1 / 3, b - 1 + (ld)1 / 3), point(i + 0.5, (ld)(b - 1) / 2), 1, (b - 1) * 2);
					int mas = 1 + (b - 1) * 2;
					// down
					for (auto p : dp[i][b][m]) {
						dp[i + 1][b - 1][m + mas].push_back(point(p1, p, mas, m));
					}
				}
				if (n - i > b + 1) {
					// up
					point p1 = point(point(i + (ld)2 / 3, b + (ld)1 / 3), point(i + 0.5, (ld)(b) / 2), 1, (b) * 2);
					int mas = 1 + b * 2;

					for (auto p : dp[i][b][m]) {
						dp[i + 1][b + 1][m + mas].push_back(point(p1, p, mas, m));
					}
				}
				// dp[i][b][m].clear();
			}
		}
	}

	pii pp = {-1, -1};
	point f = ans;
	for (int m = 0; m < maxm; m++) {
		for (auto p : dp[n][0][m]) {
			if (p == ans) {
				pp = {0, m};
				// cout << "found " << m << '\n';
			}
		}
	}
	if (pp == (pii){-1, -1}) {
		assert(0);
	}

	vector<int> a(n);

	for (int i = n - 1; i >= 0; i--) {
		pii pp1;
		point f1 = point(0, 0);
		for (int b = 0; b <= n / 2; b++) {
			if (b - 1 != pp.first && b + 1 != pp.first) continue;
			for (int m = 0; m < maxm; m++) {
				if (b > 0) {
					int mas = 1 + (b - 1) * 2;
					// down
					if (b - 1 == pp.first && m + mas == pp.second) {
						point p1 = point(point(i + (ld)1 / 3, b - 1 + (ld)1 / 3), point(i + 0.5, (ld)(b - 1) / 2), 1, (b - 1) * 2);
					
						for (auto p : dp[i][b][m]) {
							point p2 = point(p1, p, mas, m);
							if (p2 == f) {
								pp1 = {b, m};
								f1 = p;
							}
						}
					}

				}
				if (n - i > b + 1) {
					// up
					int mas = 1 + b * 2;

					if (b + 1 == pp.first && m + mas == pp.second) {
						point p1 = point(point(i + (ld)2 / 3, b + (ld)1 / 3), point(i + 0.5, (ld)(b) / 2), 1, (b) * 2);
					
						for (auto p : dp[i][b][m]) {
							point p2 = point(p1, p, mas, m);
							if (p2 == f) {
								pp1 = {b, m};
								f1 = p;
							}
						}
					}
				}
			}
		}

		a[i] = pp.first - pp1.first;
		pp = pp1;
		f = f1;
	}

	for (auto i : a) {
		if (i == 1) {
			cout << "(";
		} else {
			cout << ")";
		}
	}
	cout << '\n';


	return 0;
}