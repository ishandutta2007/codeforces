#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector <bool> used;
vector <set <int>> g;

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	int mi, ma;
	if (g[0].size() > g[1].size()) {
		mi = 1;
		ma = 0;
	}
	else {
		mi = 0;
		ma = 1;
	}
	for (int i = 2; i < n; i++) {
		if (g[i].size() > g[mi].size())
			mi = i;
		if (g[mi].size() > g[ma].size())
			swap(mi, ma);
	}
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += g[i].size();
	for (int i = 0; i < n; i++)
		if (g[i].size() > 2)
			cnt++;
	if (g[mi].size() * 2 + g[ma].size() * 2 >= sum && cnt < 3)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}