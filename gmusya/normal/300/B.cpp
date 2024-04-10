#include <iostream>
#include <vector>

using namespace std;

vector <bool> used;
vector <vector <int>> comp;
vector <vector <int>> g;

void dfs(int u, int pos) {
	used[u] = true;
	for (int v : g[u])
		if (!used[v])
			dfs(v, pos);
	comp[pos].push_back(u);
}

int main() {
	int n, m;
	cin >> n >> m;
	used.resize(n), g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <int> cnt1;
	vector <pair <int, int>> cnt2;
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			comp.push_back({});
			dfs(i, comp.size() - 1);
		}
	for (int i = 0; i < comp.size(); i++) {
		if (comp[i].size() == 1)
			cnt1.push_back(comp[i][0]);
		if (comp[i].size() == 2)
			cnt2.push_back({ comp[i][0], comp[i][1] });
		if (comp[i].size() > 3) {
			cout << "-1";
			return 0;
		}
	}
	if (cnt1.size() < cnt2.size()) {
		cout << "-1";
		return 0;
	}
	for (int i = 0; i < cnt2.size(); i++) 
		cout << cnt1[i] + 1 << " " << cnt2[i].first + 1 << " " << cnt2[i].second + 1 << endl;
	for (int i = cnt2.size(); i < cnt1.size(); i += 3)
		cout << cnt1[i] + 1 << " " << cnt1[i + 1] + 1 << " " << cnt1[i + 2] + 1 << endl;
	for (int i = 0; i < comp.size(); i++) 
		if (comp[i].size() == 3) 
			cout << comp[i][0] + 1 << " " << comp[i][1] + 1 << " " << comp[i][2] + 1 << endl;
	return 0;
}