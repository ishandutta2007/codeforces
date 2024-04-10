#include<bits/stdc++.h>
using namespace std;
const int N=500005,inf=1e9;
int n,a[N],dp[N],tr[N];
long long p[N];
vector<long long>v;
struct seg
{
	int tr[N<<2];
	void build(int k,int l,int r)
	{
		tr[k]=-inf;
		if(l==r)
			return;
		int md=l+r>>1;
		build(k<<1,l,md);
		build(k<<1|1,md+1,r);
	}
	void upd(int k,int l,int r,int x,int v)
	{
		if(l==r)
		{
			tr[k]=max(tr[k],v);
			return;
		}
		int md=l+r>>1;
		if(x<=md) upd(k<<1,l,md,x,v);
		else upd(k<<1|1,md+1,r,x,v);
		tr[k]=max(tr[k<<1],tr[k<<1|1]);
	}
	int ask(int k,int l,int r,int a,int b)
	{
		if(a>b)
			return -inf;
		if(l==a&&r==b)
			return tr[k];
		int md=l+r>>1;
		if(b<=md) return ask(k<<1,l,md,a,b);
		else if(a>md) return ask(k<<1|1,md+1,r,a,b);
		else return max(ask(k<<1,l,md,a,md),ask(k<<1|1,md+1,r,md+1,b)); 
	}
}t1,t2;
void sol()
{
	scanf("%d",&n);
	v.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[i]=p[i-1]+a[i];
		v.push_back(p[i]);
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<=n;i++)
		a[i]=lower_bound(v.begin(),v.end(),p[i])-v.begin()+1;
	int m=v.size();
	t1.build(1,1,m);
	t2.build(1,1,m);
	for(int i=1;i<=m;i++)
		tr[i]=-inf;
	dp[0]=0;
	tr[a[0]]=0;
	t1.upd(1,1,m,a[0],0);
	t2.upd(1,1,m,a[0],0);
	for(int i=1;i<=n;i++)
	{
		dp[i]=tr[a[i]];
		dp[i]=max(dp[i],t1.ask(1,1,m,1,a[i]-1)+i);
		dp[i]=max(dp[i],t2.ask(1,1,m,a[i]+1,m)-i);
		tr[a[i]]=max(tr[a[i]],dp[i]);
		t1.upd(1,1,m,a[i],dp[i]-i);
		t2.upd(1,1,m,a[i],dp[i]+i);
	}
	printf("%d\n",dp[n]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}