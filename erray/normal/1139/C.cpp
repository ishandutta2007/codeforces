#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!c) {
			--a;--b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	vector<int> vis(n);
	function<int(int)> dfs = [&](int nd) {
		int r = 1;
		vis[nd] = 1;
		for (int a : g[nd]) {
			if (!vis[a]) r += dfs(a);
		}
		return r;		
	};
	const int mod = 1e9 + 7;
	auto fp = [&] (long long b, int pw){ 
		long long r = 1;
		for (; pw; pw >>= 1, (b *= b) %= mod) {
			if (pw & 1) (r *= b) %= mod;
		} 
		return r;
	};
	long long ans = fp(n, k);
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		((ans -= fp(dfs(i), k))+= mod) %= mod;;
	}
	cout << ans;
}