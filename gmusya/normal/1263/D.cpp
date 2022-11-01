#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int n, cnt = 0;
vector <string> a;
vector <vector <int>> g(26);
vector <bool> used(26);
vector <bool> unused(26);

void dfs(int u) {
	used[u] = true;
	for (int i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i]);
}

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		unused[a[i][0] - 'a'] = true;
		for (int j = 0; j < a[i].size() - 1; j++) {
			int u = a[i][j] - 'a';
			int v = a[i][j + 1] - 'a';
			g[u].push_back(v);
			g[v].push_back(u);
			unused[u] = true;
			unused[v] = true;
		}
	}
	for (int i = 0; i < 26; i++)
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	for (int i = 0; i < 26; i++)
		cnt -= (1 - unused[i]);
	cout << cnt;
	return 0;
}