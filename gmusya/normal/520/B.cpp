#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <bool> used(100000);
vector <int> d(100000);
vector <vector <int>> g(100000);

int main() {
	cin >> n >> m;
	for (int i = 1; i < 50000; i++) {
		g[i].push_back(i * 2);
		g[i].push_back(i - 1);
	}
	queue <int> q;
	q.push(n);
	d[n] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		used[v] = true;
		for (int i = 0; i < g[v].size(); i++) {
			if (used[g[v][i]])
				continue;
			d[g[v][i]] = d[v] + 1;
			q.push(g[v][i]);
			used[g[v][i]] = true;
		}
	}
	cout << d[m];
	return 0;
}