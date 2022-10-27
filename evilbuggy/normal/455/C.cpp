#include <bits/stdc++.h>
using namespace std;

const int maxn = 300005;

vector<int> g[maxn];
int cnt[maxn], par[maxn], diam[maxn], dist[maxn];

int find(int v){
	return (par[v] == v)?v:(par[v] = find(par[v]));
}

void combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v){
		return;
	}
	if(cnt[u] < cnt[v]){
		swap(u, v);
	}
	int dm = (diam[u] + 1)/2  + (diam[v] + 1)/2 + 1;
	diam[u] = max({diam[u], diam[v], dm});
	cnt[u] += cnt[v]; par[v] = u;
}

int dfs(int v, int p = 0, int d = 0){
	int ret = v;
	dist[v] = d;
	for(int u : g[v]){
		if(u == p)continue;
		int w = dfs(u, v, d + 1);
		if(dist[ret] < dist[w])ret = w;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	int q; cin >> q;
	for(int i = 1; i <= n; i++){
		cnt[i] = 1; par[i] = i; diam[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		int x; cin >> x;
		int y; cin >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
		combine(x, y);
	}
	for(int i = 1; i <= n; i++){
		if(find(i) == i){
			int v;
			v = dfs(i);
			v = dfs(v);
			diam[i] = dist[v];
		}
	}
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int x; cin >> x;
			cout << diam[find(x)] << '\n';
		}else{
			int x; cin >> x;
			int y; cin >> y;
			combine(x, y);
		}
	}

	return 0;
}