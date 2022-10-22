#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=40;
struct xxj
{
	int d[M];
	void init(){for(int i=0;i<=29;i++)d[i]=0;}
	void add(int v)
	{
		for(int i=29;i>=0&&v;i--)
		{
			if(v>>i&1)
			{
				if(d[i])
					v^=d[i];
				else
				{
					d[i]=v;
					break;
				}
			}
		}
	}
	int ask(int v)
	{
		for(int i=29;i>=0;i--)
			v=min(v,v^d[i]);
		return v;
	}
};
struct nd{int u,v,w;}qs[N];
int n,m,q,ans[N],f[N],sz[N],tx[N],su[N],sv[N],tp;
int fa(int x){return x==f[x]?x:fa(f[x]);}
int val(int x){return x==f[x]?0:(val(f[x])^tx[x]);}
map<pair<int,int>,pair<int,int>>mp;
vector<nd>tr[N<<2];
void add(int k,int l,int r,int a,int b,nd v)
{
	if(l==a&&r==b)
	{
		tr[k].push_back(v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
}
void undo(int d)
{
	while(tp>d)
	{
		int u=su[tp],v=sv[tp];
		f[u]=u,tx[u]=0;
		sz[v]-=sz[u];
		tp--;
	}
}
void dfs(int k,int l,int r,xxj z)
{
	int d=tp;
	for(auto i:tr[k])
	{
		int u=i.u,v=i.v,w=i.w^val(u)^val(v);
		u=fa(u),v=fa(v);
		if(u==v)
		{
			z.add(w);
			continue;
		}
		if(sz[u]>sz[v])
			swap(u,v);
		tp++,su[tp]=u,sv[tp]=v;
		f[u]=v,sz[v]+=sz[u],tx[u]=w;
	}	
	if(l==r)
	{
		if(qs[l].w)
			ans[qs[l].w]=z.ask(val(qs[l].u)^val(qs[l].v));
		undo(d);
		return;
	}
	int mid=l+r>>1;
	dfs(k<<1,l,mid,z);
	dfs(k<<1|1,mid+1,r,z);
	undo(d);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		mp[{u,v}]={0,w};
	}	
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int op,u,v,w;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&u,&v,&w);
			mp[{u,v}]={i,w};
		}
		if(op==2)
		{
			scanf("%d%d",&u,&v);
			add(1,0,q,mp[{u,v}].first,i-1,{u,v,mp[{u,v}].second});
			mp[{u,v}]={-1,-1};
		}
		if(op==3)
		{
			scanf("%d%d",&u,&v);
			qs[i]={u,v,i};
		}
	}
	for(auto i:mp)
		if(i.second.first!=-1)
			add(1,0,q,i.second.first,q,{i.first.first,i.first.second,i.second.second});
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	xxj z;
	z.init();
	dfs(1,0,q,z);
	for(int i=1;i<=q;i++)
		if(qs[i].w)
			printf("%d\n",ans[i]);
	return 0;
}