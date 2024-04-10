#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000005;

vector<int> g[maxN];
int ans[maxN], vis[maxN], dist[maxN];

void dfs(int v){
	vis[v] = 1;
	dist[v] = 0;
	for(int u : g[v]){
		if(vis[u] == 2){
			dist[v] = max(dist[v], dist[u] + 1);
			continue;
		}
		if(vis[u] == 1){
			continue;
		}
		dfs(u);
		dist[v] = max(dist[v], dist[u] + 1);
	}
	if(ans[v]){
		for(int u : g[v]){
			if(vis[u] == 1){
				ans[u] = 0;
			}
		}
	}
	vis[v] = 2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		ans[i] = 1;
		vis[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
	}
	vector<pair<int, int> > vec;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
		}
		vec.emplace_back(dist[i], i);
	}
	vector<int> vert;
	sort(vec.rbegin(), vec.rend());
	for(auto x : vec){
		int v = x.second;
		if(!ans[v])continue;
		for(int u : g[v]){
			if(dist[u] < dist[v]){
				ans[u] = 0;
			}
		}
		vert.emplace_back(v);
	}
	cout << vert.size() << '\n';
	for(auto x : vert){
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}