#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

vector<int> g[maxN], ng[maxN];
int n, m, k, par[maxN], dep[maxN];

void dfs(int v){
	for(int u : g[v]){
		if(!dep[u]){
			par[u] = v;
			dep[u] = dep[v] + 1; dfs(u);

			ng[v].emplace_back(u);
		}else if(dep[u] + 1 < dep[v] && dep[u] >= dep[v] - k + 1){
			cout << 2 << '\n';
			cout << dep[v] - dep[u] + 1 << '\n';
			while(v != u){
				cout << v << ' ';
				v = par[v];
			}
			cout << u << '\n';
			exit(0);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dep[1] = 1; dfs(1);

	cout << 1 << '\n';
	vector<pair<int, int> > vec[2];
	for(int i = 1; i <= n; i++){
		vec[dep[i]&1].emplace_back(dep[i], i);
	}
	int req = (k + 1)/2;
	sort(vec[0].begin(), vec[0].end());
	sort(vec[1].begin(), vec[1].end());
	if((int)vec[0].size() >= req){
		for(int i = 0; i < req; i++){
			cout << vec[0][i].second << ' ';
		}
		cout << '\n';
	}else{
		for(int i = 0; i < req; i++){
			cout << vec[1][i].second << ' ';
		}
		cout << '\n';
	}
	return 0;
}