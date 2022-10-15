#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> p(n), h(n);
		vector<vector<int>> g(n);
		for (int i = 0; i < n; ++i) cin >> p[i];
		for (int i = 0; i < n; ++i) cin >> h[i];
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			--a;--b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vector<int> ct(n);
		function<int(int, int)> dfs = [&](int nd, int par) {
			ct[nd] = p[nd];
			for (auto el : g[nd]) {
				if (el != par) {
					ct[nd] += dfs(el, nd);
				}
			}			
			return ct[nd];
		};
		dfs(0, -1);
		vector<pair<int, int>> rans(n);
		bool ok = true;
		for (int i = 0; i < n; ++i) {
	  	rans[i].first = (ct[i] + h[i]) / 2;
			rans[i].second = ct[i] - rans[i].first; 
			if ((ct[i] + h[i]) & 1 || rans[i].first < 0 || rans[i].second < 0) {
				ok = false;
			}
		}
		cerr << (ok ? "true" : "false") << '\n';
		function<void(int, int)> dfs2 = [&](int nd, int par) {
			int sum = 0;
			for (auto el : g[nd]) {
				if (el != par) {
					sum += rans[el].second;
					dfs2(el, nd);	
				}
			}
			if (sum + p[nd] < rans[nd].second && (nd == 0 || (int) g[nd].size() != 1))  {
				ok = false;
			}
		};
		dfs2(0, -1);
		cout << (ok ? "YES" : "NO") << '\n';
	}
}