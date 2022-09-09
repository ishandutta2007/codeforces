//Author: Heltion
//Date: 09-29-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1 << 18;
vector<int> G[maxn];
int sz[maxn];
int n, m, rt1 = 0, rt2 = 0;
void DFS(int u, int fa = 0){
	sz[u] = 1;
	for(int v : G[u]) if(v != fa){
		DFS(v, u);
		sz[u] += sz[v];
		if(sz[v] == m / 2) rt1 = u, rt2 = v;
	}
}
void DFS3(int u, int fa = 0){
	sz[u] = 1;
	for(int v : G[u]) if(v != fa){
		DFS3(v, u);
		sz[u] += sz[v];
	}
}
int ok, ans;
bool vis[maxn];
void DFS2(int u, int fa = 0, int id = 1){
	if(id <= m + 1 and id >= 1) vis[id] = true;
	else ok = 0;
	vector<int> son;
	for(int v : G[u]) if(v != fa) son.push_back(v);
	if(son.size() == 0U) return;
	if(son.size() == 1U){
		if(ans) ok = 0;
		ans = u;
		if(id * 2 + 1 <= m + 1 and id * 2 + 1 >= 1) vis[id * 2 + 1] = true;
		else ok = 0;
		DFS2(son[0], u, id * 2);
	}
	else if(son.size() == 2U){
		DFS2(son[0], u, id * 2);
		DFS2(son[1], u, id * 2 + 1);
	}
	else if(son.size() == 3U){
		if(ans) ok = 0;
		ans = u;
		sort(son.begin(), son.end(), [&](const int &x, const int &y){
			return sz[x] < sz[y];
		});
		if(id * 2 + 1 <= m + 1 and id * 2 + 1 >= 1) vis[id * 2 + 1] = true;
		else ok = 0;
		DFS2(son[2], u, id * 2);
		DFS2(son[1], u, (id * 2 + 1) * 2);
		DFS2(son[0], u, (id * 2 + 1) * 2 + 1);
	}
	else ok = 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> n;
	m = (1 << n) - 2;
	for(int i = 1, u, v; i < m; i += 1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	if(not rt1) no(0);
	vector<int> fk;
	ok = 1;
	ans = 0;
	DFS3(rt1);
	DFS2(rt1);
	for(int i = 1; i <= m + 1; i += 1) if(not vis[i]) ok = 0;
	if(ok) fk.push_back(ans);
	ok = 1;
	ans = 0;
	fill(vis, vis + maxn, false);
	DFS3(rt2);
	DFS2(rt2);
	for(int i = 1; i <= m + 1; i += 1) if(not vis[i]) ok = 0;
	if(ok) fk.push_back(ans);
	cout << fk.size() << "\n";
	sort(fk.begin(), fk.end());
	for(int x : fk) cout << x << " ";
	return 0;
}