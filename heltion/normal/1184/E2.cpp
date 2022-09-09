//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200000;
int pa[maxn];
int getpa(int u){
	return u == pa[u] ? u : pa[u] = getpa(pa[u]);
}
struct edge{
	int u, v, w;
	bool operator < (const edge &b){
		return w < b.w;
	}
}e[maxn], es[maxn];
vector<pair<int, int>> G[maxn];
int fa[maxn][20], fw[maxn][20], d[maxn];
void DFS(int u){
	for(int i = 1; i < 20; i += 1){
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
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
	for(int i = 0; i < m; i += 1){
		int u = e[i].u, v = e[i].v;
		if(fa[u][0] == v or fa[v][0] == u) continue;
		int ans = 0;
		if(d[u] < d[v]) swap(u, v);
		int dif = d[u] - d[v];
		for(int i = 0; i < 20; i += 1) if((dif >> i) & 1){
			ans = max(ans, fw[u][i]);
			u = fa[u][i];
		}
		for(int i = 19; ~i; i -= 1) if(fa[u][i] != fa[v][i]){
			ans = max(ans, fw[u][i]);
			u = fa[u][i];
			ans = max(ans, fw[v][i]);
			v = fa[v][i];
		}
		if(u != v){
			ans = max(ans, fw[u][0]);
			ans = max(ans, fw[v][0]);
		}
		cout << ans << "\n";
	}
	return 0;
}