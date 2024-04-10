#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
vector<int> g[N];

int par[N], sz[N];

void dfs(int v, int p){
	sz[v] = 1;
	par[v] = p;
	for(int u : g[v]){
		if(u != p){
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(x, 0);
	long long ans = n*1LL*(n - 1);
	int cnt1 = sz[x], cnt2 = sz[y];
	while(par[y] != x){
		y = par[y];
	}
	cnt1 -= sz[y];
	ans -= cnt1*1LL*cnt2;
	cout << ans << '\n';

	return 0;
}