#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

const ll INF = 1e9;

using namespace std;

void dfs(int v, vector <bool> &used, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u]) 
			dfs(u, used, g);
}

int N;
vector <int> ANS, POS;
vector <pair <pair <int, int>, bool>> E;
vector <vector <pair <int, int>>> G;

void tour(int v) {
	for (; POS[v] < G[v].size();) {
		int i = POS[v];
		int u = G[v][i].first;
		int num = G[v][i].second;
		POS[v]++;
		if (E[num].second)
			continue;
		E[num].second = true;
		tour(u);
	}
	ANS.push_back(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	int L = 0;
	int R = 20;
	while (L != R) {
		int k = (L + R + 1) / 2;
		int modulo = (1 << k);
		vector <vector <int>> g(modulo);
		for (int i = 0; i < n; i++) {
			int u = a[i].first % modulo, v = a[i].second % modulo;
			if (u > v) swap(u, v);
			g[u].push_back(v), g[v].push_back(u);
		}
		bool tf = true;
		for (int i = 0; i < modulo; i++)
			if (g[i].size() % 2 == 1)
				tf = false;
		int cnt = 0;
		vector <bool> used(modulo);
		for (int i = 0; i < modulo; i++)
			if (!g[i].empty() && !used[i]) {
				cnt++;
				dfs(i, used, g);
			}
		if (cnt > 1) tf = false;
		if (tf) L = k;
		else R = k - 1;
	}
	int k = L;
	int modulo = (1 << k);
	vector <vector <int>> g(modulo);
	for (int i = 0; i < n; i++) {
		int u = a[i].first % modulo, v = a[i].second % modulo;
		if (u > v) swap(u, v);
		if (u != v) g[v].push_back(u);
		g[u].push_back(v);
	}
	vector <bool> used(modulo);
	N = modulo;
	G.resize(modulo), POS.resize(modulo);
	vector <int> count(modulo);
	cout << k << '\n';
	for (int i = 0; i < N; i++) {
		int m = g[i].size();
		for (int j = 0; j < m; j++) {
			int v = g[i][j];
			if (i <= v) E.push_back({ {i, v}, 0 });
		}
	}
	for (int i = 0; i < E.size(); i++) {
		int v = E[i].first.first;
		int u = E[i].first.second;
		G[u].push_back({ v, i });
		G[v].push_back({ u, i });
	}
	int s = 0;
	while (G[s].size() == 0) s++;
	tour(s);
	map <ll, vector <pair <int, int>>> ma;
	int cnt = 0;
	for (int i = 0; i < ANS.size() - 1; i++) {
		ll u = ANS[i];
		ll v = ANS[i + 1];
		bool tmp = false;
		if (u > v) {
			swap(u, v);
			tmp = true;
		}
		ma[u * INF + v].push_back({ cnt++, tmp });
	}
	vector <pair <int, int>> answer(cnt);
	for (int i = 0; i < n; i++) {
		ll u = a[i].first % modulo, v = a[i].second % modulo;
		bool _tmp = false;
		if (u > v) {
			swap(u, v);
			_tmp = true;
		}
		if (ma[u * INF + v].back().second) _tmp = !_tmp;
		if (_tmp) answer[ma[u * INF + v].back().first] = { 2 * i + 1, 2 * i };
		else answer[ma[u * INF + v].back().first] = { 2 * i, 2 * i + 1 };
		ma[u * INF + v].pop_back();
	}
	for (auto now : answer)
		cout << now.first + 1 << ' ' << now.second + 1 << ' ';
	return 0;
}