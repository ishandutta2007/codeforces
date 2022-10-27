#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

vector<int> g[maxn];
int deg[maxn], dp[maxn][2];
vector<pair<int, int> > ans;

bool dfs(int v, int p){
	vector<int> cnt(3);
	for(int u : g[v]){
		if(u == p){
			continue;
		}
		if(!dfs(u, v)){
			return false;
		}
		if(dp[u][0]){
			if(dp[u][1])cnt[2]++;
			else cnt[0]++;
		}else{
			if(dp[u][1])cnt[1]++;
			else return false;
		}
	}
	dp[v][0] = 0;
	dp[v][1] = 0;
	if(p == -1){
		int c0 = cnt[deg[v]^0];
		int c1 = cnt[deg[v]^1];
		if(max(-cnt[2], c0 - c1 - 1) <= min(cnt[2], c0 - c1)){
			dp[v][0] = 1;
		}
		return dp[v][0]|dp[v][1];
	}
	for(int f = 0; f < 2; f++){
		int c0 = cnt[deg[v]^0];
		int c1 = cnt[deg[v]^1];
		if(deg[v] == f){
			c0++;
		}else{
			c1++;
		}
		if(max(-cnt[2], c0 - c1 - 1) <= min(cnt[2], c0 - c1)){
			dp[v][f] = 1;
		}
	}
	return dp[v][0]|dp[v][1];
}

void dfs2(int v, int p, int f){
	vector<vector<int> > vert(3);
	for(int u : g[v]){
		if(u == p){
			continue;
		}
		if(dp[u][0]){
			if(dp[u][1])vert[2].emplace_back(u);
			else vert[0].emplace_back(u);
		}else{
			if(dp[u][1])vert[1].emplace_back(u);
			else assert(false);
		}
	}
	if(p != -1){
		vert[f].emplace_back(p);
	}
	int d0 = deg[v]^0;
	int d1 = deg[v]^1;
	while(!vert[2].empty()){
		if(vert[d0].size() > vert[d1].size()){
			vert[d1].emplace_back(vert[2].back());
		}else{
			vert[d0].emplace_back(vert[2].back());
		}
		vert[2].pop_back();
	}
	int take = 0;
	while(!vert[d0].empty() || !vert[d1].empty()){
		int u;
		if(take){
			u = vert[d1].back(); vert[d1].pop_back();
		}else{
			u = vert[d0].back(); vert[d0].pop_back();
		}
		if(u == p){
			ans.emplace_back(v, p);
		}else{
			dfs2(u, v, deg[v]^take);
		}
		take ^= 1;
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		deg[i] = 0;
	}
	for(int i = 2; i <= n; i++){
		int u; cin >> u;
		int v; cin >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		deg[u] ^= 1;
		deg[v] ^= 1;
	}
	if(dfs(1, -1)){
		cout << "YES" << '\n';
		ans.clear();
		dfs2(1, -1, 0);
		for(auto x : ans){
			cout << x.first << " " << x.second << '\n';
		}
	}else{
		cout << "NO" << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}