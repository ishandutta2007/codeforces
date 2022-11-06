#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#define N 100010
#define M 1010
#define BT bitset<M>
using namespace std;
int n,m,w[N],head[N],nxt[N<<1],to[N<<1],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
BT o[M],rm;
BT p[N<<2];
BT operator +(BT a,int v){return a>>v|(a&o[v])<<(m-v);}
int tag[N<<2];
void insert(int u,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R){tag[u]=(tag[u]+v+m)%m;return;}
	int mid=(l+r)>>1;
	if(L<=mid) insert(u<<1,l,mid,L,R,v);
	if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
	p[u]=(p[u<<1]+tag[u<<1])|(p[u<<1|1]+tag[u<<1|1]);
}
BT ans;
void answer(int u,int l,int r,int L,int R,int v=0)
{
	v=(v+tag[u])%m;
	if(L<=l && r<=R){ans|=p[u]+v;return;}
	int mid=(l+r)>>1;
	if(L<=mid) answer(u<<1,l,mid,L,R,v);
	if(R>mid) answer(u<<1|1,mid+1,r,L,R,v);
}
int id[N],nid[N],siz[N],tot;
void build(int u,int l,int r)
{
	if(l==r){p[u].set(w[nid[l]]);return;}
	int mid=(l+r)>>1;build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	p[u]=p[u<<1]|p[u<<1|1];
}
void dfs(int u,int f)
{
	siz[u]=1;
	nid[id[u]=++tot]=u;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),w[i]%=m;
	for(int i=1;i<=m;i++) o[i]=o[i-1]<<1,o[i].set(0);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=2;i<m;i++)
	{
		bool can=true;
		for(int j=2;j*j<=i;j++) can&=(i%j!=0);
		if(can) rm.set(i);
	}
	dfs(1,0);
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q --> 0)
	{
		int opt,u,v;
		scanf("%d%d",&opt,&u);
		if(opt==1) scanf("%d",&v),insert(1,1,n,id[u],id[u]+siz[u]-1,m-v%m);
		else
		{
			ans.reset();
			answer(1,1,n,id[u],id[u]+siz[u]-1);
			printf("%d\n",(int)(ans&rm).count());
		}
	}
	return 0;
}