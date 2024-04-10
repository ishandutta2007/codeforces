#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,Q,x[N],y[N],root,cnt,head[N],tag[2][N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
int dfn[N],low[N],vis[N],num,tot,col[N];
stack<int> st;
void Tarjan(int u,int in_edge){
	low[u]=dfn[u]=++num;
	st.push(u);
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(!dfn[v]){
			Tarjan(v,i^1);
			low[u]=min(low[u],low[v]);
		}
		else if(i^in_edge){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int t=0;
		++tot;
		while(t^u){
			t=st.top();
			st.pop();
			col[t]=tot;
			vis[t]=0;
		}
	}
}
void sear(int u){vis[u]=1;for(int i=head[u];i;i=edge[i].nxt){int v=edge[i].to;if(!vis[v])sear(v);}}
int top[N],siz[N],son[N],dep[N],f[N];
void dfs1(int u,int fa,int deep){
	dep[u]=deep;
	f[u]=fa;
	siz[u]=1;
	int maxson=-1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson){
			maxson=siz[v];
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
void dfs(int u){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==f[u])continue;
		dfs(v);
		tag[0][u]+=tag[0][v];
		tag[1][u]+=tag[1][v];
	}
	if(tag[0][u]&&tag[1][u]){
		printf("No\n");
		exit(0);
	}
}
int main(){
	n=read(),m=read(),Q=read(),cnt=1;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		x[i]=u,y[i]=v;
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])Tarjan(i,0);
	}
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=m;++i){
		if(col[x[i]]^col[y[i]]){
			add(col[x[i]],col[y[i]]),add(col[y[i]],col[x[i]]);
		}
	}
	memset(vis,0,sizeof(vis));
	root=tot+1;
	for(int i=1;i<=tot;++i){
		if(!vis[i])add(root,i),add(i,root),sear(i);
	}
	dfs1(root,0,1),dfs2(root,root);
	while(Q--){
		int u=col[read()],v=col[read()];
		int lca=LCA(u,v);
		if(lca==root){
			printf("No\n");
			return 0;
		}
		tag[0][u]++,tag[0][lca]--;
		tag[1][v]++,tag[1][lca]--;
	}
	dfs(root);
	printf("Yes\n");
	return 0;
}