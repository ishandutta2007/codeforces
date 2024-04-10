#include <bits/stdc++.h>
#define N 5050
using namespace std;

#define U e[_][0]
#define V e[_][1]

int dis[N],e[N][2],vis[N],vv[N][2];
int n,m;
inline int rd() {int r;scanf("%d",&r);return r;}
void dfs(int u,int t) {
	vv[u][t] = 1;
	for (int _=1;_<=m;_++) if (e[_][t]==u && !vv[ e[_][t^1] ][t]) dfs( e[_][t^1], t );
}

int main() {
	n = rd(), m = rd();
	for (int _=1;_<=m;_++) U = rd(), V = rd();
	dfs(1,0), dfs(n,1);
	for (int _=1;_<=n;_++) vv[_][0] && vv[_][1] ? vis[_] = 1 :0;
	for (int _=1;_<=n;_++)
		for (int i=1;i<=m;i++) if (vis[e[i][0]] && vis[e[i][1]]) {
			int u = e[i][0], v = e[i][1];
			dis[u] = min(dis[v]+2, dis[u]);
			dis[v] = min(dis[u]-1, dis[v]);
		}
	for (int _=1;_<=m;_++) if (vis[U] && vis[V]){
		int x = dis[U] - dis[V];
		if (x!=1 && x!=2) return puts("No"), 0;
	}
	puts("Yes");
	for (int _=1;_<=m;_++) printf("%d\n",max(min( dis[U]-dis[V],2 ), 1));
	return 0;
}