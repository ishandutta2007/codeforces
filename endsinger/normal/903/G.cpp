#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,m,q,a[N],b[N],c[N],tr[N<<2],tag[N<<2];
vector<pair<int,int>>e[N];
void build(int k,int l,int r)
{
	tag[k]=0;
	if(l==r)
	{
		tr[k]=b[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<n;i++)
		cin>>a[i]>>b[i+1];
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].emplace_back(v,w);
	}
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		for(auto &c:e[i])
			update(1,1,n,1,c.first,c.second);
		c[i]=tr[1];
	}
	for(int i=1;i<=n;i++)
		b[i]=a[i]+c[i];
	build(1,1,n);
	cout<<tr[1]<<endl;
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		update(1,1,n,u,u,v-a[u]);
		a[u]=v;
		cout<<tr[1]<<endl;
	}
	return 0;
}