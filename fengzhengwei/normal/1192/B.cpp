#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char c;int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,q,w;
struct node
{
	int next,to,v;
}e[1000005];
int h[1000005];
int cnt;
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	e[cnt].to=y;
	e[cnt].v=z;
	h[x]=cnt;
}
int f[1000005];
int st[1000005];
int ed[1000005];
int oul[1000005];
int cst;
int val[1000005];
int d[1000005];
void dfs(int x,int y)
{
	f[x]=y;
	st[x]=++cst;
	oul[cst]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to!=y)
		{
			val[e[i].to]=e[i].v;
			d[e[i].to]=e[i].v+d[x];
			dfs(e[i].to,x);
			oul[++cst]=x;
		}
	}
	ed[x]=cst;
}
int maxx[1000005];
int minn[1000005];
int lz[1000005];
int rz[1000005];
int lzr[1000005];
int Add[1000005];
void update(int k,int l,int r)
{
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
	minn[k]=min(minn[k<<1],minn[k<<1|1]);
	lz[k]=max(lz[k<<1],max(lz[k<<1|1],maxx[k<<1]-minn[k<<1|1]));
	rz[k]=max(rz[k<<1],max(rz[k<<1|1],maxx[k<<1|1]-minn[k<<1]));
	lzr[k]=max(lzr[k<<1],max(lzr[k<<1|1],max(lz[k<<1]+maxx[k<<1|1],rz[k<<1|1]+maxx[k<<1])));
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		maxx[k]=d[oul[l]];
		minn[k]=2*d[oul[l]];
		lz[k]=rz[k]=-d[oul[l]];
		lzr[k]=0;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k,l,r);
}
void Ad(int k,int l,int r,int v)
{
	maxx[k]+=v;
	minn[k]+=2*v;
	lz[k]-=v;
	rz[k]-=v;
	Add[k]+=v;
}
void pd(int k,int l,int r)
{
	if(!Add[k])return;
	int mid=l+r>>1;
	Ad(k<<1,l,mid,Add[k]);
	Ad(k<<1|1,mid+1,r,Add[k]);
	Add[k]=0;
}
void change(int k,int l,int r,int x,int y,int v)
{
	if(r<x||y<l)return;
	if(x<=l&&r<=y)
	{
		Ad(k,l,r,v);
		return;
	}
	pd(k,l,r);
	int mid=l+r>>1;
	change(k<<1,l,mid,x,y,v);
	change(k<<1|1,mid+1,r,x,y,v);
	update(k,l,r);
}
int uu[1000005];
int vv[1000005];
signed main(){
	n=read();
	q=read();
	w=read();
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		a=read();
		b=read();
		c=read();
		add(a,b,c);
		add(b,a,c);
		uu[i]=a;
		vv[i]=b;
	}
	dfs(1,0);
	build(1,1,2*n-1);
	int lastans=0;
	for(int i=1;i<=q;i++)
	{
		int a,b;
		a=read();
		b=read();
		a+=lastans;
		a%=(n-1);
		a++;
		b+=lastans;
		b%=w;
		int x,y;
		x=uu[a];
		y=vv[a];
		if(f[x]==y)
		{
			a=x;
		}
		else 
		{
			a=y;
		}
		change(1,1,2*n-1,st[a],ed[a],b-val[a]);
		val[a]=b;
		printf("%lld\n",lastans=lzr[1]);
	}
	return 0;
}