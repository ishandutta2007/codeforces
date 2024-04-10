#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxn 100005
int anc[100005][20],depth[100005]={0}, fa[maxn],head[maxn]={0}, tail=0, vis[maxn]={0};
int len[100005], dp[100005], ans[100005];
int n, l; long long s;
long long depth2[100005]={0};
long long val[100005];
struct edge {
	int v, next;
}edges[maxn*2];
inline void add_edge(int u, int v) {
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}
int cmp(int a, int b) {return depth[a]>depth[b];}
void dfs(int u, int f) {
	depth2[u]=depth2[f]+val[u];
	depth[u]=depth[f]+1; anc[u][0]=f;
	for (int i=1;(1<<i)<=depth[u];i++) {
        anc[u][i]=anc[anc[u][i-1]][i-1];
    }
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v!=f) {
			dfs(edges[i].v, u);
		}
	} fa[u]=f;
}

int dfs2(int u) {
	dp[u]=-1; ans[u]=0;int flag=0;
	for (int i=head[u];i;i=edges[i].next) {
		flag=1;
		if (edges[i].v!=fa[u]) {
			dfs2(edges[i].v);
			ans[u]+=ans[edges[i].v];
			dp[u]=std::max(dp[u], dp[edges[i].v]-1);
		}
	}if (flag==0) {dp[u]=len[u]-1; ans[u]=1; return 0;}
	if (dp[u]==-1) {
		dp[u]=len[u]-1;
		ans[u]++;
	}
	return 0;
}
	

int main() {
	std::cin >> n >> l >> s;
	if (l==0) {
		printf("-1"); return 0;
	}
	for (int i=1;i<=n;++i) {
		std::cin >> val[i];
		if (val[i]>s) {printf("-1"); return 0;}
	}
	for (int i=2;i<=n;++i) {
		int u; scanf("%d", &u);
		add_edge(i, u); add_edge(u, i);
	}dfs(1, 0);
	for (int i=1;i<=n;++i) {
		int u=i;
		for (int j=20;j>=0;--j) {
			if (anc[u][j]!=0&&depth2[i]-depth2[fa[anc[u][j]]]<=s&&depth[i]-depth[fa[anc[u][j]]]<=l) 
				u=anc[u][j];
		} //printf("%d->%d\n", i, u);
		len[i]=depth[i]-depth[u]+1;
		//printf("%d ", len[i]);
	}dfs2(1);
	printf("%d", ans[1]);/*
	for (int i=1;i<=n;++i) {
		printf("%d %d\n", ans[i], dp[i]);
	}*/
	return 0;
}