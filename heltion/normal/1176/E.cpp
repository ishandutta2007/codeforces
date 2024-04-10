//Author: Heltion
//Date: 2019-06-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
vector<int> G[maxn];
int d[maxn];
void DFS(int u){
	for(int v : G[u]) if(not d[v]){
		d[v] = d[u] + 1;
		DFS(v);
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1){
		d[i] = 0;
		G[i].clear();
	}
	for(int i = 1; i <= m; i += 1){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(d[1] = 1);
	int c[2] = {0, 0};
	for(int i = 1; i <= n; i += 1) c[d[i] & 1] += 1;
	if(c[0] < c[1]) {
		cout << c[0] << "\n";
		for(int i = 1; i <= n; i += 1) if(!(d[i] & 1)) cout << i << " ";
		cout << "\n";
	}
	else{
		cout << c[1] << "\n";
		for(int i = 1; i <= n; i += 1) if(d[i] & 1) cout << i << " ";
		cout << "\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int t;
	for(cin >> t; t; t -= 1) solve();
	return 0;
}