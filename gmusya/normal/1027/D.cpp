#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000;

int cnt = 0;
vector <bool> used;
vector <int> order, comp, ans, cost, c, nei;
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
	for (auto to : gr[v])
		if (ans[to] != ans[v])
			nei[ans[to]]++;
	for (auto to : gr[v])
		if (!used[to])
			dfs3(to);
}

int main() {
	int n;
	cin >> n;
	g.resize(n);
	gr.resize(n);
	used.resize(n);
	ans.resize(n);
	c.resize(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		u--;
		g[i].push_back(u);
		gr[u].push_back(i);
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++)
		used[i] = false;
	for (auto v : order) {
		if (!used[v]) {
			dfs2(v);
			cnt++;
		}
	}
	cost.assign(cnt, INF);
	for (int i = 0; i < n; i++)
		cost[ans[i]] = min(cost[ans[i]], c[i]);
	used.assign(n, false);
	nei.resize(cnt);
	int answer = 0;
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs3(i);
	for (int i = 0; i < cnt; i++)
		if (nei[i] == 0)
			answer += cost[i];
	cout << answer;
	return 0;
}