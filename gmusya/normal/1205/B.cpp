#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef unsigned long long ll;

const ll INF = 1e18;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector <ll> b;
	for (int i = 0; i < n; i++) if (a[i]) b.push_back(a[i]);
	a = b;
	n = b.size();
	vector <ll> p(64);
	p[0] = 1;
	for (int i = 1; i < 64; i++) p[i] = (p[i - 1] << 1);
	vector <int> cnt(64);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 64; j++)
			cnt[j] += ((a[i] & p[j]) > 0);
	for (int i = 0; i < 64; i++) {
		if (cnt[i] > 2) {
			cout << 3;
			return 0;
		}
	}
	vector <vector <int>> g(n);	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] & a[j]) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
	ll cycle = INF;
	for (int s = 0; s < n; s++) {
		vector <vector <int>> used(n, vector <int>(n));
		queue <int> q;
		vector <ll> d(n, INF);
		d[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u : g[v]) {
				if (d[u] != INF && !used[u][v]) 
					cycle = min(cycle, d[u] + d[v] + 1);
				used[u][v] = used[v][u] = true;
				if (d[u] == INF) {
					d[u] = d[v] + 1;
					q.push(u);
				}
			}
		}
	}
	if (cycle == INF) cout << -1;
	else cout << cycle;
	return 0;
}