#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],w[N<<1],head[N],cnt,n,m;
int fr[N];
int find(int x){return x==fr[x]?fr[x]:(fr[x]=find(fr[x]));}
void add(int u,int v,int w1)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	w[cnt]=w1;
	head[u]=cnt;
}
struct road{
	int x,y,w,id;
	bool operator <(const road a)const{return w<a.w;}
}r[N];
int wp[N],siz[N],son[N],dep[N],fa[N];
void dfs1(int u,int f)
{
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		wp[v]=w[i];
		dfs1(v,u);
		siz[u]+=v;
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
int top[N],id[N],nid[N],tot;
void dfs2(int u,int topp)
{
	nid[id[u]=++tot]=u;
	top[u]=topp;
	if(son[u]) dfs2(son[u],topp);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}
int val[N<<2];
void build(int u,int l,int r)
{
	if(l==r){val[u]=wp[nid[l]];return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	val[u]=max(val[u<<1],val[u<<1|1]);
}
int answer(int u,int l,int r,int L,int R)
{
	if(L<=l && r<=R) return val[u];
	int mid=(l+r)>>1,ans=0;
	if(L<=mid) ans=max(ans,answer(u<<1,l,mid,L,R));
	if(R>mid) ans=max(ans,answer(u<<1|1,mid+1,r,L,R));
	return ans;
}
int answer(int u,int v)
{
	int ans=0;
	for(;top[u]!=top[v];u=fa[top[u]])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ans=max(ans,answer(1,1,n,id[top[u]],id[u]));
	}
	if(dep[u]>dep[v]) swap(u,v);
	ans=max(ans,answer(1,1,n,id[u]+1,id[v]));
	return ans;
}
bool cmp(road &a,road &b){return a.id<b.id;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].w),r[i].id=i;
	sort(r+1,r+m+1);
	for(int i=1;i<=n;i++) fr[i]=i;
	ll res=0;
	for(int i=1;i<=m;i++)
	if(find(r[i].x)!=find(r[i].y))
	{
		fr[find(r[i].x)]=find(r[i].y);
		add(r[i].x,r[i].y,r[i].w);
		add(r[i].y,r[i].x,r[i].w);
		res+=r[i].w;
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++)
	printf("%lld\n",res-answer(r[i].x,r[i].y)+r[i].w);
	return 0;
}