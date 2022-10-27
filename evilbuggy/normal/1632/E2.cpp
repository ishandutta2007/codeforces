#include <bits/stdc++.h>
using namespace std;

const int logn = 19;
const int maxn = 300005;

vector<int> g[maxn], vec[maxn];
int parent[maxn][logn], depth[maxn], h[maxn];

void dfs(int v, int p, int d){
	depth[v] = d;
	parent[v][0] = p;
	for(int k = 1; k < logn; k++){
		parent[v][k] = parent[parent[v][k - 1]][k - 1];
	}
	for(int u : g[v]){
		if(u != p){
			dfs(u, v, d + 1);
		}
	}
}

inline int lca(int u, int v){
	if(depth[u] < depth[v])swap(u, v);
	for(int i = logn - 1; i >= 0; i--){
		if((depth[u] - depth[v]) >= (1 << i)){
			u = parent[u][i];
		}
	}
	if(u == v)return u;
	for(int i = logn - 1; i >= 0; i--){
		if(parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		vec[i].clear();
	}
	for(int i = 2; i <= n; i++){
		int u; cin >> u;
		int v; cin >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 1, 0);
	for(int i = 2; i <= n; i++){
		vec[depth[i]].emplace_back(i);
	}
	int u = -1;
	int v = -1;
	int dim = -1e9;
	for(int y = n; y >= 1; y--){
		h[y] = (dim + 1)/2;
		for(int w : vec[y]){
			if(u == -1){
				u = w;
				v = w;
				dim = 0;
			}else{
				int duw = depth[u] + depth[w] - 2*depth[lca(u, w)];
				int dwv = depth[w] + depth[v] - 2*depth[lca(w, v)];
				if(duw >= max(dim, dwv)){
					v = w;
					dim = duw;
				}else if(dwv >= max(dim, duw)){
					u = w;
					dim = dwv;
				}
			}
		}
	}
	for(int x = 1, y = 1; x <= n; x++){
		while(h[y] > y - x)y++;
		cout << y << " ";
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--)solve();

	return 0;
}