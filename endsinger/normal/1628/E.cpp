#include<bits/stdc++.h>
using namespace std;
const int N=600005;
int n,m,q,f[N],c[N],p[N],sq[N],ti,fa[N][20],rt,d[N],tl[N<<1],tr[N<<1],pl[N<<1],pr[N<<1],tg[N<<1];
struct ed
{
	int u,v,w,d;
	bool operator<(const ed k)const{return w<k.w;}
}g[N];
vector<int>e[N];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void dfs(int u,int f)
{
	fa[u][0]=f,d[u]=d[f]+1;
	if(u<=n)
	{
		ti++;
		sq[ti]=u;
		p[u]=ti;
	}
	for(auto v:e[u])
		dfs(v,u);
}
int lca(int u,int v)
{
	if(d[u]<d[v])
		swap(u,v);
	for(int i=19;i>=0;i--)
		if(d[fa[u][i]]>=d[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void build(int k,int l,int r)
{
	tl[k]=n+1,tr[k]=0,tg[k]=-1;
	if(l==r)
	{
		pl[k]=pr[k]=p[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pl[k]=min(pl[k<<1],pl[k<<1|1]);
	pr[k]=max(pr[k<<1],pr[k<<1|1]);
}
void pu(int k)
{
	tl[k]=min(tl[k<<1],tl[k<<1|1]);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void pt(int k,int v)
{
	if(!v) tl[k]=n+1,tr[k]=0;
	else  tl[k]=pl[k],tr[k]=pr[k];
	tg[k]=v;
}
void pd(int k)
{
	if(tg[k]!=-1)
	{
		pt(k<<1,tg[k]);
		pt(k<<1|1,tg[k]);
		tg[k]=-1;
	}
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		pt(k,v);
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
	pu(k);
}
int main()
{
	scanf("%d%d",&n,&q);
	m=n*2-1;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
		g[i].d=n+i;
		c[n+i]=g[i].w;
	}
	sort(g+1,g+n);
	for(int i=1;i<=m;i++)
		f[i]=i;
	for(int i=1;i<n;i++)
	{
		int u=g[i].u,v=g[i].v,d=g[i].d;
		u=gf(u),v=gf(v);
		e[d].push_back(u);
		e[d].push_back(v);
		f[u]=d,f[v]=d,rt=d;
	}
	dfs(rt,0);
	for(int j=1;j<=19;j++)
		for(int i=1;i<=m;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	build(1,1,n);
	while(q--)
	{
		int o;
		scanf("%d",&o);
		if(o==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			upd(1,1,n,l,r,1);
		}
		if(o==2)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			upd(1,1,n,l,r,0);
		}
		if(o==3)
		{
			int x;
			scanf("%d",&x);
			int vl=sq[tl[1]],vr=sq[tr[1]];
			if(vl==0||(vl==x&&vr==x))
			{
				puts("-1");
				continue;
			}
			int l1=lca(x,vl),l2=lca(x,vr);
			printf("%d\n",max(c[l1],c[l2]));
		}
	}
	return 0;
}