#include <bits/stdc++.h>

using ll = long long;
int n,pt,x[2005],y[2005],p[2005],rk[2005],vis[2005],c;
std::vector<std::pair<int,int> > ans;

void dfs(int u,int cl) {
	if (vis[u]) return ;
	vis[u] = cl;
	dfs(p[u],cl);
}

int in(int x1,int y1) {
	if (x1 > 0) return 1;
	if (x1 <= 0) return 2;
}

int cmp(int a,int b) {
	int x1 = x[a] - x[pt], y1 = y[a] - y[pt];
	int x2 = x[b] - x[pt], y2 = y[b] - y[pt];
	if (in(x1,y1) != in(x2,y2)) return in(x1,y1) < in(x2,y2);
	return (ll) x1 * y2 - (ll) x2 * y1 > 0;
}

void perf(int x,int y) {
	std::swap(p[x],p[y]);
	ans.push_back( { x,y } );
} 

void work() {
	c = 0;
	std::memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n; ++ i)
		if (!vis[i]) dfs(i,++c);
}

int main() {
	scanf("%d",&n);
	pt = 0;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d",&x[i],&y[i],&p[i]);
		rk[i] = i;
		if (p[i] != i) pt = i;
	} 
	if (!pt) { puts("0"); return 0; }
	work();
	std::swap(rk[1],rk[pt]);
	std::sort(rk + 2,rk + n + 1,cmp);
	for (int i = 2; i <= n; ++ i) {
		int u = rk[i], v = rk[(i == n ? 2 : i + 1)];
		int x1 = x[u] - x[pt], y1 = y[u] - y[pt];
		int x2 = x[v] - x[pt], y2 = y[v] - y[pt];
		if ((ll) x1 * y2 - (ll) x2 * y1 < 0) continue;
		if (vis[u] != vis[v]) {
			perf(u,v);
			work();
		}
	}
	while (p[pt] != pt) 
		perf(pt,p[pt]);
	printf("%d\n",ans.size());
	for (auto p:ans) {
		int x = p.first, y = p.second;
		printf("%d %d\n",x,y);
	} 
	//for (int i = 1; i <= n; ++ i)  printf("%d ",p[i]);
	return 0;
}