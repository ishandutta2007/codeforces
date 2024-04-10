#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> deg(n);
	vector <vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	vector <bool> used(n);
	queue <int> q;
	for (int i = 0; i < n; i++)
		if (deg[i] == 1) {
			q.push(i);
			used[i] = true;
		}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (q.empty()) {
			cout << "! " << v + 1;
			return 0;
		}
		int u = q.front();
		q.pop();
		cout << "? " << v + 1 << " " << u + 1 << endl;
		cout.flush();
		int lca;
		cin >> lca;
		lca--;
		if (lca == u || lca == v) {
			cout << "! " << lca + 1 << endl;
			return 0;
		}
		for (int s : g[v])
			if (!used[s]) {
				deg[v]--;
				deg[s]--;
				if (deg[s] <= 1) {
					used[s] = true;
					q.push(s);
				}
			}
		for (int s : g[u]) {
			if (!used[s]) {
				deg[u]--;
				deg[s]--;
				if (deg[s] <= 1) {
					used[s] = true;
					q.push(s);
				}
			}
		}
	}
	return 0;
}