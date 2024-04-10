#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,c[300002],head[300002],cnt,fa[300002],dfn[300002],siz[300002],S[300002],a[300002],b[300002],p[300002],top[300002],son[300002],F[300002],ans,c1[300002];
struct edge{int to,next;}e[600002];
inline bool cmp(re int x,re int y){return dfn[a[x]]<dfn[a[y]];}
inline int root(re int x){return x==F[x]?x:F[x]=root(F[x]);}
inline bool in(re int x,re int y){return dfn[y]>=dfn[x]&&dfn[y]<dfn[x]+siz[x];}
inline void add(re int x,re int y){for(;x<=n;x+=x&(-x))c[x]+=y;}
inline void add1(re int x,re int y){for(;x<=n;x+=x&(-x))c1[x]+=y;}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
inline int ask1(re int x,re int s=0){for(;x;x^=x&(-x))s+=c1[x];return s;}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)siz[i]=1,F[i]=i;
	for(re int i=2;i<=n;++i)fa[i]=read();
	for(re int i=n;i;--i)siz[fa[i]]+=siz[i];
	for(re int i=1;i<=n;++i)dfn[i]=S[fa[i]]+dfn[fa[i]]+1,S[fa[i]]+=siz[i];
	for(re int i=1;i<=m;++i){
		a[i]=read(),b[i]=read();
		if(dfn[a[i]]>dfn[b[i]])swap(a[i],b[i]);
		if(fa[b[i]]==a[i])return puts("-1"),0;
		p[i]=i;
	}sort(p+1,p+m+1,cmp);
	for(re int i=m;i;--i)
		if(in(a[p[i]],b[p[i]])&&!ask(dfn[fa[b[p[i]]]])){
			re int x=root(b[p[i]]);
			while(fa[x]!=a[p[i]])x=F[x]=root(fa[x]);
			if((ask1(dfn[b[p[i]]]-1)-ask1(dfn[x]-1)+ask1(dfn[x]+siz[x]-1)-ask1(dfn[b[p[i]]]+siz[b[p[i]]]-1)))continue;
			add1(dfn[x],1),add(dfn[x],1),add(dfn[x]+siz[x],-1),++ans;
		}
	re bool ia=1;
	for(re int i=m;i&&ia;--i)if((!in(a[i],b[i]))&&((!ask(fa[a[i]]))&&(!ask(fa[b[i]])))&&(!(ask1(dfn[a[i]]-1)+ask1(dfn[b[i]]-1)-ask1(dfn[a[i]]+siz[a[i]]-1)+ask1(n)-ask1(dfn[b[i]]+siz[b[i]]-1))))ia=0;
	if(ia)puts("");
	printf("%d",ans+!ia);
}