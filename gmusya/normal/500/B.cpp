#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt = 0;
vector <bool> used;
vector <int> a;
vector <vector <char>> c;
vector <vector <int>> g;
vector <pair <vector <int>, vector <int>>> comp;

void dfs(int u) {
	used[u] = true;
	comp[cnt].first.push_back(u);
	comp[cnt].second.push_back(a[u]);
	for (auto to : g[u])
		if (!used[to])
			dfs(to);
}

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	c.assign(n, vector <char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	g.resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (c[i][j] == '1')
				g[i].push_back(j);
	used.resize(n);
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			comp.push_back({});
			dfs(i);
			cnt++;
		}
	vector <int> ans(n);
	for (auto arr : comp) {
		sort(arr.first.begin(), arr.first.end());
		sort(arr.second.begin(), arr.second.end());
		for (int i = 0; i < arr.first.size(); i++)
			ans[arr.first[i]] = arr.second[i];
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return 0;
}