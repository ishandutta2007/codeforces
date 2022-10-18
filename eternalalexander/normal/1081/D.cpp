#include <bits/stdc++.h>
#define maxn 200005

int fa[maxn]={0};
int getf(int x) {return fa[x]?fa[x]=getf(fa[x]):x;}
int u[maxn], v[maxn], w[maxn], head[maxn]={0}, id[maxn], size[maxn], mark[maxn], tail=0;
struct edge {
	int v, w, next;
}edges[maxn<<1];

int wei=0;

void add_edge(int u, int v, int w) {
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}
int n, m, k;
void dfs(int u, int f) {
	if (mark[u]) size[u]=1;
	for (int i=head[u];i;i=edges[i].next) {
		int v=edges[i].v;
		if (v==f) continue;
		dfs(v, u);
		size[u]+=size[v];
		if (size[v]!=0&&k-size[v]!=0) wei=std::max(wei, edges[i].w);
	}
}



int cmp(int a, int b) {return w[a]<w[b];}

int main() {
	int t;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1;i<=k;++i) {
		scanf("%d", &t);
		mark[t]=i;
	}
	for (int i=1;i<=m;++i) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		id[i]=i;
	}
	std::sort(id+1, id+m+1, cmp);
	for (int i=1;i<=m;++i) {
		int j=id[i];
		if (getf(u[j])!=getf(v[j])) {
			add_edge(u[j], v[j], w[j]);
			add_edge(v[j], u[j], w[j]);
			fa[getf(u[j])]=getf(v[j]);
		}
	} dfs(1, 0);
	for (int i=1;i<=k;++i) printf("%d ", wei);
	return 0;
}