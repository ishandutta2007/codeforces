#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

vector<int> g[maxn];
int degi[maxn], dego[maxn], len[maxn];

int dfs(int u){
	if(len[u])return len[u];
	if(dego[u] == 1)return len[u] = 1;
	
	int ret = 1;
	for(int v : g[u]){
		if(degi[v] > 1){
			ret = max(ret, 1 + dfs(v));
		}
	}
	return len[u] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	memset(degi, 0, sizeof(degi));
	memset(dego, 0, sizeof(dego));
	for(int i = 1; i <= m; i++){
		int u; cin >> u;
		int v; cin >> v;
		g[u].emplace_back(v);
		dego[u]++;
		degi[v]++;
	}
	int ans = 0;
	memset(len, 0, sizeof(len));
	for(int i = 1; i <= n; i++){
		ans = max(ans, dfs(i));
	}
	cout << ans << '\n';

	return 0;
}