#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000*1000 + 5;

vector<int> g[maxn], child[maxn];
int a[maxn], b[maxn], vis[maxn], color[maxn], cnt1[maxn], cnt2[maxn];

void dfs(int v, int pi, int cl){
	vis[v] = 1;
	cnt1[v] = 0;
	cnt2[v] = 0;
	color[v] = cl;
	for(int i : g[v]){
		int u = a[i]^b[i]^v;
		if(i == pi)continue;
		if(vis[u] == 0){
			dfs(u, i, cl^1);
			cnt1[v] += cnt1[u];
			cnt2[v] += cnt2[u];
			child[v].emplace_back(u);
		}else if(vis[u] == 1){
			cnt1[v]++;
			if(color[v] == color[u])cnt2[v]++;
		}else{
			cnt1[v]--;
			if(color[v] == color[u])cnt2[v]--;
		}
	}
	vis[v] = 2;
}

void change(int v){
	color[v] ^= 1;
	for(int u : child[v]){
		change(u);
	}
}

bool check(int n, int m){
	int u = -1;
	for(int i = 1; i <= m; i++){
		if(color[a[i]] == color[b[i]]){
			if(u != -1)return false;
			u = a[i];
		}
	}
	if(u != -1 && color[u] == 0){
		for(int i = 1; i <= n; i++){
			color[i] ^= 1;
		}
	}
	cout << "YES" << '\n';
	for(int i = 1; i <= n; i++){
		cout << color[i];
	}
	cout << '\n';
	return true;
}

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	for(int i = 1; i <= n; i++){
		g[i].clear(); child[i].clear();
		vis[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		cin >> b[i];
		g[a[i]].emplace_back(i);
		g[b[i]].emplace_back(i);
	}
	dfs(1, 0, 0);
	if(check(n, m))return;
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(color[a[i]] == color[b[i]])cnt++;
	}
	for(int v = 2; v <= n; v++){
		int cur = cnt - cnt2[v] + cnt1[v] - cnt2[v];
		if(cur == 0){
			change(v);
			if(color[v] == 0){
				for(int i = 1; i <= n; i++){
					color[i] ^= 1;
				}
			}
			cout << "YES" << '\n';
			for(int i = 1; i <= n; i++){
				cout << color[i];
			}
			cout << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}