#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 1e15;


void dfs(int v, vector <bool> &used, vector <ll> &a, vector <ll> &b, vector <ll> &c, vector <ll> &s01, vector <ll> &s10, vector <ll> &ans, vector <vector <int>> &g) {
	used[v] = true;
	ll sum01 = 0, sum10 = 0;
	s01[v] = (b[v] == 0 && c[v] == 1);
	s10[v] = (b[v] == 1 && c[v] == 0);
	sum01 += (b[v] == 0 && c[v] == 1);
	sum10 += (b[v] == 1 && c[v] == 0);
	for (int u : g[v]) {
		if (!used[u]) {
			a[u] = min(a[u], a[v]);
			dfs(u, used, a, b, c, s01, s10, ans, g);
			sum01 += max(0LL, s01[u] - s10[u]);
			sum10 += max(0LL, s10[u] - s01[u]);
			s01[v] += s01[u];
			s10[v] += s10[u];
			ans[v] += ans[u];
		}
	}
	ans[v] += 2LL * min(sum01, sum10) * a[v];
}

int main() {
	int n;
	cin >> n;
	vector <ll> a(n), b(n), c(n), s01(n), s10(n), ans(n);
	vector <bool> used(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];
	vector <vector <int>> g(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cnt1 += b[i];
		cnt2 += c[i];
	}
	if (cnt1 != cnt2) {
		cout << -1 << '\n';
		return 0;
	}
	dfs(0, used, a, b, c, s01, s10, ans, g);
	cout << ans[0] << '\n';
	return 0;
}

/*
4
3 1 0
2 0 1
1 1 0
0 0 1
1 2
2 3
3 4
*/