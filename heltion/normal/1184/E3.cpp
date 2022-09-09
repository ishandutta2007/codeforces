//Author: Heltion
//Date: 07-31-1719
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
int pa[maxn];
int getpa(int u){
	return u == pa[u] ? u : pa[u] = getpa(pa[u]);
}
struct edge{
	int u, v, w;
	bool operator < (const edge &b){
		return w < b.w;
	}
}e[maxn * 10], es[maxn * 10];
vector<pair<int, int>> G[maxn];
int fa[maxn][17], fw[maxn][17], d[maxn];
void DFS(int u){
	for(int i = 1; i < 17; i += 1){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
		fw[u][i] = max(fw[u][i - 1], fw[fa[u][i - 1]][i - 1]);
	}
	for(auto p : G[u]){
		int v = p.first, w = p.second;
		if(v != fa[u][0]){
			fa[v][0] = u;
			fw[v][0] = w;
			d[v] = d[u] + 1;
			DFS(v);
		}
	}
}
int sz[maxn], hs[maxn], top[maxn], id[maxn], di[maxn], ans[maxn * 10], idn, pans[maxn];
vector<int> L[maxn], R[maxn];
multiset<int> ms;
void DFS2(int u){
	sz[u] = 1;
	for(auto p : G[u]){
		int v = p.first;
		if(v == fa[u][0]) continue;
		DFS2(v);
		sz[u] += sz[v];
		if(sz[v] > sz[hs[u]]) hs[u] = v;
	}
}
void DFS3(int u){
	id[u] = idn += 1;
	di[idn] = u;
	if(hs[u]){
		top[hs[u]] = top[u];
		DFS3(hs[u]);
	}
	for(auto p : G[u]){
		int v = p.first;
		if(v == fa[u][0] or v == hs[u]) continue;
		DFS3(top[v] = v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(17);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) pa[i] = i;
	for(int i = 0; i < m; i += 1) cin >> e[i].u >> e[i].v >> e[i].w;
	for(int i = 0; i < m; i += 1) es[i] = e[i];
	sort(es, es + m);
	for(int i = 0; i < m; i += 1){
		if(getpa(es[i].u) != getpa(es[i].v)){
			pa[getpa(es[i].u)] = getpa(es[i].v);
			G[es[i].u].push_back(make_pair(es[i].v, es[i].w));
			G[es[i].v].push_back(make_pair(es[i].u, es[i].w));
		}
	}
	DFS(1);
	DFS2(1);
	DFS3(top[1] = 1);
	for(int i = 0; i < m; i += 1){
		int u = e[i].u, v = e[i].v;
		if(fa[u][0] == v or fa[v][0] == u) continue;
		if(d[u] < d[v]) swap(u, v);
		int dif = d[u] - d[v];
		for(int ii = 0; ii < 17; ii += 1) if((dif >> ii) & 1){
			ans[i] = max(ans[i], fw[u][ii]);
			u = fa[u][ii];
		}
		for(int ii = 16; ~ii; ii -= 1) if(fa[u][ii] != fa[v][ii]){
			ans[i] = max(ans[i], fw[u][ii]);
			u = fa[u][ii];
			ans[i] = max(ans[i], fw[v][ii]);
			v = fa[v][ii];
		}
		if(u != v){
			ans[i] = max(ans[i], fw[u][0]);
			ans[i] = max(ans[i], fw[v][0]);
		}
		u = e[i].u, v = e[i].v;
		while(top[u] != top[v]){
			if(d[top[u]] < d[top[v]]) swap(u, v);
			L[id[top[u]]].push_back(e[i].w);
			R[id[u]].push_back(e[i].w);
			u = fa[top[u]][0];
		}
		if(u != v){
			if(d[u] < d[v]) swap(u, v);
			L[id[hs[v]]].push_back(e[i].w);
			R[id[u]].push_back(e[i].w);
		}
	}
	for(int i = 2; i <= n; i += 1){
		for(int x : L[i]) ms.insert(x);
		if(ms.size()) pans[di[i]] = *ms.begin();
		else pans[di[i]] = 1e9;
		for(int x : R[i]) ms.erase(ms.find(x));
	}
	for(int i = 0; i < m; i += 1){
		int u = e[i].u, v = e[i].v;
		if(fa[u][0] == v) cout << pans[u] << "\n";
		else if(fa[v][0] == u) cout << pans[v] << "\n";
		else cout << ans[i] << "\n";
	}
	return 0;
}