#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

const vector<pair<int, int>> dirs = []() {
	vector<pair<int, int>> res;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			res.push_back({i, j});
		}
	}
	return res;
}();

int f(int x1, int y1, int x2, int y2) {
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	if (!dx && !dy) {
		return 0;
	} else if (dx % 2 || dy % 2) {
		return -1;
	} else {
		return 1;
	}
}

void solve() {
	int n = nxt();
	vector<vector<int>> a(4, vector<int>(4));
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		int x = nxt(), y = nxt();
		v[i] = {x, y};
		x %= 4, y %= 4;
		a[x][y] += 1;
	}
	// inner = area - boundary / 2
	// boundary = sum(gcd(dx, dy))
	long long ans = 0;
	for (auto [x1, y1] : dirs) {
		for (auto [x2, y2] : dirs) {
			for (auto [x3, y3] : dirs) {
				int area = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
				area %= 4;
				if (area < 0) {
					area += 4;
				}
				if (area % 2) {
					continue;
				}
				area /= 2;
				bool ok = true;
				if (auto t = f(x1, y1, x2, y2); t > -1) {
					area ^= t;
				} else {
					ok = false;
				}
				if (auto t = f(x2, y2, x3, y3); t > -1) {
					area ^= t;
				} else {
					ok = false;
				}
				if (auto t = f(x3, y3, x1, y1); t > -1) {
					area ^= t;
				} else {
					ok = false;
				}
				if (!ok) {
					continue;
				}
				if (!area) {
					// cerr << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";
					long long tmp = 1;
					tmp *= a[x1][y1]--;
					tmp *= a[x2][y2]--;
					tmp *= a[x3][y3]--;
					ans += tmp;
					++a[x3][y3];
					++a[x2][y2];
					++a[x1][y1];
				}
			}
		}
	}
	ans /= 3;
	int p[4][4][4];
	for (int i = 0; i < n; ++i) {
		memset(p, 0, sizeof(p));
		for (int j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			int g = gcd(abs(v[j].first - v[i].first), abs(v[j].second - v[i].second));
			p[g % 4][v[j].first % 4][v[j].second % 4] += 1;
		}
		int x1 = v[i].first % 4;
		int y1 = v[i].second % 4;
		for (auto [x2, y2] : dirs) {
			for (auto [x3, y3] : dirs) {
				int area = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
				area %= 4;
				if (area < 0) {
					area += 4;
				}
				if (area % 2) {
					continue;
				}
				area /= 2;
				if (auto t = f(x2, y2, x3, y3); t == -1) {
					continue;
				} else {
					area -= t;
				}
				if ((area + 2) % 2) {
					ans += p[1][x2][y2] * (p[1][x3][y3] - (x2 == y2 && x3 == y3 ? 1 : 0));
					ans += p[3][x2][y2] * (p[3][x3][y3] - (x2 == y2 && x3 == y3 ? 1 : 0));
				} else {
					ans += p[1][x2][y2] * p[3][x3][y3];
					ans += p[3][x2][y2] * p[1][x3][y3];
				}
			}
		}
	}
	cout << ans / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}