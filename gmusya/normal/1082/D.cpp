#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int v, vector <bool> &used, vector <int> &d, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v]) 
		if (!used[u]) {
			d[u] = d[v] + 1;
			dfs(u, used, d, g);
		}
}

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (2 * (n - 1) > sum) {
		cout << "NO";
		return 0;
	}
	vector <int> more_than_one, leaves;
	for (int i = 0; i < n; i++) {
		if (a[i] > 1) more_than_one.push_back(i);
		else leaves.push_back(i);
	}
	vector <pair <int, int>> ans;
	for (int i = 0; i < more_than_one.size() - 1; i++)
		ans.push_back({ more_than_one[i], more_than_one[i + 1] });
	for (int i = 0; i < more_than_one.size() - 1; i++) {
		a[more_than_one[i]]--;
		a[more_than_one[i + 1]]--;
	}
	int l = more_than_one[0];
	if (leaves.size() > 0) {
		ans.push_back({ leaves[0], l });
		a[l]--;
	}
	int r = more_than_one[more_than_one.size() - 1];
	if (leaves.size() > 1) {
		ans.push_back({ leaves[1], r });
		a[r]--;
	}
	int it = 0;
	for (int i = 2; i < leaves.size(); i++) {
		while(!a[more_than_one[it]]) it++;
		ans.push_back({leaves[i], more_than_one[it] });
		a[more_than_one[it]]--;
	}
	vector <bool> used(n);
	vector <int> d(n);
	vector <vector <int>> g(n);
	for (int i = 0; i < ans.size(); i++) {
		int u = ans[i].first;
		int v = ans[i].second;
		g[u].push_back(v), g[v].push_back(u);
	}
	d[0] = 0;
	dfs(0, used, d, g);
	int ma = 0;
	for (int i = 0; i < n; i++)
		if (d[ma] < d[i])
			ma = i;
	used.assign(n, false);
	d[ma] = 0;
	dfs(ma, used, d, g);
	for (int i = 0; i < n; i++)
		if (d[ma] < d[i])
			ma = i;
	cout << "YES " << d[ma] << endl;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	return 0;
}