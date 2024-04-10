#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
struct unionFindSet{
	LL fa[2005];
	void makeSet(LL up){for(LL i=0;i<=up;++i)	fa[i]=i;}
	LL findSet(LL x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}
	bool unionSet(LL x,LL y)
	{
		LL xx=findSet(x),yy=findSet(y);
		if(xx==yy)	return false;
		return fa[yy]=xx,true;
	}
}ufs;
struct Edge{
	LL u,v,val,id;
	Edge(){}
	Edge(LL U,LL V,LL VAL,LL I){u=U,v=V,val=VAL,id=I;}
	bool operator < (Edge ano) const {return val<ano.val;}
}ed[200005];
LL n,m;
#define mp make_pair
vector<pair<LL,LL>> G[200005];
LL init;
bool onTree[800005];
void Kruskal()
{
	sort(ed+1,ed+1+m);
	ufs.makeSet(n);
	for(LL i=1;i<=m;++i)
	{
		LL u=ed[i].u,v=ed[i].v,val=ed[i].val;
		if(ufs.unionSet(u,v))	init+=val,G[u].push_back(mp(v,val)),G[v].push_back(mp(u,val)),onTree[ed[i].id]=true;
	}
}
LL dfn[200005],sjc,dep[200005],fa[200005],top[200005],siz[200005],son[200005],pv[200005],rel[200005],ans[200005];
void dfs1(LL now,LL pre)
{
	dep[now]=dep[pre]+1;
	fa[now]=pre;
	siz[now]=1;
	for(auto st:G[now])
	{
		LL to=st.first,val=st.second;
		if(to==pre)	continue;
		pv[to]=val;
		dfs1(to,now);
		siz[now]+=siz[to];
		if(siz[to]>siz[son[now]])	son[now]=to;
	}
}
void dfs2(LL now,LL upt)
{
	top[now]=upt;
	dfn[now]=++sjc;
	if(son[now])	dfs2(son[now],upt);
	for(auto st:G[now])
	{
		LL to=st.first;
		if(to==fa[now] || to==son[now])	continue;
		dfs2(to,to);
	}
}
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define Mm LL mid=(l+r)>>1
LL minn[800005],tag[800005];
void push_upM(LL now){minn[now]=min(minn[lc(now)],minn[rc(now)]);}
void buildM(LL l,LL r,LL now)
{
	tag[now]=minn[now]=2e9;
	if(l==r)	return ;
	Mm;
	buildM(l,mid,lc(now)),buildM(mid+1,r,rc(now));
	push_upM(now);
}
void push_downM(LL now)
{
	if(tag[now]!=2e9)
	{
		tag[lc(now)]=min(tag[lc(now)],tag[now]);
		tag[rc(now)]=min(tag[rc(now)],tag[now]);
		minn[lc(now)]=min(minn[lc(now)],tag[now]);
		minn[rc(now)]=min(minn[rc(now)],tag[now]);
		tag[now]=2e9;
	}
}
void modifyM(LL l,LL r,LL now,LL x,LL y,LL val)
{
	if(x<=l && r<=y)
	{
		minn[now]=min(minn[now],val);
		tag[now]=min(tag[now],val);
		return ;
	}
	Mm;
	push_downM(now);
	if(x<=mid)	modifyM(l,mid,lc(now),x,y,val);
	if(mid<y)	modifyM(mid+1,r,rc(now),x,y,val);
	push_upM(now);
}
LL queryM(LL l,LL r,LL now,LL x,LL y)
{
	if(x<=l && r<=y)	return minn[now];
	Mm,ret=2e9;
	push_downM(now);
	if(x<=mid)	ret=min(ret,queryM(l,mid,lc(now),x,y));
	if(mid<y)	ret=min(ret,queryM(mid+1,r,rc(now),x,y));
	return ret;
}
void modifyChainM(LL x,LL y,LL k)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		modifyM(1,n,1,dfn[top[x]],dfn[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])	swap(x,y);
	modifyM(1,n,1,dfn[x]+1,dfn[y],k);
}
LL queryChainM(LL x,LL y)
{
	LL ret=2e9;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		ret=min(ret,queryM(1,n,1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])	swap(x,y);
	return min(ret,queryM(1,n,1,dfn[x]+1,dfn[y]));
}
LL maxn[800005];
void push_up(LL now){maxn[now]=max(maxn[lc(now)],maxn[rc(now)]);}
void build(LL l,LL r,LL now)
{
	if(l==r)
	{
		maxn[now]=rel[l];
		return ;
	}
	Mm;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
	push_up(now);
}
LL query(LL l,LL r,LL now,LL x,LL y)
{
	if(x<=l && r<=y)	return maxn[now];
	Mm,ret=0;
	if(x<=mid)	ret=max(ret,query(l,mid,lc(now),x,y));
	if(mid<y)	ret=max(ret,query(mid+1,r,rc(now),x,y));
	return ret;
}
#undef lc
#undef rc
#undef Mm
LL queryChain(LL x,LL y)
{
	LL ret=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		ret=max(ret,query(1,n,1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])	swap(x,y);
	return max(ret,query(1,n,1,dfn[x]+1,dfn[y]));
}
int main(){
	n=read(),m=read();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read(),w=read();
		ed[i]=Edge(u,v,w,i);
	}
	Kruskal();
	pv[1]=0;
	dfs1(1,0),dfs2(1,1);
	for(LL i=1;i<=n;++i)	rel[dfn[i]]=pv[i];
	build(1,n,1);
	buildM(1,n,1);
	for(LL i=1;i<=m;++i)
	{
		LL id=ed[i].id;
		if(!onTree[id])	modifyChainM(ed[i].u,ed[i].v,ed[i].val);
	}
	for(LL i=1;i<=m;++i)
	{
		LL id=ed[i].id;
		if(!onTree[id])	ans[id]=queryChain(ed[i].u,ed[i].v)-1;
		else	ans[id]=queryChainM(ed[i].u,ed[i].v)-1;
	}
	for(LL i=1;i<=m;++i)	write(ans[i]==(2e9-1)?-1:ans[i]),putchar(' ');
	return 0;
}