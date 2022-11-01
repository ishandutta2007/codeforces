#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e8;

vector <bool> used;
vector <int> d_1, d_n;
vector < vector <int>> g;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	used.resize(n), g.resize(n), d_1.resize(n), d_n.resize(n);
	vector <int> a(k);
	for (int i = 0; i < k; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue <int> q;
	d_1[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		used[v] = true;
		for (auto u : g[v]) 
			if (!used[u]) {
				d_1[u] = d_1[v] + 1;
				q.push(u);
				used[u] = true;
			}
	}
	used.assign(n, false);
	d_n[n - 1] = 0;
	q.push(n - 1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		used[v] = true;
		for (auto u : g[v])
			if (!used[u]) {
				d_n[u] = d_n[v] + 1;
				q.push(u);
				used[u] = true;
			}
	}
	//for (int i = 0; i < n; i++)
	//	cout << d_1[i] << " ";
	//cout << endl;
	//for (int i = 0; i < n; i++)
	//	cout << d_n[i] << " ";
	int ans = d_1[n - 1];
	vector <pair <int, int>> hm(k);
	for (int i = 0; i < k; i++)
		hm[i] = { d_1[a[i] - 1], d_n[a[i] - 1] };
	sort(hm.begin(), hm.end());
	//cout << endl;
	//for (auto now : hm)
	//	cout << now.first << " " << now.second << endl;
	int ma = hm[k - 1].second;
	int lul = 0;
	for (int i = k - 2; i >= 0; i--) {
		lul = max(lul, hm[i].first + 1 + ma);
		ma = max(ma, hm[i].second);
	}
	cout << min(lul, ans);
	return 0;
}