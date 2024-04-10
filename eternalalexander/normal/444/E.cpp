#include <bits/stdc++.h>

const int maxn = 40005;
const int maxm = maxn * 2;
const int inf = 1e8;

namespace Flow {
	int hd[maxn],cur[maxn],d[maxn],n,m,s,t,tl;
	struct edge {
		int v,nxt,c;
	}E[maxn << 1];
	
	void reset(int s1,int t1) { 
		tl = 0; s = s1; t = t1; 
		std::memset(hd,0,sizeof(hd));
		std::memset(cur,0,sizeof(cur));
		std::memset(d,0,sizeof(d));
	}
	
	int rev(int x) { return ((x-1)^1)+1;}
	
	void add_edge(int u,int v,int c) {
		E[++tl].v = v;
		E[tl].c = c;
		E[tl].nxt = hd[u];
		hd[u] = tl;
	}
	
	void addEdge(int u,int v,int c) {
		//printf("%d -> %d %intd\n",u,v,c);
		add_edge(u,v,c);
		add_edge(v,u,0);
	}
	
	int bfs() {
		std::queue<int>q; q.push(s);
		std::memcpy(cur,hd,sizeof(cur));
		std::memset(d,-1,sizeof(d)); d[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = hd[u]; i; i = E[i].nxt) {
				if (E[i].c == 0 || d[E[i].v] != -1) continue;
				d[E[i].v] = d[u] + 1;
				q.push(E[i].v);
			} 
		} return d[t] != -1;
	}
	
	int dfs(int u,int cap) {
		if ( u == t) return cap;
		int flow = 0;
		for (int i = cur[u]; i; i = E[i].nxt) {
			cur[u] = i;
			if (E[i].c == 0 || d[E[i].v] != d[u] + 1) continue;
			int f = dfs(E[i].v, std::min(cap, E[i].c) );
			E[i].c -= f; E[rev(i)].c += f;
			flow += f; cap -= f;
		} return flow;
	}
	
	int Dinic() { int ans = 0; while (bfs()) ans += dfs(s,inf); return ans; }
}

struct edge {
	int v,w,nxt;
}E[maxn<<1];

int hd[maxn],tl,sz,x[maxn],dfn[maxn],ref[maxn],vis[maxn],idx,cnt,n,u,v,w,
sumx[maxn],size[maxn],a[maxn],b[maxn];

void add_edge(int u,int v,int w) {
	E[++tl].v = v; E[tl].w = w; E[tl].nxt = hd[u]; hd[u] = tl;
}

void dfs(int u,int lim) {
	vis[u] = cnt;
	sumx[cnt] += x[u];
	size[cnt] += 1;
	for (int i = hd[u]; i; i = E[i].nxt) {
		int v = E[i].v, w = E[i].w;
		if (vis[v]) continue;
		if (w < lim) dfs(v,lim);
	}
}

int newnode() { return ++sz; }
	
int check(int lim) {
	std::memset(vis,0,sizeof(vis)); 
	std::memset(size,0,sizeof(size));
	std::memset(sumx,0,sizeof(sumx));
	idx = cnt = 0;
	for (int i = 1; i <= n; ++ i) if (!vis[i]) { ++cnt; dfs(i,lim); }
	int s = n * 5 + 1, t = n * 5 + 2;
	Flow::reset(s,t);
	for (int i = 1; i <= cnt; ++ i) {
		Flow::addEdge(s,i,size[i]);
		Flow::addEdge(i+cnt,t,sumx[i]);
	}
	sz = cnt * 2;
	for (int i = 1; i <= cnt; ++ i) {
		a[i] = newnode(), b[i] = newnode();
		Flow::addEdge(a[i],i+cnt,inf);
		Flow::addEdge(b[i],i+cnt,inf);
	}
	for (int i = 2; i <= cnt; ++ i) Flow::addEdge(a[i],a[i-1],inf);
	for (int i = 1; i < cnt; ++ i) Flow::addEdge(b[i],b[i+1],inf);
	for (int i = 1; i <= cnt; ++ i) {
		if (i > 1) Flow::addEdge(i,a[i-1],inf);
		if (i < n) Flow::addEdge(i,b[i+1],inf);
	} return Flow::Dinic() == n;
}
	

int main() {
	scanf("%d",&n);
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	} for (int i = 1; i <= n; ++ i) scanf("%d",&x[i]);
	int l = 1, r = 1e4, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} printf("%d",ans);
	return 0;
}