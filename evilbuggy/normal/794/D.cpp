#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
vector<int> g[N], s[N];
int a[N], b[N], ind[N], ans[N], cnt[N];

void dfs(int v, int p, int x){
	ans[v] = x;
	cnt[x] = s[v].size();
	for(int u : g[v]){
		if(u != p)dfs(u, v, x + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i];
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
	}
	int iter = 0;
	map<vector<int>, int> indMap;
	for(int i = 1; i <= n; i++){
		g[i].emplace_back(i);
		sort(g[i].begin(), g[i].end());
		if(!indMap.count(g[i])){
			indMap[g[i]] = ++iter;
		}
		ind[i] = indMap[g[i]];
		s[ind[i]].emplace_back(i);
	}
	if(iter == 1){
		cout << "YES" << '\n';
		for(int i = 1; i <= n; i++){
			cout << 1 << " ";
		}
		cout << '\n';
		exit(0);
	}
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	set<pair<int, int> > edges;
	for(int i = 1; i <= m; i++){
		int u = ind[a[i]];
		int v = ind[b[i]];
		if(u == v)continue;
		if(u > v)swap(u, v);
		edges.insert({u, v});
	}
	for(auto x : edges){
		g[x.first].emplace_back(x.second);
		g[x.second].emplace_back(x.first);
	}
	int endpoint = -1;
	for(int i = 1; i <= iter; i++){
		if(g[i].size() > 2){
			cout << "NO" << '\n';
			exit(0);
		}
		if(g[i].size() == 1)endpoint = i;
	}
	if(endpoint == -1){
		cout << "NO" << '\n';
		exit(0);
	}
	dfs(endpoint, 0, 1);
	long long total = 0;
	for(int i = 1; i <= iter; i++){
		total += cnt[i]*1LL*(cnt[i] - 1)/2;
		if(i < iter)total += cnt[i]*1LL*cnt[i + 1];
	}
	if(total != m){
		cout << "NO" << '\n';
		exit(0);
	}
	cout << "YES" << '\n';
	for(int i = 1; i <= n; i++){
		cout << ans[ind[i]] << " ";
	}
	cout << '\n';


	return 0;
}