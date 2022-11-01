#include <iostream>
#include <vector>

using namespace std;

int cnt = -1;
vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	used[u] = true;
	for (int i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i]);
}

int main() {
	int n;
	cin >> n;
	used.resize(n);
	g.resize(n);
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			if (a[i].first == a[j].first || a[i].second == a[j].second) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	cout << cnt;
	return 0;
}