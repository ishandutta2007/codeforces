//Author: Heltion
//Date: 2019-06-03
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 240000;
vector<int> G[maxn];
int dep, nxt;
int sz[maxn], f[maxn], d[maxn], ok[maxn];
vector<int> ans;
void DFS1(int u, int fa = 0){
	f[u] = fa;
	if(d[u] == dep) ok[u] = sz[u] = 1;
	for(int v : G[u]) if(v != f[u]){
		d[v] = d[u] + 1;
		DFS1(v, u);
		sz[u] += sz[v];
	}
}
void DFS2(int u){
	if(sz[u] == 1){
		nxt = u;
		return;
	}
	int maxv = 0;
	for(int v : G[u]) if(v != f[u])
		if(sz[v] > sz[maxv]) maxv = v;
	if(maxv) DFS2(maxv);
}
void DFS3(int u, int d, int fa){
	if(d) ok[u] = 0;
	for(int v : G[u]) if(v != fa) DFS3(v, d - 1, u);
}
void DFS4(int u){
	sz[u] = ok[u];
	for(int v : G[u]) if(f[u] != v){
		DFS4(v);
		sz[u] += sz[v];
	}
}
void DFS5(int u, int x){
	if(u == x)return;
	ok[u] = 0;
	for(int v : G[u]) if(f[u] != v){
		DFS5(v, x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i < n; i += 1){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << "d 1" << endl;
	cin >> dep;
	DFS1(1);
	for(int i = 1; i <= n; i += 1) if(ok[i]) ans.push_back(i);
	int u = 1;
	while(true){
		if(ans.size() == 1){
			cout << "! " << ans[0];
			return 0;
		}
		if(d[u] == dep){
			cout << "! " << u;
			return 0;
		}
		int maxv = 0, cnt = 0;
		for(int v : G[u]) if(v != f[u]){
			if(sz[v] > sz[maxv]) maxv = v;
			if(sz[v]) cnt += 1;
		}
		if(cnt == 1){
			u = maxv;
			continue;
		}
		if(sz[maxv] <= sz[u] / 2){
			cout << "s " << u << endl;
			cin >> u;
			DFS5(1, u);
			DFS4(1);
			continue;
		}
		DFS2(maxv);
		cout << "d " << nxt << endl;
		int dd;
		cin >> dd;
		DFS3(nxt, dd, 0);
		DFS4(1);
		ans.clear();
		for(int i = 1; i <= n; i += 1) if(ok[i]) ans.push_back(i);
	}
	return 0;
}