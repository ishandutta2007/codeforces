#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
struct edge
{
	int u,v,c;
	bool operator<(const edge k)const
	{
		return c<k.c;
	}
}e[N];
int n,ans,a[N],f;
struct UnionFind
{
	int parent[N],rnk[N];
	int init(int n)
	{
		for(int i=1;i<=n;i++)
			parent[i]=i,rnk[i]=1;
	}
	int root(int x)
	{
		if(parent[x]!=x)
			parent[x]=root(parent[x]);
		return parent[x];
	}
	int connect(int x,int y,int zh)
	{
		int rx=root(x),ry=root(y);
		if(rx==ry)
			return 0;
		ans+=rnk[rx]*rnk[ry]*f*zh;
		parent[ry]=rx;
		rnk[rx]+=rnk[ry];
		return 1;
	}
}uf;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		cin>>e[i].u>>e[i].v;
	for(int i=1;i<n;i++)
		e[i].c=max(a[e[i].u],a[e[i].v]);
	sort(e+1,e+n);
	uf.init(n);
	f=1;
	for(int i=1;i<n;i++)
		uf.connect(e[i].u,e[i].v,e[i].c);
	for(int i=1;i<n;i++)
		e[i].c=min(a[e[i].u],a[e[i].v]);
	sort(e+1,e+n);
	reverse(e+1,e+n);
	uf.init(n);
	f=-1;
	for(int i=1;i<n;i++)
		uf.connect(e[i].u,e[i].v,e[i].c);
	cout<<ans<<endl;
	return 0;
}