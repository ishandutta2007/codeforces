#include <bits/stdc++.h>
using namespace std;

const int K = 26;
const int N = 300005;

vector<int> g[N];
int ch[N], c[N], dif[N], tree[N][K];

int insert(int v, int u){
	if(tree[v][ch[u]] == -1){
		tree[v][ch[u]] = u;
		return 0;
	}
	int ret = 1;
	for(int i = 0; i < K; i++){
		if(tree[u][i] != -1){
			ret += insert(tree[v][ch[u]], tree[u][i]);
		}
	}
	return ret;
}

void dfs(int v, int p){
	dif[v] = 1;
	int bg = -1;
	for(int u : g[v]){
		if(u == p)continue;
		dfs(u, v);
		dif[v] += dif[u];
		if(bg == -1 || dif[bg] < dif[u])bg = u;
	}
	if(bg == -1)return;
	dif[v] -= insert(v, bg);
	for(int u : g[v]){
		if(u == p || u == bg)continue;
		dif[v] -= insert(v, u);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++){
		char tmp;
		cin >> tmp;
		ch[i] = tmp - 'a';
	}
	memset(tree, -1, sizeof(tree));
	for(int i = 2; i <= n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	int mx = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		mx  = max(mx, c[i] + dif[i]);
	}
	cout << mx << '\n';
	for(int i = 1; i <= n; i++){
		if(mx == c[i] + dif[i]){
			cnt++;
		}
	}
	cout << cnt << '\n';
	

	return 0;
}