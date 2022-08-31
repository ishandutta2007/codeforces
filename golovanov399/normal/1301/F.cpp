#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 1111;
const int K = 44;
int a[N][N];

signed char cd[N * N];
signed char dist[K][K];
vector<int> by_color[K];
signed char hui_forw[K][N * N];
signed char hui_back[K][N * N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = nxt(), m = nxt(), k = nxt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			by_color[a[i][j] = nxt() - 1].push_back(i * m + j);
		}
	}

	for (int i = 0; i < k; ++i) {
		memset(cd, -1, sizeof(cd));
		deque<int> st = {n * m + i};
		cd[n * m + i] = 0;
		while (!st.empty()) {
			int v = st.front();
			st.pop_front();
			if (v >= n * m) {
				for (int x : by_color[v - n * m]) {
					if (cd[x] == -1) {
						cd[x] = cd[v] + 1;
						st.push_back(x);
					}
				}
			} else {
				int x = v / m, y = v % m;
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if (abs(dx) + abs(dy) != 1) {
							continue;
						}
						if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m) {
							continue;
						}
						int u = (x + dx) * m + (y + dy);
						if (cd[u] == -1) {
							cd[u] = cd[v] + 1;
							st.push_back(u);
						}
					}
				}
				if (cd[n * m + a[x][y]] == -1) {
					cd[n * m + a[x][y]] = cd[v];
					st.push_front(n * m + a[x][y]);
				}
			}
		}
		for (int j = 0; j < k; ++j) {
			dist[i][j] = cd[n * m + j];
		}
		memcpy(hui_forw[i], cd, sizeof(cd));
	}
	for (int i = 0; i < k; ++i) {
		memset(cd, -1, sizeof(cd));
		deque<int> st = {n * m + i};
		cd[n * m + i] = 0;
		while (!st.empty()) {
			int v = st.front();
			st.pop_front();
			if (v >= n * m) {
				for (int x : by_color[v - n * m]) {
					if (cd[x] == -1) {
						cd[x] = cd[v];
						st.push_front(x);
					}
				}
			} else {
				int x = v / m, y = v % m;
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if (abs(dx) + abs(dy) != 1) {
							continue;
						}
						if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m) {
							continue;
						}
						int u = (x + dx) * m + (y + dy);
						if (cd[u] == -1) {
							cd[u] = cd[v] + 1;
							st.push_back(u);
						}
					}
				}
				if (cd[n * m + a[x][y]] == -1) {
					cd[n * m + a[x][y]] = cd[v] + 1;
					st.push_back(n * m + a[x][y]);
				}
			}
		}
		memcpy(hui_back[i], cd, sizeof(cd));
	}

	int q = nxt();
	while (q--) {
		int x1 = nxt() - 1, y1 = nxt() - 1, x2 = nxt() - 1, y2 = nxt() - 1;
		int u = x1 * m + y1;
		int v = x2 * m + y2;
		int ans = abs(x1 - x2) + abs(y1 - y2);
		for (int c1 = 0; c1 < k; ++c1) {
			for (int c2 = 0; c2 < k; ++c2) {
				ans = min<int>(ans, (int)dist[c1][c2] + hui_forw[c2][v] + hui_back[c1][u]);
			}
		}
		cout << (int)ans << "\n";
	}

	return 0;
}