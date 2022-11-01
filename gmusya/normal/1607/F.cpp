#pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<bool> used;
vector<int> _order;
vector<vector<int>> _g;

void DFS(int v) {
	used[v] = true;
	for (int u : _g[v]) {
		if (!used[u]) {
			DFS(u);
		}
	}
	_order.push_back(v);
};

void DFS(int v, vector<int>& order, vector<vector<int>>& g) {
	swap(order, _order);
	swap(g, _g);
	DFS(v);
	swap(order, _order);
	swap(g, _g);
}

void DFSG(int v, vector<int>& order, vector<int>& p) {
	vector<int> x;
	int u = v;
	while (!used[u]) {
		used[u] = true;
		x.push_back(u);
		u = p[u];
	}
	while (!x.empty()) {
		order.push_back(x.back());
		x.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, pair<int, int>> map_move = {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> board(n, vector<char>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> board[i][j];
			}
		}
		function<int(int, int)> GetVertex = [&](int x, int y) {
			if (0 > x || x >= n || 0 > y || y >= m) {
				return n * m;
			}
			return x * m + y;
		};
		int number_of_vertices = n * m + 1;
		vector<int> p(number_of_vertices);
		used.assign(number_of_vertices, false);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int u = GetVertex(i, j);
				pair<int, int> change = map_move[board[i][j]];
				int v = GetVertex(i + change.first, j + change.second);
				p[u] = v;
			}
		}
		board.clear();
		vector<int> order;
		for (int v = 0; v < number_of_vertices; ++v) {
			if (!used[v]) {
				DFSG(v, order, p);
			}
		}
		vector<vector<int>> comps;
		vector<int> comp(number_of_vertices);
		int cnt = 0;
		used.assign(number_of_vertices, false);
		for (int i = 0; i < number_of_vertices; ++i) {
			int v = order[i];
			if (v == number_of_vertices - 1) {
				comps.emplace_back(number_of_vertices);
				comp[v] = cnt;
				used[v] = true;
				++cnt;
			} else if (!used[v]) {
				comps.emplace_back();
				DFSG(v, comps.back(), p);
				for (int u : comps.back()) {
					comp[u] = cnt;
				}
				++cnt;
			}
		}
		used.clear();
		_g.clear();
		vector<int> ans(number_of_vertices);
		for (int v : order) {
			if (v == n * m) {
				continue;
			}
			if (p[v] == number_of_vertices) {
				ans[v] = 0;
			} else if (comps[comp[v]].size() != 1) {
				ans[v] = static_cast<int>(comps[comp[v]].size());
			} else {
				ans[v] = 1 + ans[p[v]];
			}
		}
		int v = max_element(ans.begin(), ans.end() - 1) - ans.begin();
		cout << v / m + 1 << ' ' << v % m + 1 << ' ' << ans[v] << '\n';
	}
	return 0;
}