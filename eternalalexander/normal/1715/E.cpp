#include <bits/stdc++.h>

using ll = long long;
const ll inf = 1e14;
const int maxn = 2e5 + 222;

int n,m,k,u,v,w,hd[maxn],tl,vis[maxn];
ll f[maxn],d[maxn],x[maxn],y[maxn];
struct edge {
	int v,nxt;ll w;
}E[maxn<<2];
void add_edge(int u,int v,ll w) {
	E[++tl].v = v; E[tl].w = w;
	E[tl].nxt = hd[u]; hd[u] = tl;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	} 
	for (int i = 1; i <= n; ++ i) d[i] = inf;
	d[1] = 0; 
	std::priority_queue<std::pair<ll,int> >q; 
		for (int i = 1; i <= n; ++ i) { q.push({-d[i],i}); vis[i] = 0; }
		while (!q.empty()) {
			auto x = q.top(); q.pop();
			int u = x.second; 
			if (vis[u]) continue;
			vis[u] = 1;
			for (int i = hd[u]; i; i = E[i].nxt) {
				int v = E[i].v; ll w = E[i].w;
				if (d[u] + w < d[v]) {
					d[v] = d[u] + w;
					if (!vis[v]) q.push({-d[v],v});
				}
			}
		} 
	for (int p = 1; p <= k; ++ p) {
		for (int i = 1; i <= n; ++ i) { f[i] = d[i] + (ll) i * i; d[i] = inf; }
		d[1] = 0;
		int tl = 0;
		for (int i = 1; i <= n; ++ i) {
			while (tl > 1 && (__int128)(f[i] - y[tl]) * (x[tl] - x[tl-1]) <= (__int128)(y[tl] - y[tl-1]) * (i - x[tl]) ) tl --;
			x[++tl] = i; y[tl] = f[i];
		} 
		int fr = 1;
		for (int i = 1; i <= n; ++ i) {
			ll k = 2 * i;
			while (fr < tl && ( (y[fr+1] - y[fr]) <= k * (x[fr+1] - x[fr]))) fr ++;
			d[i] = std::min(d[i],(ll)i * i + y[fr] - 2 * i * x[fr]);
		}
		std::priority_queue<std::pair<ll,int> >q; 
		for (int i = 1; i <= n; ++ i) { q.push({-d[i],i}); vis[i] = 0; }
		while (!q.empty()) {
			auto x = q.top(); q.pop();
			int u = x.second; 
			if (vis[u]) continue;
			vis[u] = 1;
			for (int i = hd[u]; i; i = E[i].nxt) {
				int v = E[i].v; ll w = E[i].w;
				if (d[u] + w < d[v]) {
					d[v] = d[u] + w;
					if (!vis[v]) q.push({-d[v],v});
				}
			}
		} 
		//for (int i = 1; i <= n; ++ i) printf("%lld ",d[i]); puts("<");
	} for (int i = 1; i <= n; ++ i) printf("%lld ",d[i]);
	return 0;
}