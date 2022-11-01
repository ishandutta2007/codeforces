#include <iostream>
#include <vector>

using namespace std;

bool cycle = false;
vector <bool> used;
vector <vector <int>> g;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		if (!used[g[v][i]])
			dfs(g[v][i]);
		if (cycle)
			break;
		if (used[g[v][i]]) {
			cycle = true;
			cout << g[v][i] + 1 << " ";
			break;
		}
	}
}

int main() {
	int n;
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		g[i].push_back(x - 1);
	}
	for (int i = 0; i < n; i++) {
		used.resize(0);
		used.resize(n);
		cycle = false;
		dfs(i);
	}
	return 0;
}