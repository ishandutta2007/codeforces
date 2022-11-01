#include <bits/stdc++.h>
#define N 1000500
using namespace std;
struct Edge{int b,v,n;}e[N];
int h[N],d[N],cur[N],x[N],y[N],o[N],rt,n,m,tot,cnt;
bool flag,vis[N];

void link(int a,int b,int v) {
	e[++cnt] = (Edge){b,v,h[a]}, h[a] = cnt;
}
inline int rd() {int r;scanf("%d",&r);return r;}

void dfs(int u,int f) {
	vis[u] = 1;
	for (int i=h[u];i;i=e[i].n) {
		int v = e[i].b;
		if (vis[v]) continue;
		dfs(v, e[i].v);
	}
	
	if (d[u] != -1 && cur[u] != d[u]) {
		if (!f) {
			flag = 0;
			return ;
		}
		if (x[f] == u) swap(x[f], y[f]);
		cur[ x[f] ] ^= 1;
		o[++tot] = f;
	}
}

int main() {
	rt = 1; flag = 1;
	n = rd(), m = rd();
	for (int i=1;i<=n;i++) d[i] = rd();
	for (int i=1;i<=m;i++) {
		int a = rd(), b = rd();
		x[i] = a, y[i] = b;
		link(a, b, i);
		link(b, a, i);
	}
	
	for (int i=1;i<=n;i++) if (d[i] == -1) rt = i;
	
	dfs(rt, 0);
	if (!flag)
		puts("-1");
	else {
		printf("%d\n",tot);
		sort(o+1,o+tot+1);
		for (int i=1;i<=tot;i++) printf("%d\n",o[i]);
	}
	return 0;
}