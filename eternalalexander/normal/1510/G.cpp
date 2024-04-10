#include <bits/stdc++.h>

const int maxn = 105;

int d[maxn],fa[maxn],son[maxn],p[maxn],n,k,vis[maxn],rk[maxn];
std::vector<int>ch[maxn],vec;

int dfs(int u,int f) {
	d[u] = d[f] + 1;
	fa[u] = f;
	int res = u;
	for (int v:ch[u]) {
		int x = dfs(v,u);
		if (d[x] > d[res]) res = x;
	} return res;
}

void dfs1(int u) {
	if (!vis[u]) return;
	vec.push_back(u);
	for (int v:ch[u]) {
		if (vis[v]) {
			dfs1(v);
			vec.push_back(u);
		}
	}
}		

void solve() {
	scanf("%d%d",&n,&k);
	vec.clear();
	for (int i = 1; i <= n; ++ i) ch[i].clear();
	std::memset(vis,0,sizeof(vis));
	std::memset(son,0,sizeof(son));
	for (int i = 2; i <= n; ++ i) {
		scanf("%d",&p[i]);
		ch[p[i]].push_back(i);
	}
	int u = dfs(1,0);
	while (d[u] > k) u = fa[u];
	k -= d[u];
	int x = u;
	while (x) { vis[x] = 1; son[fa[x]] = x; x = fa[x]; }
	for (int i = 1; i <= n; ++ i) rk[i] = i;
	std::sort(rk+1,rk+n+1,[](int a,int b) { return d[a] < d[b]; });
	for (int i = 1; i <= n; ++ i) {
		int u = rk[i];
		if ((!vis[u]) && k > 0) { vis[u] = 1; k --; }
	}
	x = 1;
	while (x != u) {
		vec.push_back(x);
		for (int v:ch[x]) if (vis[v] && (v != son[x])) { dfs1(v); vec.push_back(x); }
		x = son[x];
	} vec.push_back(u);
	printf("%d\n",(int)vec.size() - 1);
	for (int x:vec) printf("%d ",x);
	puts("");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}