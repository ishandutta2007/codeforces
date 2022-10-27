#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

vector<int> g[N];
int timer, p[N], c[N], k[N], match[N], chk[N], ans[N], vis[N];

bool dfs(int v){
	if(vis[v] == timer)return false;
	vis[v] = timer;
	for(int u : g[v]){
		if(match[u] == -1 || dfs(match[u])){
			match[u] = v;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	int d;
	cin >> d;
	memset(chk, 0, sizeof(chk));
	for(int i = 1; i <= d; i++){
		cin >> k[i];
		chk[k[i]] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(!chk[i]){
			g[p[i]].emplace_back(c[i]);
		}
	}
	timer = 0;
	int cur = 0;
	memset(vis, 0, sizeof(vis));
	memset(match, -1, sizeof(match));
	for(int i = d; i >= 1; i--){
		while(true){
			++timer;
			if(!dfs(cur))break;
			++cur;
		}
		ans[i] = cur;
		g[p[k[i]]].emplace_back(c[k[i]]);
	}
	for(int i = 1; i <= d; i++){
		cout << ans[i] << '\n';
	}

	return 0;
}