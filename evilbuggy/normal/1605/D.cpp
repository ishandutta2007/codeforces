#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

vector<int> g[maxN];
int ind[maxN], ans[maxN];

void dfs(int v, int p, int b){
	ind[v] = b;
	for(int u : g[v]){
		if(u != p){
			dfs(u, v, b^1);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	for(int i = 2; i <= n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 1, 1);
	vector<vector<int> > ver(2);
	for(int i = 1; i <= n; i++){
		ver[ind[i]].emplace_back(i);
	}
	for(int r = n; r >= 1; r--){
		int l = r;
		for(int i = 20; i >= 0; i--){
			if((l >> i) & 1){
				l = (1 << i);
				break;
			}
		}
		int flg = 0;
		if((int)ver[0].size() < r - l + 1){
			flg = 1;
		}
		assert((int)ver[flg].size() >= r - l + 1);
		for(int i = l; i <= r; i++){
			ans[ver[flg].back()] = i; ver[flg].pop_back();
		}
		r = l;
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
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