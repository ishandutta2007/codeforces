#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1e6;
const long long inf=1e11;
long long mna[maxn+10],mnb[maxn+10];
int n,m,p,x,y,z;
long long tree[4444444],lazy[4444444];
int xx[222222],yy[222222],zz[222222];
vector<int> v[maxn+10];
long long ans;
void pushup(int node)
{
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}
void push(int node,long long x)
{
	tree[node]+=x;
	lazy[node]+=x;
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void update(int beg,int en,int l,int r,int node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		push(node,x);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=-mnb[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=maxn;i++)
	{
		mna[i]=mnb[i]=1e12;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		mna[x]=min(mna[x],(long long)y);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		mnb[x]=min(mnb[x],(long long)y);
	}
	for (int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&xx[i],&yy[i],&zz[i]);
		v[xx[i]].push_back(i);
	}
	build(1,maxn,1);
	ans=-1e18;
	for (int i=1;i<=maxn;i++)
	{
		for (int j=0;j<v[i-1].size();j++)
		{
			int id=v[i-1][j];
			update(yy[id]+1,maxn,1,maxn,1,zz[id]);
		}
		if (mna[i]<inf) ans=max(ans,1ll*tree[1]-mna[i]);
	}
	printf("%lld\n",ans);
	return Accepted;
}