#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,ans,cnt,tg[1200002],dfn[300002],c[300002],siz[300002],tim,pl[300002],lzy[12000002];
vector<int>g1[300002],g2[300002];
inline void cg(re int p,re int x){
	tg[p]=x;
	lzy[p]=1;
}
inline void pd(re int p){
	if(lzy[p]){
		cg(p<<1,tg[p]),cg(p<<1|1,tg[p]);
		lzy[p]=0;
	}
}
inline void cov(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y){
		cg(p,z);
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)cov(p<<1,l,mid,x,y,z);
	if(y>mid)cov(p<<1|1,mid+1,r,x,y,z);
}
inline int ask(re int p,re int l,re int r,re int x){
	if(l==r)return tg[p];
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)return ask(p<<1,l,mid,x);
	else return ask(p<<1|1,mid+1,r,x);
}
inline void add(re int x,re int y){for(;x<=n;x+=x&(-x))c[x]+=y;}
inline int ask(re int x){
	re int s=0;
	for(;x;x-=x&(-x))s+=c[x];
	return s;
}
inline void dfs(re int x){
	dfn[x]=++tim,siz[x]=1,pl[tim]=x;
	for(re int i=0;i<g2[x].size();++i)dfs(g2[x][i]),siz[x]+=siz[g2[x][i]];
}
inline void ins(re int x){
	add(dfn[x],1);
	cov(1,1,n,dfn[x],dfn[x]+siz[x]-1,x);
}
inline void del(re int x){
	add(dfn[x],-1);
	cov(1,1,n,dfn[x],dfn[x]+siz[x]-1,0); 
}
inline void calc(re int x,re int y){
	re int usd=0,lst=0;
	if(!(ask(dfn[x]+siz[x]-1)-ask(dfn[x])))usd=1,++y;
	if(usd&&ask(1,1,n,dfn[x])){
		re int z=ask(1,1,n,dfn[x]);
		del(z);
		lst=z;
		--y;
	}
	if(usd)ins(x);
	ans=max(ans,y);
	for(re int i=0;i<g1[x].size();++i)calc(g1[x][i],y);
	if(usd)del(x);
	if(lst)ins(lst);
}
signed main(){
	t=read();
	while(t--){
		n=read(),tim=ans=0;
		for(re int i=1;i<=n;++i)g1[i].clear(),g2[i].clear(),c[i]=0;
		for(re int i=1;i<=n*4;++i)tg[i]=0;
		for(re int i=2;i<=n;++i)g1[read()].push_back(i);
		for(re int i=2;i<=n;++i)g2[read()].push_back(i);
		dfs(1),calc(1,0);
		printf("%d\n",ans);
	}
}