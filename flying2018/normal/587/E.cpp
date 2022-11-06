#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
struct base{
	#define B 30
	int b[B+2],tot;
	base(){memset(b,0,sizeof(b));tot=0;}
	void clear(){memset(b,0,sizeof(b));tot=0;}
	void insert(int x)
	{
		for(int i=B;i>=0;i--)
		if((x>>i)&1){if(b[i]) x^=b[i]; else{b[i]=x;++tot;return;}}
	}
};
base operator +(base a,base b)
{
	for(int i=0;i<B;i++)
	if(b.b[i]) a.insert(b.b[i]);
	return a;
}
base val[N<<2];
int a[N],b[N];
void build(int u,int l,int r)
{
	if(l==r){val[u].insert(b[l]);return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	val[u]=val[u<<1]+val[u<<1|1];
}
void insert(int u,int l,int r,int p,int v)
{
	if(l==r){val[u].clear();val[u].insert(v);return;}
	int mid=(l+r)>>1;
	if(p<=mid) insert(u<<1,l,mid,p,v);
	else insert(u<<1|1,mid+1,r,p,v);
	val[u]=val[u<<1]+val[u<<1|1];
}
base ans;
void answer(int u,int l,int r,int L,int R)
{
	if(L<=l && r<=R){ans=ans+val[u];return;}
	int mid=(l+r)>>1;
	if(L<=mid) answer(u<<1,l,mid,L,R);
	if(R>mid) answer(u<<1|1,mid+1,r,L,R);
}
namespace t2{
	int val[N<<2];
	void build(int u,int l,int r)
	{
		if(l==r){val[u]=b[l];return;}
		int mid=(l+r)>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		val[u]=val[u<<1]^val[u<<1|1];
	}
	void insert(int u,int l,int r,int p,int v)
	{
		if(l==r){val[u]=v;return;}
		int mid=(l+r)>>1;
		if(p<=mid) insert(u<<1,l,mid,p,v);
		else insert(u<<1|1,mid+1,r,p,v);
		val[u]=val[u<<1]^val[u<<1|1];
	}
	int answer(int u,int l,int r,int L,int R)
	{
		if(L<=l && r<=R) return val[u];
		int mid=(l+r)>>1,ans=0;
		if(L<=mid) ans^=answer(u<<1,l,mid,L,R);
		if(R>mid) ans^=answer(u<<1|1,mid+1,r,L,R);
		return ans;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i-1]^a[i];
	build(1,1,n);
	t2::build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,l,r,v;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			scanf("%d",&v);
			b[l]^=v;
			b[r+1]^=v;
			insert(1,1,n,l,b[l]);
			insert(1,1,n,r+1,b[r+1]);
			t2::insert(1,1,n,l,b[l]);
			t2::insert(1,1,n,r+1,b[r+1]);
		}
		else
		{
			ans.clear();
			if(l!=r) answer(1,1,n,l+1,r);
			ans.insert(t2::answer(1,1,n,1,l));
			printf("%lld\n",1ll<<ans.tot);
		}
	}
	return 0;
}