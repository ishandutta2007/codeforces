#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

int n, m;

int f(int i, int j) {
	return i * m + j;
}

vector<vector<pair<int, int>>> g;
vector<vector<char>> a;

void AddEdge(int u, int v, int w) {
	if (a[v / m][v % m] == '#') {
		return;
	}
	g[v].emplace_back(u, w);
}

const ll INF = 1e18;

int main() {
	cin >> n >> m;
	int p, q;
	cin >> p >> q;
	a.resize(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	g.resize(n * m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.' || a[i][j] == '#') {
				continue;
			}
			if (a[i][j] == 'L') {
				if (i - 1 >= 0 && j + 1 < m) {
					AddEdge(f(i, j), f(i - 1, j + 1), p);
				}
				if (i + 1 < n && j + 1 < m) {
					AddEdge(f(i, j), f(i + 1, j + 1), p);
				}
				if (j + 2 < m) {
					AddEdge(f(i, j), f(i, j + 2), q);
				}
			} else if (a[i][j] == 'R') {
				if (i - 1 >= 0 && j - 1 >= 0) {
					AddEdge(f(i, j), f(i - 1, j - 1), p);
				}
				if (i + 1 < n && j - 1 >= 0) {
					AddEdge(f(i, j), f(i + 1, j - 1), p);
				}
				if (j - 2 >= 0) {
					AddEdge(f(i, j), f(i, j - 2), q);
				}
			} else if (a[i][j] == 'U') {
				if (i + 1 < n && j - 1 >= 0) {
					AddEdge(f(i, j), f(i + 1, j - 1), p);
				}
				if (i + 1 < n && j + 1 < m) {
					AddEdge(f(i, j), f(i + 1, j + 1), p);
				}
				if (i + 2 < n) {
					AddEdge(f(i, j), f(i + 2, j), q);
				}
			} else if (a[i][j] == 'D') {
				if (i - 1 >= 0 && j - 1 >= 0) {
					AddEdge(f(i, j), f(i - 1, j - 1), p);
				}
				if (i - 1 >= 0 && j + 1 < m) {
					AddEdge(f(i, j), f(i - 1, j + 1), p);
				}
				if (i - 2 >= 0) {
					AddEdge(f(i, j), f(i - 2, j), q);
				}
			}
		}
	}
	vector<ll> d(n * m, INF);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.') {
				d[f(i, j)] = 0;
			}
		}
	}
	set<pair<ll, int>> x;
	for (int i = 0; i < n * m; ++i) {
		x.insert({d[i], i});
	}
	while (!x.empty()) {
		int v = x.begin()->second;
		x.erase(x.begin());
		for (auto& now : g[v]) {
			int u = now.first;
			int w = now.second;
			if (d[v] + w < d[u]) {
				x.erase({d[u], u});
				d[u] = d[v] + w;
				x.insert({d[u], u});
			}
		}
	}
	/*
	for (int v = 0; v < n * m; ++v) {
		if (g[v].empty()) {
			continue;
		}
		cout << "(" << v / m << ", " << v % m << "): ";
		for (auto& now : g[v]) {
			int ux = now.first / m;
			int uy = now.first % m;
			cout << "(" << ux << ", " << uy << ") ";
		}
		cout << endl;
	}
	 */
	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + 1 < m; ++j) {
			if (a[i][j] == 'L' && a[i][j + 1] == 'R') {
				continue;
			}
			ans = min(ans, d[f(i, j)] + d[f(i, j + 1)]);
		}
	}
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'U' && a[i + 1][j] == 'D') {
				continue;
			}
			ans = min(ans, d[f(i, j)] + d[f(i + 1, j)]);
		}
	}
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[f(i, j)] == INF) {
				cout << "x ";
			} else {
				cout << d[f(i, j)] << ' ';
			}
		}
		cout << endl;
	}
	 */
	if (ans == INF) {
		ans = -1;
	}
	cout << ans;
	return 0;
}