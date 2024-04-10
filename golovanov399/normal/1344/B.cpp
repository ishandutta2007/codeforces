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

void panic() {
	cout << "-1\n";
	exit(0);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	bool exists_white_row = false;
	bool exists_white_col = false;
	for (int i = 0; i < n; ++i) {
		int state = 0;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#') {
				if (state % 2 == 0) {
					++state;
				}
			} else {
				if (state % 2 == 1) {
					++state;
				}
			}
		}
		if (state > 2) {
			panic();
		}
		if (state == 0) {
			exists_white_row = true;
		}
	}
	for (int j = 0; j < m; ++j) {
		int state = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i][j] == '#') {
				if (state % 2 == 0) {
					++state;
				}
			} else {
				if (state % 2 == 1) {
					++state;
				}
			}
		}
		if (state > 2) {
			panic();
		}
		if (state == 0) {
			exists_white_col = true;
		}
	}

	if (exists_white_row ^ exists_white_col) {
		panic();
	}

	int ans = 0;
	vector<vector<char>> used(n, vector<char>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j] || a[i][j] == '.') {
				continue;
			}
			vector<pair<int, int>> st = {{i, j}};
			used[i][j] = true;
			++ans;
			while (!st.empty()) {
				auto [x, y] = st.back();
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
						if (used[nx][ny] || a[nx][ny] != '#') {
							continue;
						}
						st.push_back({nx, ny});
						used[nx][ny] = true;
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}