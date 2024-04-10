#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],ans,fa[1000002],dep[1000002],top[1000002],head[1000002],cnt,A[1000002],B[1000002],k,siz[1000002],son[1000002],tg[1000002],f[1000002],dfn[1000002],pl[1000002],tim;
char s[1000002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
struct edge{int to,next;}e[2000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs1(re int x,re int y){
	fa[x]=y,siz[x]=1,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs2(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^fa[x]&&e[i].to^son[x])
			dfs2(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
inline int nxt(re int x,re int y){
	while(top[x]^top[y]){
		if(fa[top[x]]==y)return top[x];
		x=fa[top[x]];
	}
	return pl[dfn[y]+1];
}
inline void dfs3(re int x,re int y){
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			tg[e[i].to]+=tg[x];
			dfs3(e[i].to,x);
		}
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)fa[i]=i;
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();
		if(root(x)^root(y))add(x,y),add(y,x),fa[root(x)]=root(y);
		else A[++k]=x,B[k]=y;
	}
	dfs1(1,1),dfs2(1,1);
	for(re int i=1;i<=k;++i){
		re int x=A[i],y=B[i],z=lca(A[i],B[i]);
		if(z!=x&&z!=y)++tg[x],++tg[y];
		else{
			if(z==x)swap(x,y);
			re int o=nxt(x,y);
			++tg[1],--tg[o],++tg[x];
		}
	}
	dfs3(1,1);
	for(re int i=1;i<=n;++i)printf("%d",tg[i]==k);
}