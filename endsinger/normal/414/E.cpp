#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,rt,c,sz[N],lc[N],rc[N],d[N],tg[N],h[N],t0[N],t1[N],pl[N],pr[N],fa[N],ti,mp[N];
vector<int>e[N];
void dfs(int u,int p)
{
	pl[u]=++ti;
	for(auto v:e[u])
		dfs(v,p+1);
	pr[u]=++ti;
	sz[pl[u]]=1,d[pl[u]]=p,t0[pl[u]]=p,t1[pl[u]]=p,h[pl[u]]=rand();
	sz[pr[u]]=1,d[pr[u]]=p,t0[pr[u]]=p,t1[pr[u]]=p,h[pr[u]]=rand();
	mp[pl[u]]=mp[pr[u]]=u;
}
void pu(int k)
{
	sz[k]=1;
	t0[k]=t1[k]=d[k];
	if(lc[k]) sz[k]+=sz[lc[k]],t0[k]=min(t0[k],t0[lc[k]]),t1[k]=max(t1[k],t1[lc[k]]),fa[lc[k]]=k;
	if(rc[k]) sz[k]+=sz[rc[k]],t0[k]=min(t0[k],t0[rc[k]]),t1[k]=max(t1[k],t1[rc[k]]),fa[rc[k]]=k;
}
void pt(int k,int x)
{
	d[k]+=x;
	t0[k]+=x;
	t1[k]+=x;
	tg[k]+=x;
}
void pd(int k)
{
	if(tg[k])
	{
		if(lc[k]) pt(lc[k],tg[k]);
		if(rc[k]) pt(rc[k],tg[k]);
		tg[k]=0;
	}
}
int mg(int x,int y)
{
	if(!x||!y)
		return x^y;
	pd(x);
	pd(y);
	if(h[x]>h[y])
	{
		rc[x]=mg(rc[x],y);
		pu(x);
		return x;
	}
	else
	{
		lc[y]=mg(x,lc[y]);
		pu(y);
		return y;
	}
}
void split(int k,int c,int &x,int &y)
{
	if(!k)
	{
		x=y=0;
		return;
	}
	pd(k);
	fa[k]=0;
	if(sz[lc[k]]+1<=c)
	{
		x=k;
		split(rc[k],c-sz[lc[k]]-1,rc[k],y);
	}
	else
	{
		y=k;
		split(lc[k],c,x,lc[k]);
	}
	pu(k);
}
int rk(int k)
{
	pd(k);
	int c=sz[lc[k]]+1;
	while(fa[k])
	{
		if(rc[fa[k]]==k)
			c+=sz[lc[fa[k]]]+1;
		k=fa[k];
	}
	return c;
}
void apd(int k)
{
	if(fa[k]) apd(fa[k]);
	pd(k);
}
int dep(int k)
{
	apd(k);
	return d[k];
}
int qmin(int l,int r)
{
	if(l>r)
		swap(l,r);
	int s1,s2,s3;
	split(rt,l-1,s1,s2);
	split(s2,r-l+1,s2,s3);
	int ans=t0[s2];
	rt=mg(s1,mg(s2,s3));
	return ans;
}
int ask(int k,int c)
{
	pd(k);
	if(rc[k]&&t0[rc[k]]<=c&&c<=t1[rc[k]])
		return ask(rc[k],c);
	if(d[k]==c)
		return k;
	return ask(lc[k],c);
}
int query(int l,int r,int c)
{
	int s1,s2,s3;
	split(rt,l-1,s1,s2);
	split(s2,r-l+1,s2,s3);
	int ans=ask(s2,c);
	rt=mg(s1,mg(s2,s3));
	return ans;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int m,x;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			e[i].push_back(x);
		}
	}
	dfs(1,1);
	rt=1;
	for(int i=2;i<=n*2;i++)
		rt=mg(rt,i);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%d\n",u==v?0:dep(pl[u])+dep(pl[v])-2*(qmin(rk(pl[u])+1,rk(pl[v])+1)-1));
		}
		if(op==2)
		{
			int u,h;
			scanf("%d%d",&u,&h);
			int du=dep(pl[u]),al=rk(pl[u]),ar=rk(pr[u]);
			int f=mp[query(1,al,du-h)];
			int s1,s2,s3,s4;
			split(rt,al-1,s1,s2);
			split(s2,ar-al+1,s2,s3);
			pt(s2,-h+1);
			s1=mg(s1,s3);
			int ps=rk(pr[f]);
			split(s1,ps-1,s1,s3);
			rt=mg(s1,mg(s2,s3));
		}
		if(op==3)
		{
			int c;
			scanf("%d",&c);
			c++;
			printf("%d\n",mp[query(1,n*2,c)]);
		}
	}
	return 0;
}