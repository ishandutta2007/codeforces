#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[200102],cnt,dep[200102],siz[200102],fa[200102],son[200102],dfn[200102],tim,c[22][200102],top[200102];
struct edge{int to,next;}e[400102];
inline void add(re int x,re int y,re int z){for(;y<=n;y+=y&(-y))c[x][y]+=z;}
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	dep[x]=dep[y]+1,siz[x]=1,fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs1(re int x,re int y){
	top[x]=y,dfn[x]=++tim;
	if(son[x])dfs1(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^fa[x]&&e[i].to^son[x])
			dfs1(e[i].to,e[i].to);
}
inline int ask(re int x,re int y){
	int s=0;
	for(;y;y^=y&(-y))s+=c[x][y];
	return s;
}
inline void Add(re int x,re int y,re int z,re int v){
//	printf("ADD%d %d %d %d\n",x,y,z,v);
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		add(z,dfn[top[x]],v),add(z,dfn[x]+1,-v),x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	add(z,dfn[x],v),add(z,dfn[y]+1,-v);
//	printf("SSS%d\n",ask(0,21));
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
inline void ADD(re int x,re int y,re int d,re int z){
	for(re int i=d;~i;--i){
		Add(x,y,i,z);if(i)Add(x,y,i-1,z);
		x=fa[x],y=fa[y];
	}
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	add(1,n+1),add(n+1,1);
	for(re int i=n+1;i<=n+19;++i)add(i,i+1),add(i+1,i);
	n+=20;
	dfs(n,n),dfs1(n,n);
	m=read();
	while(m--){
		re int o=read();
		if(o==1){
			long long ans=0;int x=read();
			for(re int i=0;i<=20;++i)ans+=ask(i,dfn[x]),x=fa[x];
			printf("%lld\n",ans);
		}
		else{
			int u=read(),v=read(),k=read(),d=read(),w=lca(u,v);
			Add(w,u,d,k),Add(w,v,d,k);
			Add(w,w,d,-k-k),ADD(w,w,d,k);
		}
	}
}