#include <bits/stdc++.h>
#define maxn 1000005
int vis[maxn],head[maxn]={0},n,m,s,g[maxn<<1],tl,u[maxn],v[maxn],w[maxn];
struct edge {
	int v,id,next;
}edges[maxn<<1];
void add_edge(int u,int v,int id){
	edges[++tl].v=v;
	edges[tl].id=id;
	edges[tl].next=head[u];head[u]=tl;
}
void dfs1(int u){
	vis[u]=1;
	for(int i=head[u];i;i=edges[i].next){
		int v1=edges[i].v,id=edges[i].id;
		if (vis[v1])continue;
		if (w[id]==2&&v1==v[id])g[id]=1;
		dfs1(v1);
	}
}

void dfs2(int u){
	vis[u]=1;
	for(int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (vis[v])continue;
		if (w[edges[i].id]==2)continue;
		dfs2(v);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&w[i],&u[i],&v[i]);
		add_edge(u[i],v[i],i);
		if (w[i]==2)add_edge(v[i],u[i],i);
	}dfs1(s);
	int cnt=0;for(int i=1;i<=n;++i)cnt+=vis[i];
	printf("%d\n",cnt);
	for(int i=1;i<=m;++i){
		if(w[i]==1)continue;
		if (g[i])printf("+");
		else printf("-");
	}std::memset(vis,0,sizeof(vis));printf("\n");
	dfs2(s);
	cnt=0;for(int i=1;i<=n;++i)cnt+=vis[i];
	printf("%d\n",cnt);
	for(int i=1;i<=m;++i){
		if (w[i]==1)continue;
		if (vis[u[i]]&&!vis[v[i]])printf("-");
		else printf("+");
	}return 0;
}