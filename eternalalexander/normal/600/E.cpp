#include <bits/stdc++.h>
#define maxn 100005
int n,col[maxn],size[maxn]={0},son[maxn]={0},vis[maxn]={0},max=0,cnt=0,tail=0,head[maxn]={0};
long long sum=0,ans[maxn]={0};
struct edge {
	int v, next;
}edges[maxn<<1];
void add_edge(int u,int v) {
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
} int dfs1(int u, int f) {
	size[u]=1;
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v==f) continue;
		size[u]+=dfs1(edges[i].v,u);
		if (size[edges[i].v]>size[son[u]]) son[u]=edges[i].v;
	}return size[u];
}
void calc(int u,int f,int flag,int tp=0) {
	vis[col[u]]+=flag;
	if (vis[col[u]]==max&&flag==1) {cnt++;sum+=col[u];}
	if (vis[col[u]]>max&&flag==1) {max=vis[col[u]];cnt=1;sum=col[u];}
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v==f||(edges[i].v==son[u]&&tp)) continue;
		calc(edges[i].v,u,flag);
	}
}

void dfs(int u, int f, int is_heavy) {
	int mx=max,mc=cnt,ms=sum;
	for (int i=head[u];i;i=edges[i].next)
		if (edges[i].v!=f&&edges[i].v!=son[u]) dfs(edges[i].v,u,0);
	if (son[u]) dfs(son[u],u,1);
	calc(u,f,1,1);
	ans[u]=sum;
	if (!is_heavy) {max=mx;cnt=mc;sum=ms;calc(u,f,-1);}
}

int main() {
	scanf("%d",&n);int u, v;
	for (int i=1;i<=n;++i) scanf("%d",&col[i]);
	for (int i=1;i<n;++i)scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
	dfs1(1,0);dfs(1,0,1);
	for (int i=1;i<=n;++i) printf("%I64d ",ans[i]);
	return 0;
}