#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100510
#define C 410
#define B 254
#define L(x) (x*B-B+1)
#define R(x) (x*B)
#define re register
using namespace std;
int fa[N],rt[C][N],val[C][N];
int pos[N],maxn[N],num[N],bl[N],tag[N];
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
void reset(int x)
{
	for(re int i=L(x);i<=R(x);i++)
	{
		int u=pos[find(i)];
		rt[x][u]=val[x][u]=0;
		num[i]=u-tag[x];
	}
    for(re int i=L(x);i<=R(x);i++) fa[i]=i;
    tag[x]=0;
}
void build(int x)
{
	maxn[x]=0;
	for(re int i=L(x);i<=R(x);i++)
	{
		maxn[x]=max(maxn[x],num[i]);
		if(!rt[x][num[i]]){pos[i]=num[i],rt[x][num[i]]=i;}
		fa[i]=rt[x][num[i]];
		val[x][num[i]]++;
	}
}
void merge(int u,int x,int y)
{
	if(!rt[u][y]) rt[u][y]=rt[u][x],pos[rt[u][x]]=y;
	else fa[rt[u][x]]=rt[u][y];
	val[u][y]+=val[u][x];
	val[u][x]=rt[u][x]=0;
}
void set_tag(int x,int v)
{
	if(maxn[x]-tag[x]>=2*v)
	{
		for(re int i=tag[x]+1;i<=tag[x]+v;i++)
		if(rt[x][i]) merge(x,i,i+v);
		tag[x]+=v;
	}
	else if(maxn[x]>tag[x]+v)
	{
		for(re int i=maxn[x];i>tag[x]+v;i--)
		if(rt[x][i]) merge(x,i,i-v);
		maxn[x]=tag[x]+v;
	}
}
void _insert(int l,int r,int v)
{
	int p=bl[l];
	reset(p);
	for(re int i=l;i<=r;i++) if(num[i]>v) num[i]-=v;
	build(p);
}
int _answer(int l,int r,int v)
{
	int ans=0,p=bl[l];
	for(re int i=l;i<=r;i++)
	if(pos[find(i)]-tag[p]==v) ++ans;
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]),bl[i]=(i-1)/B+1;
	for(int i=1;i<=bl[n];i++) build(i);
	while(m --> 0)
	{
		int opt,l,r,v;
		scanf("%d%d%d%d",&opt,&l,&r,&v);
		if(opt==1)
		{
			int pl=bl[l],pr=bl[r];
			if(pl==pr) _insert(l,r,v);
			else
			{
				_insert(l,R(pl),v);
				for(re int i=pl+1;i<=pr-1;i++) set_tag(i,v);
				_insert(L(pr),r,v);
			}
		}
		else
		{
			int pl=bl[l],pr=bl[r],ans=0;
			if(pl==pr) ans=_answer(l,r,v);
			else
			{
				ans=_answer(l,R(pl),v);
				for(re int i=pl+1;i<=pr-1;i++)
				if(v+tag[i]<N) ans+=val[i][v+tag[i]]; 
				ans+=_answer(L(pr),r,v);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}