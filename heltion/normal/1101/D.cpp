#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 240000
int a[maxn];
vector<int> G[maxn];
int sz[maxn], maxp[maxn], vis[maxn], sum, rt;
vector<int> d[maxn];
int ans = 0;
void getrt(int u, int fa){
	sz[u] = 1;
	maxp[u] = 0;
	for(int v : G[u]) if(v == fa || vis[v]) continue;
	else{
		getrt(v, u);
		sz[u] += sz[v];
		maxp[u] = max(maxp[u], sz[v]);
	}
	maxp[u] = max(maxp[u], sum - sz[u]);
	if(maxp[u] < maxp[rt]) rt = u;
}
int calc(int u, int fa, int d){
	if(a[u] % d) return 0;
	int s = 0;
	for(int v : G[u]) if(vis[v] == 0 && v != fa)
		s = max(s, calc(v, u, d));
	return s + 1;
}
void calc(int u, int d){
	vector<int> vec;
	for(int v : G[u]) if(vis[v] == 0) vec.push_back(calc(v, u, d));
	sort(vec.begin(), vec.end());
	int s = 1;
	if(vec.size()) s += vec[vec.size() - 1];
	if(vec.size() > 1) s += vec[vec.size() - 2];
	ans = max(ans, s);
}
void calc(int u){
	for(int v : d[a[u]])
		calc(u, v);
}
void solve(int u){
	vis[u] = 1;
	calc(u);
	for(int v : G[u]) if(vis[v]) continue;
	else{
		sum = sz[v];
		maxp[rt = 0] = maxn;
		getrt(v, 0);
		solve(rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 2; i < maxn; i += 1) if(d[i].size() == 0)
		for(int j = i; j < maxn; j += i) d[j].push_back(i);
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i < n; i += 1){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	maxp[rt] = sum = n;
	getrt(1, 0);
	solve(rt);
	cout << ans;
}