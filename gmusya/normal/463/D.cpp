#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> used;
vector <int> order, ans;
vector <vector <int>> g;

void dfs1(int v) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs1(u);
	order.push_back(v);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector <vector <int>> a(k, vector <int>(n)), cnt(n, vector <int>(n));
	used.resize(n), ans.resize(n), g.resize(n);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	for (int it = 0; it < k; it++)
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				cnt[a[it][i]][a[it][j]]++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (cnt[i][j] == k) 
				g[i].push_back(j);
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int v = order[i];
		ans[v] = 1;
		for (int u : g[v])
			ans[v] = max(ans[v], ans[u] + 1);
		answer = max(ans[v], answer);
	}
	cout << answer;
	return 0;
}