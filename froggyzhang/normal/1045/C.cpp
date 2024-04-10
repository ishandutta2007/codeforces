#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int num,dfn[N],low[N],n,m,tot,Q;
int dis[N],dep[N],top[N],siz[N],son[N],f[N];
vector<int> G[N],H[N];
void Tarjan(int u){
	static int st[N],top;
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++tot;
				H[tot].push_back(u);
				H[u].push_back(tot);
				int t=0;
				while(t^v){
					t=st[top--];
					H[t].push_back(tot);
					H[tot].push_back(t);
				}	
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}	
	}
}
void dfs1(int u){
	dep[u]=dep[f[u]]+1;
	dis[u]=dis[f[u]]+(u<=n);
	siz[u]=1;
	for(auto v:H[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:H[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int get_dis(int x,int y){
	int lca=LCA(x,y);
	return dis[x]+dis[y]-dis[lca]-dis[f[lca]]-1;	
}
int main(){
	n=read(),m=read(),Q=read();
	tot=n;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Tarjan(1);
	dfs1(1);
	dfs2(1,1);
	while(Q--){
		int u=read(),v=read();
		printf("%d\n",get_dis(u,v));
	}	
	return 0;
}