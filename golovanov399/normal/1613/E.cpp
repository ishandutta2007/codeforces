#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<pair<int, int>> coords;
	vector<vector<int>> g;
	vector<vector<int>> id(n, vector<int>(m, -1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#') {
				continue;
			}
			id[i][j] = g.size();
			g.push_back({});
			coords.push_back({i, j});
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#') {
				continue;
			}
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					if (abs(dx) + abs(dy) != 1) {
						continue;
					}
					int ni = i + dx, nj = j + dy;
					if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, m - 1) != nj) {
						continue;
					}
					if (a[ni][nj] == '#') {
						continue;
					}
					g[id[i][j]].push_back(id[ni][nj]);
				}
			}
		}
	}
	int lab = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'L') {
				lab = id[i][j];
			}
		}
	}
	const int sz = g.size();
	vector<char> used(sz);
	vector<int> rem(sz);
	for (int i = 0; i < sz; ++i) {
		rem[i] = g[i].size();
	}
	vector<int> st = {lab};
	used[lab] = true;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		for (int x : g[v]) {
			--rem[x];
			if (!used[x] && rem[x] <= 1) {
				used[x] = 1;
				st.push_back(x);
			}
		}
	}
	for (int i = 0; i < sz; ++i) {
		if (used[i] && i != lab) {
			auto [x, y] = coords[i];
			a[x][y] = '+';
		}
	}
	for (auto s : a) {
		cout << s << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}