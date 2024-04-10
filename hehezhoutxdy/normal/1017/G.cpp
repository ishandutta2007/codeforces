//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[100003];
int sz[100003],son[100003],dft[100003],dfn[100003],tp[100003],fa[100003];
int sum[530007],tg[530007],mx[530007],cnt;
int n=read(),m=read(),tsum,ans;
void dfs(int x)
{
	sz[x]=1;
	for(int y:e[x])
		dfs(y),sz[x]+=sz[y],(sz[son[x]]<sz[y])&&(son[x]=y);
	return ;
}
void dfs2(int x,int top){
	tp[x]=top,dfn[x]=++cnt;
	if(son[x]) dfs2(son[x],top);
	for(int y:e[x])
		if(y!=son[x]) dfs2(y,y);
	dft[x]=cnt;
}
void pd(int x,int l,int r)
{
	if(tg[x])
	{
		int lc=x<<1,rc=(x<<1)+1,mid=(l+r)>>1;
		mx[lc]=mx[rc]=-1,
		sum[lc]=-(mid-l+1),sum[rc]=-(r-mid),
		tg[lc]=tg[rc]=1,tg[x]=0;
	}
}
void clr(int x,int tl,int tr,int l,int r){
	if(tg[x]||(tl<=l&&r<=tr)){
		sum[x]=-(r-l+1);mx[x]=-1;tg[x]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(tl<=mid)clr(x<<1,tl,tr,l,mid);
	if(tr>mid)clr((x<<1)+1,tl,tr,mid+1,r);
	mx[x]=max(mx[(x<<1)+1],mx[x<<1]+sum[(x<<1)+1]);
	sum[x]=sum[x<<1]+sum[(x<<1)+1];
}
void mdf(int x,int tl,int tr,int l,int r){
	if(l==r){
		sum[x]+=tr;mx[x]+=tr;
		return;
	}
	int mid=(l+r)>>1;pd(x,l,r);
	if(tl<=mid)mdf(x<<1,tl,tr,l,mid);
	else mdf((x<<1)+1,tl,tr,mid+1,r);
	mx[x]=max(mx[(x<<1)+1],mx[x<<1]+sum[(x<<1)+1]);
	sum[x]=sum[x<<1]+sum[(x<<1)+1];
}
void qry(int x,int tl,int tr,int l,int r){
	if(tl<=l&&r<=tr){
		ans=max(ans,tsum+mx[x]);
		tsum+=sum[x];
		return;
	}
	int mid=(l+r)>>1;pd(x,l,r);
	if(tr>mid)qry((x<<1)+1,tl,tr,mid+1,r);
	if(tl<=mid)qry(x<<1,tl,tr,l,mid);
}
int query(int x){
	tsum=0;ans=-1;
	while(x) qry(1,dfn[tp[x]],dfn[x],1,n),x=fa[tp[x]];
	return ans;
}
int main()
{
	for(int i=2; i<=n; ++i)	e[fa[i]=read()].push_back(i);
	dfs(1),dfs2(1,1),tg[1]=1;mx[1]=-1,sum[1]=-n;
	for(int x,y; m--;)
	{
		x=read(),y=read();
		if(x==1) mdf(1,dfn[y],1,1,n);
		else if(x==2) clr(1,dfn[y],dft[y],1,n),mdf(1,dfn[y],-1-query(y),1,n);
		else puts(query(y)>=0?"black":"white");
	}
	return 0;
}