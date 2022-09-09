#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(){printf("NO"); exit(0);}
constexpr int maxn = 240000;
struct{int u, v;}e[maxn];
int f[maxn];
int gf(int u){
	return f[u] == u ? u : f[u] = gf(f[u]);
}
bool vis[maxn];
vector<int> G[maxn];
set<int> s;
void DFS(int u = 1){
	vis[u] = true;
	for(int v : G[u])
		if(not vis[v]){
			DFS(v);
			if(u == 1) s.insert(v);
		}
}
int main(){
	int n, m, D, d = 0;
	scanf("%d %d %d", &n, &m, &D);
	for(int i = 0; i < m; i += 1){ 
		scanf("%d %d", &e[i].u, &e[i].v);
		G[e[i].u].push_back(e[i].v);
		G[e[i].v].push_back(e[i].u);
		if(e[i].u > e[i].v) swap(e[i].u, e[i].v);
		if(e[i].u == 1) d += 1;
	}
	for(int i = 1; i <= n; i += 1) f[i] = i;
	if(d < D) no();
	DFS();
	if(D < s.size()) no();
	puts("YES");
	for(int x : s){
		printf("1 %d\n", x);
		f[x] = 1;
	}
	for(int i = 0, j = D - s.size(); i < m and j; i += 1)
		if(e[i].u == 1 and not s.count(e[i].v)){
			printf("1 %d\n", e[i].v);
			f[e[i].v] = 1;
			j -= 1;
		}
	for(int i = 0; i < m; i += 1) if(e[i].u != 1){
		int u = gf(e[i].u), v = gf(e[i].v);
		if(u != v){
			printf("%d %d\n", e[i].u, e[i].v);
			f[u] = v;
		}
	}
}