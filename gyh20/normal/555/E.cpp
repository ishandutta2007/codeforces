#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,head[200002],cnt=1,dfn[200002],low[200002],stk[200002],bl[200002],tot,top[200002],f[200002],fa[200002],dep[200002],siz[200002],tim,tp,blk,q,m,f1[200002],f2[200002],son[200002],k;
inline int root(re int x){return x==f[x]?x:f[x]=root(f[x]);}
inline void merge(re int x,re int y){f[root(x)]=root(y);}
vector<int>g[200002];
inline void dfs(re int x,re int y){
	fa[x]=y,dep[x]=dep[y]+1,siz[x]=1;
	for(auto &z:g[x])
		if(z^y){
			dfs(z,x),siz[x]+=siz[z];
			if(siz[z]>siz[son[x]])son[x]=z;
		}
}
inline void dfs1(re int x,re int y){
	top[x]=y;
	if(son[x])dfs1(son[x],y);
	for(auto &z:g[x])if(z!=fa[x]&&z!=son[x])dfs1(z,z);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
bool ist[200002];
struct edge{int to,next;}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
inline void tarjan(re int x,re int y){
	dfn[x]=low[x]=++tim,stk[++tp]=x,ist[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(i^y){   
			if(!dfn[e[i].to])tarjan(e[i].to,i^1),low[x]=min(low[x],low[e[i].to]);
			else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
		}
	if(dfn[x]==low[x]){
		++blk;
		do{
			bl[stk[tp]]=blk;
			ist[stk[tp--]]=0;
		}while(stk[tp+1]^x);
	}
}
inline void dfs2(re int x,re int y){
	for(auto &z:g[x])
		if(z^fa[x]){
			dfs2(z,x);
			f1[x]+=f1[z],f2[x]+=f2[z];
		}
	if(f1[x]&&f2[x]){puts("No");exit(0);}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read(),k=read(),cnt=1;
	for(re int i=1;i<=n;++i)f[i]=i;
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read(),merge(x,y);
		add(x,y),add(y,x);
	}
	for(re int i=1;i<=n;++i)if(!dfn[i])tarjan(i,0);
	for(re int i=1;i<=n;++i)for(re int j=head[i];j;j=e[j].next)if(bl[i]^bl[e[j].to])g[bl[i]].push_back(bl[e[j].to]);
	for(re int i=1;i<=blk;++i)sort(g[i].begin(),g[i].end()),g[i].resize(unique(g[i].begin(),g[i].end())-g[i].begin());
	dfs(1,1),dfs1(1,1);
	while(k--){
		re int x=read(),y=read();
		if(root(x)^root(y))return puts("No");
		if(bl[x]==bl[y])continue;
		x=bl[x],y=bl[y];
		re int z=lca(x,y);
		++f1[x],--f1[z],++f2[y],--f2[z];
	}
	dfs2(1,1);
	puts("Yes");
}