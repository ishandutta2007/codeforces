#include <iostream>
#include <vector>

using namespace std;

vector <bool> used, leave;
vector <int> d;
vector <vector <int>> g;

int minans, maxans;

void dfs(int v) {
	used[v] = true;
	int cnt = 0;
	for (int u : g[v])
		if (!used[u]) {
			d[u] = d[v] + 1;
			cnt += leave[u];
			dfs(u);
		}
	if (cnt >= 1) maxans -= (cnt - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	maxans = n - 1;
	used.resize(n), leave.resize(n), d.resize(n), g.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int notleave;
	for (int i = 0; i < n; i++) {
		leave[i] = (g[i].size() == 1);
		if (!leave[i]) notleave = i;
	}
	d[notleave] = 0;
	dfs(notleave);
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (!leave[i]) continue;
		if (d[i] % 2) cnt1++;
		else cnt0++;
	}
	if (cnt0 && cnt1) minans = 3;
	else minans = 1;
	cout << minans << " " << maxans;
	return 0;
}