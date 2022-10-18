#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
struct edge
{
	int nxt,to,weight;
}e[200001<<1];
struct mst
{
	int id,x,y,weight;
}v[200001];
int cost,tot,cnt,n,m,a[200001],w[200001],id[200001],top[200001],dep[200001],fa[200001],s[200001],son[200001],sw[200001],ans[200001<<2],h[200001],bin[200001];
bool inmst[200001];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void add(int x,int y,int w)
{
	e[++tot].nxt=h[x];
	h[x]=tot;
	e[tot].to=y;
	e[tot].weight=w;
}
inline bool cmp1(mst a,mst b)
{
	return a.weight<b.weight;
}
inline bool cmp2(mst a,mst b)
{
	return a.id<b.id;
}
int anc(int k)
{
	if(!bin[k])
		return k;
	return bin[k]=anc(bin[k]);
}
inline void link(int a,int b)
{
	a=anc(a);
	b=anc(b);
	if(a!=b)
		bin[b]=a;
}
inline void kruskal()
{
	int num=0;
	sort(v+1,v+m+1,cmp1);
	for(register int i=1;i<=m;++i)
		if(anc(v[i].x)!=anc(v[i].y))
		{
			link(v[i].x,v[i].y);
			inmst[v[i].id]=1;
			add(v[i].x,v[i].y,v[i].weight);
			add(v[i].y,v[i].x,v[i].weight);
			cost+=v[i].weight;
			if(++num==n-1)
				return;
		}
}
inline int ls(int k)
{
	return k<<1;
}
inline int rs(int k)
{
	return k<<1|1;
}
inline void push_up(int k)
{
	ans[k]=max(ans[ls(k)],ans[rs(k)]);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		ans[k]=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(k),l,mid);
	build(rs(k),mid+1,r);
	push_up(k);
}
int query(int nl,int nr,int l,int r,int k)
{
	if(l>=nl&&r<=nr)
		return ans[k];
	int mid=(l+r)>>1,res=0;
	if(nl<=mid)
		res=max(res,query(nl,nr,l,mid,ls(k)));
	if(nr>mid)
		res=max(res,query(nl,nr,mid+1,r,rs(k)));
	return res;
}
void dfs1(int k,int f,int deep)
{
	fa[k]=f;
	s[k]=1;
	dep[k]=deep;
	int maxson=-1;
	for(register int i=h[k];i;i=e[i].nxt)
	{
		if(e[i].to==f)
			continue;
		dfs1(e[i].to,k,deep+1);
		s[k]+=s[e[i].to];
		if(s[e[i].to]>maxson)
		{
			maxson=s[e[i].to];
			son[k]=e[i].to;
			sw[k]=e[i].weight;
		}
	}
}
void dfs2(int k,int t,int val)
{
	id[k]=++cnt;
	w[cnt]=val;
	top[k]=t;
	if(!son[k])
		return;
	dfs2(son[k],t,sw[k]);
	for(register int i=h[k];i;i=e[i].nxt)
	{
		if(e[i].to==fa[k]||e[i].to==son[k])
			continue;
		dfs2(e[i].to,e[i].to,e[i].weight);
	}
}
inline int q(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		res=max(res,query(id[top[x]],id[x],1,n,1));
		//res=max(res,w[id[top[x]]]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	res=max(res,query(id[x]+1,id[y],1,n,1));
	return res;
}
signed main()
{
	n=read(),m=read();
	for(register int i=1;i<=m;++i)
	{
		v[i].x=read(),v[i].y=read(),v[i].weight=read();
		v[i].id=i;
		if(v[i].x>v[i].y)
			swap(v[i].x,v[i].y);
	}
	kruskal();
	dfs1(1,0,1);
	dfs2(1,1,0);
	build(1,1,n);
	sort(v+1,v+m+1,cmp2); 
	for(register int i=1;i<=m;++i)
	{
		if(inmst[i])
		{
			printf("%lld\n",cost);
			continue;
		}
		printf("%lld\n",cost+v[i].weight-q(v[i].x,v[i].y));
	}
	return 0;
}