#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m, k;

void dfs(int v, vector <bool> &used, vector <int> &color, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u]) {
			color[u] = 1 - color[v];
			dfs(u, used, color, g);
		}
}

void solve1(int n, int k) {
	vector <vector <int>> g(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <bool> used(n);
	vector <int> color(n);
	dfs(0, used, color, g);
	vector <int> c0, c1;
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) c0.push_back(i);
		else c1.push_back(i);
	}
	if (c0.size() < c1.size()) swap(c0, c1);
	cout << 1 << '\n';
	for (int i = 0; i < (k + 1) / 2; i++)
		cout << c0[i] + 1 << ' ';
}

void solve2(int n, int m, int k) {
	vector <pair <int, int>> e;
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		e.push_back({ u, v });
	}
	stack <int> s;
	vector <bool> used(n);
	s.push(0);
	vector <int> cycle;
	while (!s.empty()) {
		int v = s.top();
		used[v] = true;
		s.pop();
		int last = -1;
		if (!s.empty()) last = s.top();
		s.push(v);
		while (!g[v].empty() && g[v].back() == last)
			g[v].pop_back();
		if (g[v].empty()) {
			s.pop();
			continue;
		}
		int u = g[v].back();
		g[v].pop_back();
		if (used[u]) {
			cycle.push_back(u);
			while (s.top() != u) {
				cycle.push_back(s.top());
				s.pop();
			}
			break;
		}
		s.push(u);
	}
	while (true) {
		vector <int> pos(n, -1);
		for (int i = 0; i < cycle.size(); i++)
			pos[cycle[i]] = i;
		int it = 0;
		while (it != m) {
			int u = e[it].first, v = e[it].second;
			if (pos[u] == -1 || pos[v] == -1 || abs(pos[v] - pos[u]) == 1 || abs(pos[v] - pos[u]) + 1 == cycle.size()) {
				it++;
				continue;
			}
			if (pos[u] > pos[v]) swap(u, v);
			vector <int> cycle0, cycle1;
			for (int i = 0; i <= pos[u]; i++)
				cycle0.push_back(cycle[i]);
			for (int i = pos[u]; i <= pos[v]; i++)
				cycle1.push_back(cycle[i]);
			for (int i = pos[v]; i < cycle.size(); i++)
				cycle0.push_back(cycle[i]);
			if (cycle0.size() == 2 || cycle1.size() == 2) {
				cout << pos[u] << ' ' << pos[v] << ' ' << cycle.size() << '\n';
				return;
			}
			if (cycle0.size() > cycle1.size()) swap(cycle0, cycle1);
			swap(cycle0, cycle);
			break;
		}
		if (it == m) break;
	}
	if (cycle.size() <= k) {
		cout << 2 << '\n';
		cout << cycle.size() << '\n';
		for (auto &now : cycle)
			cout << now + 1 << ' ';
		return;
	}
	cout << 1 << '\n';
	for (int i = 0; i < (k + 1) / 2; i++)
		cout << cycle[2 * i] + 1 << ' ';
}

int main() {
	cin >> n >> m >> k;
	if (m + 1 == n) solve1(n, k);
	else solve2(n, m, k);
	return 0;
}

/*
4 5 2
1 3
4 1
3 4
2 3
1 2
*/