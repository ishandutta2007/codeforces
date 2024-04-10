#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

vector<int> g[maxn];
int cnt[maxn];

void dfs1(int v, int p){
	for(int u : g[v]){
		if(u != p){
			dfs1(u, v);
			cnt[v] += cnt[u];
		}
	}
}

int dfs2(int v, int p){
	int ret = 0;
	for(int u : g[v]){
		if(u != p && cnt[u]){
			ret += 2 + dfs2(u, v);
		}
	}
	return ret;
}

int dfs3(int v, int p, int y){
	if(v == y)return 0;
	for(int u : g[v]){
		if(u != p){
			int len = dfs3(u, v, y);
			if(len != -1)return len + 1;
		}
	}
	return -1;
}

void solve(){
	int n; cin >> n;
	int k; cin >> k;
	int x; cin >> x;
	int y; cin >> y;
	for(int i = 1; i <= n; i++){
		cnt[i] = 0;
		g[i].clear();
	}
	cnt[y]++;
	for(int i = 1; i <= k; i++){
		int u; cin >> u; cnt[u]++;
	}
	for(int i = 2; i <= n; i++){
		int u; cin >> u;
		int v; cin >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs1(x, x);
	cout << dfs2(x, x) - dfs3(x, x, y) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}