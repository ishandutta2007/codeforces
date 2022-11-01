#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector <int> ans;
vector <bool> used;
vector <vector <int>> g;


int main() {
	int n, m;
	cin >> n >> m;
	used.resize(n);
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u == v)
			continue;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	set <int> s;
	for (int i = 0; i < g[0].size(); i++)
		s.insert(g[0][i]);
	used[0] = true;
	ans.push_back(0);
	while (s.size() > 0) {
		int x = *s.begin();
		s.erase(x);
		used[x] = true;
		ans.push_back(x);
		for (int i = 0; i < g[x].size(); i++)
			if (!used[g[x][i]])
				s.insert(g[x][i]);
	}
	for (auto now : ans)
		cout << now + 1 << " ";
	return 0;
}