#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void dfs1(int v, int p, vector <int> &par, vector <int> &pe, vector <vector <int>> &g) {
	for (int u : g[v]) {
		if (u == p) continue;
		par[u] = v;
		dfs1(u, v, par, pe, g);
		pe[v] += pe[u];
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		bool tf = true;
		vector <int> pe(n);
		for (int i = 0; i < n; i++)
			cin >> pe[i];
		vector <int> h(n);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		vector <vector <int>> g(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector <int> par(n);
		dfs1(0, -1, par, pe, g);
		vector <int> gd(n), bd(n);
		for (int i = 0; i < n; i++) {
			if (abs(h[i] + pe[i]) % 2) tf = false;
			gd[i] = (h[i] + pe[i]) / 2;
			bd[i] = pe[i] - gd[i];
			if (gd[i] < 0 || bd[i] < 0) tf = false;
		}
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int u : g[i]) {
				if (u == par[i]) continue;
				sum += gd[u];
			}
			if (sum > gd[i]) tf = false;
		}
		if (tf) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}