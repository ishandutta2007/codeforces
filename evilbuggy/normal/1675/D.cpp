#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

vector<int> g[maxn], f[maxn];

int dfs(int v){
	int w = v;
	for(int u : g[v]){
		w = dfs(u);
	}
	f[w].emplace_back(v);
	return w;
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		f[i].clear();
	}
	int root = -1;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		if(x != i){
			g[x].emplace_back(i);
		}else{
			root = i;
		}
	}
	assert(root != -1);

	dfs(root);
	vector<vector<int> > ans;
	for(int i = 1; i <= n; i++){
		if(f[i].empty())continue;
		reverse(f[i].begin(), f[i].end());
		ans.push_back(f[i]);
	}
	cout << ans.size() << '\n';
	for(auto vec : ans){
		cout << (int)vec.size() << '\n';
		for(auto u : vec){
			cout << u << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}