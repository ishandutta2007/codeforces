#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
#define ll long long
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
vector<int>vl[N];
int siz[N],fa[N],dep[N],son[N];
int id[N],nid[N],tot;
int top[N],n;
void dfs1(int u,int f)
{
	dep[u]=dep[fa[u]=f]+1;
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
void dfs2(int u,int topp)
{
	top[u]=topp;
	nid[id[u]=++tot]=u;
	if(son[u]) dfs2(son[u],topp);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v!=fa[u] && v!=son[u]) dfs2(v,v);
	}
}
struct node{
	ll v;
	int u;
	node(ll V=0,int U=0):v(V),u(U){}
	bool operator <(const node a)const{return v==a.v?u<a.u:v<a.v;}
	void operator +=(ll a){v+=a;}
};
node val[N<<2];
ll tag[N<<2];
#define inf 1000000000000000ll
void build(int u,int l,int r)
{
	if(l==r){val[u]=node(vl[nid[l]].empty()?inf:*vl[nid[l]].rbegin(),nid[l]);return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	val[u]=min(val[u<<1],val[u<<1|1]);
}
void set_tag(int u,ll v){val[u]+=v,tag[u]+=v;}
void push_down(int u)
{
	if(!tag[u]) return;
	set_tag(u<<1,tag[u]),set_tag(u<<1|1,tag[u]);
	tag[u]=0;
}
void insert(int u,int l,int r,int L,int R,ll v)
{
	if(L<=l && r<=R){set_tag(u,v);return;}
	int mid=(l+r)>>1;
	push_down(u);
	if(L<=mid) insert(u<<1,l,mid,L,R,v);
	if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
	val[u]=min(val[u<<1],val[u<<1|1]);
}
node answer(int u,int l,int r,int L,int R)
{
	if(L<=l && r<=R) return val[u];
	push_down(u);
	int mid=(l+r)>>1;
	node ans=inf;
	if(L<=mid) ans=min(ans,answer(u<<1,l,mid,L,R));
	if(R>mid) ans=min(ans,answer(u<<1|1,mid+1,r,L,R));
	return ans;
}
void update(int u)
{
	ll p=*vl[u].rbegin();vl[u].pop_back();
	insert(1,1,n,id[u],id[u],(vl[u].empty()?inf:*vl[u].rbegin())-p);
}
int lanswer(int u,int v)
{
	node a=inf/2;
	for(;top[u]!=top[v];u=fa[top[u]])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		a=min(a,answer(1,1,n,id[top[u]],id[u]));
	}
	if(dep[u]>dep[v]) swap(u,v);
	a=min(a,answer(1,1,n,id[u],id[v]));
	return a.u;
}
void linsert(int u,ll k){insert(1,1,n,id[u],id[u]+siz[u]-1,k);}
int ans[N],ta;
int main()
{
	int m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=m;i++)
	{
		int u;
		scanf("%d",&u);
		vl[u].push_back(i);
	}
	for(int i=1;i<=n;i++) sort(vl[i].begin(),vl[i].end(),greater<int>());
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(q --> 0)
	{
		int opt,u,v,k;
		scanf("%d%d%d",&opt,&u,&v);
		if(opt==1)
		{
			scanf("%d",&k);
			ta=0;
			while(k --> 0)
			{
				int r=lanswer(u,v);
				if(!r) break;
				ans[++ta]=*vl[r].rbegin();
				update(r);
			}
			printf("%d",ta);for(int i=1;i<=ta;i++) printf(" %d",ans[i]);
			puts("");
		}
		else linsert(u,v);
	}
	return 0;
}