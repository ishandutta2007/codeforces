#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
vector<int> H[maxn], G[maxn], g[maxn], h[maxn];
int p[maxn], par[maxn], d[maxn];
int gpar(int u){
	return u == par[u] ? u : par[u] = gpar(par[u]);
}
int dep[maxn], s[maxn];
void DFS(int u){
	s[dep[u]] = u;
	for(int y : g[u]) if(dep[y] < dep[u] and s[dep[y]] == y){
		cout << "0\n";
		exit(0);
	}
	for(int v : H[u]){
		dep[v] = dep[u] + 1;
		DFS(v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1){
		cin >> p[i];
		H[p[i]].push_back(i);
		par[i] = i;
	}
	for(int i = 1; i <= k; i += 1){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		if(gpar(x) == y){
			cout << "0\n";
			return 0;
		}
		par[y] = x;
	}
	DFS(0);
	for(int i = 1; i <= n; i += 1){
		int u = gpar(p[i]), v = gpar(i);
		if(u != v){
			G[u].push_back(v);
			d[v] += 1;
		}
	}
	vector<int> ans;
	queue<int> q;
	q.push(0);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int p = u; p; p = g[p].empty() ? 0 : g[p][0]) ans.push_back(p);
		for(int v : G[u]) if(not(d[v] -= 1)) q.push(v);
	}
	if(ans.size() != n) cout << "0\n";
	else for(int x : ans) cout << x << " ";
	return 0;
}