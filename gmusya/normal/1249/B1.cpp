#include <iostream>
#include <vector>

using namespace std;

int color;
vector <int> answer;
vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	used[u] = true;
	color++;
	for (int i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i]);
	answer[u] = color;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		answer.resize(0);
		answer.resize(n);
		used.resize(0);
		used.resize(n);
		g.resize(0);
		g.resize(n);
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u;
			u--;
			g[i].push_back(u);
			g[u].push_back(i);
		}
		for (int i = 0; i < n; i++) {
			if (used[i])
				continue;
			color = 0;
			dfs(i);
		}
		for (auto now : answer)
			cout << now << " ";
		cout << endl;
	}
	return 0;
}