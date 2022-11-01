#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
vector <bool> used;
vector <int> order, comp, ans, hm;
vector <vector <int>> g, gr;

void dfs1(int v) {
	used[v] = true;
	for (auto to : g[v])
		if (!used[to])
			dfs1(to);
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	ans[v] = cnt;
	for (auto to : gr[v])
		if (!used[to])
			dfs2(to);
}

void dfs3(int v) {
	used[v] = true;
	for (auto to : g[v])
		if (ans[to] != ans[v]) {
			hm[ans[to] - 1]++;
		}
	for (auto to : g[v])
		if (!used[to])
			dfs3(to);
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	g.resize(n);
	gr.resize(n);
	used.resize(n);
	ans.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++)
		used[i] = false;
	for (auto v : order) {
		if (!used[v]) {
			cnt++;
			dfs2(v);
		}
	}
	used.assign(n, false);
	hm.resize(cnt);
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs3(i);
	int answer = 0;
	for (int i = 0; i < cnt; i++)
		answer += (hm[i] == 0) && (ans[s] - 1 != i);
	cout << answer;
	return 0;
}