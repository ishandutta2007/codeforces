#include <iostream>
#include <vector>

using namespace std;

vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	used[u] = true;
	for (auto to : g[u])
		if (!used[to])
			dfs(to);
}
int main() {
	int n;
	cin >> n;
	g.resize(n + 1);
	used.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		g[u].push_back(i);
		g[i].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	cout << cnt;
	return 0;
}