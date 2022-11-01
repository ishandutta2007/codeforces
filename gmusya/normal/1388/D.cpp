#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void dfs(int v, vector <bool> &used, vector <int> &order, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs(u, used, order, g);
	order.push_back(v);
}

int main() {
	int n;
	cin >> n;
	vector <ll> a(n);
	vector <int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector <vector <int>> g(n);
	for (int i = 0; i < n; i++) {
		if (b[i] == -1) continue;
		g[i].push_back(b[i] - 1);
	}
	vector <int> order;
	vector <bool> used(n);
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i, used, order, g);
	ll ans = 0;
	vector <int> ans0, ans1;
	for (int i = n - 1; i >= 0; i--) {
		int v = order[i];
		ans += a[v];
		if (b[v] != -1 && a[v] > 0)
			a[b[v] - 1] += a[v];
		if (a[v] >= 0) ans0.push_back(v);
		else ans1.push_back(v);
	}
	reverse(ans1.begin(), ans1.end());
	cout << ans << '\n';
	for (auto &now : ans0)
		cout << now + 1 << ' ';
	for (auto &now : ans1)
		cout << now + 1 << ' ';
	return 0;
}