#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
map<int, double> mp[N];
vector<int> g[N], s[N];
vector<long long> sum[N];
int comp[N], dist[N], diam[N];

void dfs1(int v, int p, int c){
	dist[v] = 0;
	comp[v] = c;
	for(int u : g[v]){
		if(u != p){
			dfs1(u, v, c);
			dist[v] = max(dist[v], dist[u] + 1);
		}
	}
}

void dfs2(int v, int p, int x){
	int mx1 = x, mx2 = 0;
	for(int u : g[v]){
		if(u != p){
			if(dist[u] + 1 >= mx1){
				mx2 = mx1;
				mx1 = dist[u] + 1;
			}else if(dist[u] + 1 > mx2){
				mx2 = dist[u] + 1;
			}
		}
	}
	for(int u : g[v]){
		if(u != p){
			if(dist[u] + 1 == mx1){
				dfs2(u, v, mx2 + 1);
			}else{
				dfs2(u, v, mx1 + 1);
			}
		}
	}
	dist[v] = max(dist[v], x);
	s[comp[v]].push_back(dist[v]);
	diam[comp[v]] = max(diam[comp[v]], dist[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int iter = 0;
	memset(comp, 0, sizeof(comp));
	memset(diam, 0, sizeof(diam));
	for(int i = 1; i <= n; i++){
		if(comp[i] == 0){
			++iter;
			dfs1(i, 0, iter);
			dfs2(i, 0, 0);
		}
	}
	for(int i = 1; i <= iter; i++){
		sort(s[i].begin(), s[i].end());
		sum[i].push_back(s[i][0]);
		for(int j = 1; j < (int)s[i].size(); j++){
			sum[i].push_back(sum[i].back() + s[i][j]);
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		if(comp[u] == comp[v]){
			cout << -1 << '\n';
			continue;
		}
		u = comp[u];
		v = comp[v];
		if(mp[u].count(v)){
			cout << mp[u][v] << '\n';
			continue;
		}
		if(mp[v].count(u)){
			cout << mp[v][u] << '\n';
			continue;
		}
		int d = max(diam[u], diam[v]);
		if(s[u].size() > s[v].size())swap(u, v);
		long long total = sum[u].back()*s[v].size() + sum[v].back()*s[u].size() + s[u].size()*1LL*s[v].size();
		for(int x : s[u]){
			if(x + 1 > d)break;
			int ind = lower_bound(s[v].begin(), s[v].end(), d - x - 1) - s[v].begin();
			if(ind > 0){
				total -= sum[v][ind - 1] + (x + 1)*1LL*ind;
				total += d*1LL*ind;
			}
		}
		double answer = total;
		answer /= s[u].size();
		answer /= s[v].size();
		cout << setprecision(30) << answer << '\n';
		mp[u][v] = answer;
	}

	return 0;
}