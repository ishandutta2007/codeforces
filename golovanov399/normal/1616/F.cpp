#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int u, v;
	int c;
};

void divide(int& a, int b) {
	if (b == 2) {
		a = a ? 3 - a : 0;
	}
}

void mul(int& a, int b) {
	a *= b;
	if (a >= 3) {
		a -= 3;
	}
}

optional<vector<int>> solve_linear(vector<vector<int>> a, vector<int> b) {
	int n = a.size();
	int m = a[0].size();
	vector<int> main_coords;
	int i = 0;
	for (int col = 0; i < n && col < m; ++col) {
		if (a[i][col] == 0) {
			int j = i + 1;
			while (j < n && a[j][col] == 0) {
				++j;
			}
			if (j == n) {
				continue;
			}
			a[j].swap(a[i]);
			swap(b[j], b[i]);
		}

		{
			int k = a[i][col];
			for (int j = col; j < m; ++j) {
				divide(a[i][j], k);
			}
			divide(b[i], k);
		}
		for (int j = i + 1; j < n; ++j) {
			int k = a[j][col];
			if (k != 0) {
				for (int l = col; l < m; ++l) {
					a[j][l] -= a[i][l] * k;
					while (a[j][l] < 0) {
						a[j][l] += 3;
					}
				}
				b[j] -= b[i] * k;
				while (b[j] < 0) {
					b[j] += 3;
				}
			}
		}
		main_coords.push_back(col);
		++i;
	}

	for (int row = i; row < n; ++row) {
		if (b[row] != 0) {
			return nullopt;
		}
	}
	n = i;
	a.resize(n);
	b.resize(n);

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			const int col = main_coords[i];
			int k = a[j][col];
			if (k != 0) {
				for (int l = 0; l < m; ++l) {
					a[j][l] -= a[i][l] * k;
					while (a[j][l] < 0) {
						a[j][l] += 3;
					}
				}
				b[j] -= b[i] * k;
				while (b[j] < 0) {
					b[j] += 3;
				}
			}
		}
	}

	vector<int> ans(m);
	for (int i = 0; i < (int)main_coords.size(); ++i) {
		ans[main_coords[i]] = b[i];
	}
	return ans;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<Edge> edges;
	vector<vector<int>> g(n, vector<int>(n, -1));
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		int c = nxt() - 1;
		if (c < 0) {
			c = -1;
		}
		g[u][v] = g[v][u] = i;
		edges.push_back({u, v, c});
	}

	vector<vector<int>> a;
	vector<int> b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
				if (min({g[i][j], g[j][k], g[k][i]}) > -1) {
					a.emplace_back(m, 0);
					b.push_back(0);
					a.back()[g[i][j]] = a.back()[g[j][k]] = a.back()[g[k][i]] = 1;
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		if (edges[i].c > -1) {
			a.emplace_back(m, 0);
			b.push_back(edges[i].c);
			a.back()[i] = 1;
		}
	}

	if (a.empty()) {
		for (int i = 0; i < m; ++i) {
			cout << 1 << " ";
		}
		cout << "\n";
		return;
	}
	auto res = solve_linear(a, b);
	if (!res) {
		cout << "-1\n";
		return;
	}
	for (auto x : *res) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}