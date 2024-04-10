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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

inline char opposite(char c) {
	return c == '0' ? '1' : '0';
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), m = nxt(), t = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<pair<int, int>>> comps;
	vector<vector<char>> used(n, vector<char>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j]) {
				continue;
			}
			comps.push_back({});
			used[i][j] = true;
			vector<pair<int, int>> st = {{i, j}};
			while (!st.empty()) {
				auto [x, y] = st.back();
				comps.back().push_back({x, y});
				st.pop_back();
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if (abs(dx) + abs(dy) != 1) {
							continue;
						}
						int nx = x + dx, ny = y + dy;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
							continue;
						}
						if (used[nx][ny]) {
							continue;
						}
						if (a[nx][ny] != a[x][y]) {
							continue;
						}
						used[nx][ny] = true;
						st.push_back({nx, ny});
					}
				}
			}
		}
	}

	vector<vector<int>> d(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	for (const auto& v : comps) {
		if ((int)v.size() <= 1) {
			continue;
		}
		for (const auto& [x, y] : v) {
			q.push({x, y});
			d[x][y] = 0;
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				if (abs(dx) + abs(dy) != 1) {
					continue;
				}
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (d[nx][ny] > -1) {
					continue;
				}
				d[nx][ny] = d[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}

	while (t--) {
		int i = nxt() - 1, j = nxt() - 1;
		long long p;
		cin >> p;

		if (d[i][j] == -1) {
			cout << a[i][j] << "\n";
		} else if (d[i][j] >= p) {
			cout << a[i][j] << "\n";
		} else {
			cout << (p % 2 == d[i][j] % 2 ? a[i][j] : opposite(a[i][j])) << "\n";
		}
	}

	return 0;
}