#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	n = k;
	vector<vector<int>> g(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		if (a < n && b < n) {                         
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	vector<int> h(n, -1), par(n);
	function<void(int)> dfs = [&](int nd) {
		for (int a : g[nd]) {
			if (a == par[nd]) continue;
			if (h[a] == -1) {
				h[a] = h[nd] + 1;
				par[a] = nd;
				dfs(a);
			} else {
				if (h[a] < h[nd]) {
					vector<int> ans;
					while (nd != a) {
						ans.push_back(nd);
						nd = par[nd];
					}	
					cout << "2\n" << ans.size() + 1 << '\n';
					for (int el : ans) cout << el + 1 << ' ';
					cout << a + 1;
					exit(0);
				}
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		if (h[i] == -1)	{
		  h[i] = 0;
			dfs(i);
		}
	}
	cout << "1\n";
	vector<int> ord(n), vis(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b) {
		return h[a] > h[b];
	});
	for (int i = 0, ct = 0; i < n && ct < (k + 1) >> 1; ++i) {
		if (!vis[ord[i]]) {
			cout << ord[i] + 1 << ' ';
			vis[par[ord[i]]] = 1;
			++ct;
		}
	}
}