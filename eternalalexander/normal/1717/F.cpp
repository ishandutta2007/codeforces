#include <bits/stdc++.h>

const int maxn = 40005;
const int maxm = 100005;
typedef long long ll;

namespace Flow {
	const ll inf = 1e18;
	int hd[maxn],cur[maxn],tl,dis[maxn],s,t;
	struct edge {
		int v,c,nxt;
	} E[maxm << 2];
	void addEdge(int u,int v,int c) { E[++tl].v=v; E[tl].c=c; E[tl].nxt=hd[u]; hd[u]=tl; }
	void add_edge(int u,int v,int c) {
		addEdge(u,v,c);
		addEdge(v,u,0);
	} int rev(int x) { return ( (x - 1) ^ 1 ) + 1; }
	int bfs() {
		std::queue<int>q;
		std::memcpy(cur,hd,sizeof(cur));
		std::memset(dis,63,sizeof(dis));
		dis[s] = 0; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = hd[u]; i; i = E[i].nxt) {
				if (E[i].c == 0) continue;
				if (dis[E[i].v] > dis[u] + 1) {
					dis[E[i].v] = dis[u] + 1;
					q.push(E[i].v);
				}
			} 
		} 
		return dis[t] <= (int)(1e7);
	} ll dfs(int u,ll cap) {
		if (u == t) return cap;
		ll flow = 0;
		for (int i = cur[u]; i; i = E[i].nxt) {
			cur[u] = i;
			int v = E[i].v, c = E[i].c;
			if (c == 0 || ( dis[v] != dis[u] + 1 ) )
				continue;
			ll f = dfs(v,std::min((ll) E[i].c,cap));
			E[i].c -= f; E[rev(i)].c += f;
			cap -= f; flow += f;
			if (!cap) return flow;
		} return flow;
	} 
	ll Dinic() { 
		ll ans = 0;
		while (bfs()) ans += dfs(s,inf);
		return ans;
	}
}

int n,m,s[maxn],a[maxn],c[maxn],d[maxn],u[maxn],v[maxn],eu[maxn],ev[maxn];

int AddEdge(int u,int v,int l,int r) {
	Flow::add_edge(u,v,r - l);
	int res = Flow::tl - 1; 
	d[u] -= l; d[v] += l;
	return res;
}

int Run() {
	int s = n + m + 3, t = n + m + 4;
	Flow::s = s; Flow::t = t;
	std::vector<int>v;
	for (int i = 1; i <= n + m + 2; ++ i) {
		if (d[i] > 0) { Flow::add_edge(s,i,d[i]); v.push_back(Flow::tl - 1); }
		if (d[i] < 0) { Flow::add_edge(i,t,-d[i]); v.push_back(Flow::tl - 1); }
	} 
	Flow::Dinic();
	for (int e:v) if (Flow::E[e].c) return 0;
	return 1;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) scanf("%d",&s[i]);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	int s1 = n + m + 1, t1 = n + m + 2;
	AddEdge(t1,s1,0,n+m);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d",&u[i],&v[i]);
		eu[i] = AddEdge(i,u[i]+m,0,1);
		ev[i] = AddEdge(i,v[i]+m,0,1);
		AddEdge(s1,i,1,1);
		c[u[i]] ++; c[v[i]] ++;
	} 
	for (int i = 1; i <= n; ++ i) {
		if (!s[i]) AddEdge(i + m,t1,0,n+m);
		else {
			if ( ( a[i] + c[i] ) % 2 ) { puts("NO"); return 0; }
			AddEdge(i + m,t1,(a[i] + c[i]) / 2,(a[i] + c[i]) / 2);
		}
	} if (Run()) {
		puts("YES");
		for (int i = 1; i <= m; ++ i) {
			if (!Flow::E[eu[i]].c) printf("%d %d\n",v[i],u[i]);
			else printf("%d %d\n",u[i],v[i]);
		}
	} else puts("NO");
	return 0;
}