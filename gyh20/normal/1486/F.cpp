#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],cnt,head[1000002],b[1000002],son[300002],top[300002],dfn[300002],tim,pl[300002],fa[300002],siz[300002],dep[300002],d[300002],vis[300002];
long long ans;
struct BIT{
	int c[300002];
	inline void add(re int x,re int y){
		for(;x<=n;x+=x&(-x))c[x]+=y;
	}
	inline int ask(re int x){
		re int s=0;
		for(;x;x-=x&(-x))s+=c[x];
		return s;
	}
}C1,C2,C3,C4;
map<int,int>v[300002],v1[300002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt;
}
inline void dfs1(re int x,re int y){
	fa[x]=y,siz[x]=1,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x);
			siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs2(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)if(e[i].to!=fa[x]&&e[i].to!=son[x])dfs2(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline void mdf(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		C1.add(dfn[top[x]],1);
		C1.add(dfn[x]+1,-1);
		C2.add(dfn[top[x]],1);
		C2.add(dfn[x],-1);
		++v[fa[top[x]]][top[x]];
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	C1.add(dfn[x],1),C1.add(dfn[y]+1,-1),C2.add(dfn[x],1),C2.add(dfn[y],-1);
}
inline void mdf1(re int x,re int y){
	re int z=lca(x,y);
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		C1.add(dfn[top[x]],1);
		C1.add(dfn[x]+1,-1);
		C2.add(dfn[top[x]],1);
		C2.add(dfn[x],-1);
		if(fa[top[x]]^z)++v[fa[top[x]]][top[x]];
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x==y)return;
	x=pl[dfn[x]+1];
	C1.add(dfn[x],1),C1.add(dfn[y]+1,-1),C2.add(dfn[x],1),C2.add(dfn[y],-1);
}
inline int nxt(re int x,re int y){
	while(top[x]^top[y]){
		if(fa[top[x]]==y)return top[x];
		x=fa[top[x]];
	}
	return pl[dfn[y]+1];
}
signed main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);dfs1(1,1),dfs2(1,1);
	m=read();
	for(re int i=1;i<=m;++i){
		a[i]=read(),b[i]=read(),d[i]=lca(a[i],b[i]);
		mdf(a[i],b[i]);
	}
	for(re int i=1;i<=m;++i){
		re int aa=0,bb=0,xx=C1.ask(dfn[d[i]]);
		if(a[i]^d[i]){
			re int x=nxt(a[i],d[i]);
			if(x==son[d[i]])xx-=C2.ask(dfn[d[i]]);
			else xx-=v[d[i]][x];
			aa=x;
		}
		if(b[i]^d[i]){
			re int x=nxt(b[i],d[i]);
			if(x==son[d[i]])xx-=C2.ask(dfn[d[i]]);
			else xx-=v[d[i]][x];
			bb=x;
		}
		if(a[i]==b[i])--xx;
		if(aa&&bb)++xx;
		ans+=xx;
	//	printf("%d %lld\n",xx,ans);
	}
	re long long ans1=0;
	memset(C1.c,0,sizeof(C1.c)),memset(C2.c,0,sizeof(C2.c));
	for(re int i=1;i<=n;++i)v[i].clear();
	for(re int i=1;i<=m;++i){
		mdf1(a[i],b[i]);
		
	}
	re long long ans2=0;
	for(re int i=1;i<=m;++i){
		re int aa=0,bb=0,xx=C1.ask(dfn[d[i]]);
		if(a[i]^d[i]){
			re int x=nxt(a[i],d[i]);
			if(x==son[d[i]])xx-=C2.ask(dfn[d[i]]);
			else xx-=v[d[i]][x];
			aa=x;
		}
		if(b[i]^d[i]){
			re int x=nxt(b[i],d[i]);
			if(x==son[d[i]])xx-=C2.ask(dfn[d[i]]);
			else xx-=v[d[i]][x];
			bb=x;
		}
		ans1+=xx;
		if(aa>bb)swap(aa,bb);
		if(aa&&bb)ans2+=v1[aa][bb],++v1[aa][bb];
	}
	//printf("%lld %lld %lld\n",ans,ans1,ans2);
	printf("%lld",ans2+ans1+(ans-ans1)/2);
}