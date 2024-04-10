#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
#define mod 1000000007
#define N 105010
#define M N*200
#define base 233
#define ull unsigned long long
using namespace std;
ull bs[N<<1];
int ls[M],rs[M],val[M],tot;
bool tag[M];
ull hs[M];
int new_node(int p)
{
	int u=++tot;
	if(!p) return u;
	ls[u]=ls[p],rs[u]=rs[p],val[u]=val[p];
	tag[u]=tag[p],hs[u]=hs[p];
	return u;
}
void update(int u,int l,int r)
{
	int mid=(l+r)>>1;
	hs[u]=hs[ls[u]]+hs[rs[u]]*bs[mid-l+1];
	val[u]=val[ls[u]]==(mid-l+1)?val[ls[u]]+val[rs[u]]:val[ls[u]];
}
void push_down(int u)
{
	if(!tag[u]) return;
	tag[ls[u]=new_node(ls[u])]=true;
	hs[ls[u]]=val[ls[u]]=0;
	tag[rs[u]=new_node(rs[u])]=true;
	hs[rs[u]]=val[rs[u]]=0;
	tag[u]=false;
}
int insert(int p,int l,int r,int pos)
{
	push_down(p);
	int u=new_node(p);
	if(l==r){val[u]=hs[u]=1;return u;}
	int mid=(l+r)>>1;
	if(pos<=mid) ls[u]=insert(ls[u],l,mid,pos);
	else rs[u]=insert(rs[u],mid+1,r,pos);
	update(u,l,r);
	return u;
}
int reset(int p,int l,int r,int L,int R)
{
	int u=new_node(p);
	if(L>R) return u;
	if(L<=l && r<=R){val[u]=hs[u]=0;tag[u]=true;return u;}
	int mid=(l+r)>>1;
	if(L<=mid) ls[u]=reset(ls[u],l,mid,L,R);
	if(R>mid) rs[u]=reset(rs[u],mid+1,r,L,R);
	update(u,l,r);
	return u;
}
int answer(int u,int l,int r,int p)
{
	if(!u || tag[u]) return 0;
	if(l>=p) return val[u];
	int mid=(l+r)>>1;
	if(p>mid) return answer(rs[u],mid+1,r,p);
	else
	{
		int v=answer(ls[u],l,mid,p);
		if(v==mid-p+1) return v+val[rs[u]];
		else return v;
	}
}
int n=N;
int cmp(int u,int v)
{
	int fu=u,fv=v;
	int l=0,r=n;
	while(1)
	{
		if(!u || tag[u]) return fv;
		if(!v || tag[v]) return fu;
		if(l==r) return hs[u]<=hs[v]?fv:fu;
		int mid=(l+r)>>1;
		if(hs[rs[u]]==hs[rs[v]]) u=ls[u],v=ls[v],r=mid;
		else u=rs[u],v=rs[v],l=mid+1;
	}
}
int add_one(int p,int v)
{
	int l=answer(p,0,n,v);
	int u=reset(p,0,n,v,v+l-1);
	u=insert(u,0,n,v+l);
	return u;
}
struct pqnode{
	int u;
	int rt;
	bool operator <(const pqnode a)const{return cmp(rt,a.rt)==rt;}
};
priority_queue<pqnode>q;
int nxt[M],to[M],wx[M],head[N],cnt;
void add(int u,int v,int w)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	wx[cnt]=w;
	head[u]=cnt;
}
int drt[N],pre[N];
ll ksm(int a,int b)
{
	ll r=1;
	for(;b;b>>=1)
	{
		if(b&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod;
	}
	return r;
}
ll dfs(int u,int l,int r)
{
	if(!u || tag[u]) return 0;
	if(l==r) return 1ll*val[u]*ksm(2,l)%mod;
	int mid=(l+r)>>1;
	return (dfs(ls[u],l,mid)+dfs(rs[u],mid+1,r))%mod;
}
int fa[N],res[N],tres;
bool vis[N];
void dij(int s,int t)
{
	drt[s]=new_node(0);
	q.push((pqnode){s,drt[s]});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		if(u==t)
		{
			printf("%lld\n",dfs(drt[u],0,n));
			for(;u!=s;u=fa[u])res[++tres]=u;
			res[++tres]=u;
			printf("%d\n",tres);
			for(int i=tres;i;i--) printf("%d ",res[i]);
			return;
		}
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			int k=add_one(drt[u],wx[i]);
			if(!vis[v] && (!drt[v] || cmp(k,drt[v])==drt[v]))
			{
				drt[v]=k;
				fa[v]=u;
				q.push((pqnode){v,drt[v]});
			}
		}
	}
	puts("-1");
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	bs[0]=1;
	for(int i=1;i<N;i++) bs[i]=bs[i-1]*base;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	dij(s,t);
	return 0;
}