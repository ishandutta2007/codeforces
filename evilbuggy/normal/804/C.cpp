#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int ans[N], chk[N];
vector<int> g[N], s[N];

int dfs(int v, int p){
	for(int x : s[v]){
		if(ans[x])chk[ans[x]] = 1;
	}
	int iter = 1;
	for(int x : s[v]){
		if(!ans[x]){
			while(chk[iter])iter++;
			ans[x] = iter; iter++;
		}
	}
	for(int x : s[v]){
		chk[ans[x]] = 0;
	}
	int ret = s[v].size();
	for(int u : g[v]){
		if(u != p)ret = max(ret, dfs(u, v));
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		s[i].resize(k);
		for(int &x : s[i]){
			cin >> x;
		}
	}
	for(int i = 2; i <= n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(chk, 0, sizeof(chk));
	memset(ans, 0, sizeof(ans));
	int total =  dfs(1, 0);
	if(!total)total = 1;

	cout << total << '\n';
	for(int i = 1; i <= m; i++){
		if(!ans[i])ans[i] = 1;
		cout << ans[i] << ' ';
	}
	cout << '\n';


	return 0;
}