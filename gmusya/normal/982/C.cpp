#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> d(n), p(n), s(n), k(n);
	vector <bool> used(n);
	vector <vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n % 2 == 1) {
		cout << "-1";
		return 0;
	}
	queue <int> q;
	q.push(0);
	p[0] = -1;
	used[0] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto to : g[u]) 
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[u] + 1;
				p[to] = u;
			}
	}
	set <int> hm;
	for (int i = 0; i < n; i++)
		s[i] = g[i].size();
	for (int i = 1; i < n; i++)
		if (s[i] == 1)
			hm.insert(i);
	while (!hm.empty()) {
		int u = *hm.begin();
		hm.erase(u);
		s[p[u]]--;
		k[p[u]] += (k[u] + 1);
		if (s[p[u]] == 1 && p[u] != 0)
			hm.insert(p[u]);
	}
	int cnt = 0;
	for (int i = 1; i < n; i++)
		cnt += (k[i] % 2 == 1);
	cout << cnt;
	return 0;
}