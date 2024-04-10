#include <bits/stdc++.h>

const int maxn = 4e4 + 20;

using ll = long long;
ll INF = 0x3f3f3f3f3f3f3f3f;
ll inf = 1e16;

int n,m;
ll big = 1e9,ans;
ll w[maxn];

namespace Flow {
	int hd[maxn],cur[maxn],d[maxn],n,m,s,t,tl;
	struct edge {
		int v,nxt;
		ll c;
	}E[maxn << 1];
	
	void reset(int s1,int t1) { 
		tl = 0; s = s1; t = t1; 
		std::memset(hd,0,sizeof(hd));
		std::memset(cur,0,sizeof(cur));
		std::memset(d,0,sizeof(d));
	}
	
	int rev(int x) { return ((x-1)^1)+1;}
	
	void add_edge(int u,int v,ll c) {
		E[++tl].v = v;
		E[tl].c = c;
		E[tl].nxt = hd[u];
		hd[u] = tl;
	}
	
	void addEdge(int u,int v,ll c) {
	//	printf("%d -> %d %lld\n",u,v,c);
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
	
	ll dfs(int u,ll cap) {
		if ( u == t) return cap;
		ll flow = 0;
		for (int i = cur[u]; i; i = E[i].nxt) {
			cur[u] = i;
			if (E[i].c == 0 || d[E[i].v] != d[u] + 1) continue;
			ll f = dfs(E[i].v, std::min(cap, E[i].c) );
			E[i].c -= f; E[rev(i)].c += f;
			flow += f; cap -= f;
		} return flow;
	}
	
	ll Dinic() { ll ans = 0; while (bfs()) ans += dfs(s,inf); return ans; }
}

int main() {
	scanf("%d",&n);
	int s = n * 3, t = n * 3 + 1;
	Flow::reset(s,t);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&m);
		for (int j = 1; j <= m; ++ j) {
			int u; scanf("%d",&u);
			Flow::addEdge(i,u+n,big);
		} 
	} for (int i = 1; i <= n; ++ i) {
		scanf("%lld",&w[i]); w[i] = big - w[i];
		if (w[i] > 0) { ans += w[i]; Flow::addEdge(s,i,w[i]); }
		else Flow::addEdge(i,t,-w[i]);
		Flow::addEdge(i+n,t,big);
	}// printf("%lld\n",ans);
	printf("%lld",- ans + Flow::Dinic());
	return 0;
}