#include <bits/stdc++.h>

const int maxn = 1e6 + 17;
int vis[maxn][2],siz[maxn],hd[maxn],tl,cnt,n;
char s[maxn];

struct edge {
	int v,w,nxt;
}E[maxn<<1];
void add_edge(int u,int v,int w){E[++tl].v=v;E[tl].w=w;E[tl].nxt=hd[u];hd[u]=tl;}
void dfs(int u,int c,int id) {
	vis[u][c] = id; siz[id] ++;
	for (int i = hd[u]; i; i = E[i].nxt) {
		int w = E[i].w, v = E[i].v;
		if (w != c) continue;
		if (vis[v][c^1]) continue;
		dfs(v,c^1,id);
	}
}

void solve() {
	tl = cnt = 0;
	scanf("%d%s",&n,s+1);
	for (int i = 0; i <= n; ++ i) {
		vis[i][0] = vis[i][1] = hd[i] =  0;
	}
	for (int i = 0; i <= (n + 2) * 2; ++ i) { siz[i] = 0; }
	for (int i = 1; i <= n; ++ i) {
		int c;
		if (s[i] == 'L') c = 0;
		else c = 1;
		add_edge(i,i-1,c);
		add_edge(i-1,i,c^1);
	}
	cnt = 0;
//	std::memset(vis,0,sizeof(vis));
//	std::memset(siz,0,sizeof(siz));
	for (int i = 0; i <= n; ++ i) {
		if (!vis[i][0]) {
			++cnt;
			dfs(i,0,cnt);
		}
		printf("%d ",siz[vis[i][0]]);
	} puts("");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}