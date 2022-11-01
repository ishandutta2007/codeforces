#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector <bool> used;
vector <int> dsu, d;
vector <vector <int>> g;

int get(int v) {
	if (v == dsu[v])
		return v;
	return dsu[v] = get(dsu[v]);
}

void merge(int v, int u) {
	v = get(v);
	u = get(u);
	if (rand() % 2)
		dsu[u] = v;
	else
		dsu[v] = u;
}

void dfs(int v) {
	used[v] = true;
	for (int to : g[v]) {
		if (!used[to]) 
			dfs(to);
		d[v] = max(d[v], d[to] + 1);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <char>> c(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	dsu.resize(n + m), g.resize(n + m), used.resize(n + m), d.assign(n + m, 1);
	for (int i = 0; i < n + m; i++)
		dsu[i] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == '=')
				merge(i, j + n);
	for (int i = 0; i < n + m; i++)
		dsu[i] = get(i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '>')
				g[dsu[i]].push_back(dsu[j + n]);
			if (c[i][j] == '<')
				g[dsu[j + n]].push_back(dsu[i]);
		}
	for (int i = 0; i < n + m; i++) 
		if (!used[dsu[i]]) 
			dfs(dsu[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '>' && d[dsu[i]] <= d[dsu[j + n]]) {
				cout << "No";
				return 0;
			}
			if (c[i][j] == '<' && d[dsu[i]] >= d[dsu[j + n]]) {
				cout << "No";
				return 0;
			}
			if (c[i][j] == '=' && d[dsu[i]] != d[dsu[j + n]]) {
				cout << "No";
				return 0;
			}
		}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++)
		cout << d[dsu[i]] << " ";
	cout << endl;
	for (int i = n; i < n + m; i++)
		cout << d[dsu[i]] << " ";
	return 0;
}