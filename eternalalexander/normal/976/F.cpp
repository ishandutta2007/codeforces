#include <bits/stdc++.h>
#define maxn 20005
#define maxm 300005
const int inf = 1e9;
int hd[maxn],cur[maxn],d[maxn],n1,n2,dgr[maxn],m,s,t,tl,u[maxn],v[maxn],I1[maxn],I2[maxn],id[maxn],vis[maxn],m1[maxn],m2[maxn];
std::set<int>S1[maxn],S2[maxn];
struct edge {
	int v,c,nxt;
}E[maxm << 1];

int rev(int x) { return ((x-1)^1)+1;}

void add_edge(int u,int v,int c) {
	E[++tl].v = v;
	E[tl].c = c;
	E[tl].nxt = hd[u];
	hd[u] = tl;
}

int addEdge(int u,int v,int c) {
	int id = tl+1;
	add_edge(u,v,c);
	add_edge(v,u,0);
	return id;
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

int main() {
	scanf("%d%d%d",&n1,&n2,&m);
	s = n1 + n2 + 1, t = n1 + n2 + 2;
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d",&u[i],&v[i]);
		id[i] = addEdge(u[i],v[i]+n1,1);
		dgr[u[i]]++; dgr[v[i]+n1]++;
		S1[u[i]].insert(i);
		S2[v[i]].insert(i);
	} int min = 1e9;
	for (int i = 1; i <= n1; ++ i) { I1[i] = addEdge(s,i,0); min = std::min(min,dgr[i]); }
	for (int i = 1; i <= n2; ++ i) { I2[i] = addEdge(i+n1,t,0); min = std::min(min,dgr[i+n1]); }
	puts("0");
	int ans = 0;
	for (int i = 1; i <= min; ++ i) {
		for (int j = 1; j <= n1; ++ j) E[I1[j]].c++;
		for (int j = 1; j <= n2; ++ j) E[I2[j]].c++;
		ans += Dinic();
		printf("%d ",(n1+n2)*i-ans);
		for (int j = 1; j <= n1; ++ j) m1[j] = i;
		for (int j = 1; j <= n2; ++ j) m2[j] = i;
		std::memset(vis,0,sizeof(vis));
		for (int j = 1; j <= m; ++ j) {
			if (E[id[j]].c==0) {
				m1[u[j]]--; m2[v[j]]--;
				printf("%d ",j);
				vis[j] = 1;
			}
		} for (int i = 1; i<=n1;++i){
			for(int x:S1[i]){
				if (!m1[i])break;
				if(vis[x])continue;
				vis[x]=1;
				printf("%d ",x);
				m1[i]--;
			}
		}for (int i = 1; i<=n2;++i){
			for(int x:S2[i]){
				if (!m2[i])break;
				if(vis[x])continue;
				vis[x]=1;
				printf("%d ",x);
				m2[i]--;
			}
		} puts("");
	}
	return 0;
}