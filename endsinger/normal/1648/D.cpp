#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[3][N];
long long p[3][N],vl[N],vr[N],ans=LLONG_MIN;
struct qu{int l,r,w;};
vector<qu>q[N];
struct seg1
{
	long long tr[N<<2];
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]=vl[l];
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		tr[k]=max(tr[k<<1],tr[k<<1|1]);
	}
	void upd(int k,int l,int r,int x)
	{
		if(l==r)
		{
			tr[k]=vl[l];
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) upd(k<<1,l,mid,x);
		else upd(k<<1|1,mid+1,r,x);
		tr[k]=max(tr[k<<1],tr[k<<1|1]);
	}
	long long ask(int k,int l,int r,int a,int b)
	{
		if(l==a&&r==b)
			return tr[k];
		int mid=l+r>>1;
		if(b<=mid) return ask(k<<1,l,mid,a,b);
		else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
		else return max(ask(k<<1,l,mid,a,mid),ask(k<<1|1,mid+1,r,mid+1,b));
	}
}t1;
struct nd{long long ml,mr,mv;};
nd operator+(nd a,nd b)
{
	nd c;
	c.ml=max(a.ml,b.ml);
	c.mr=max(a.mr,b.mr);
	c.mv=max(max(a.mv,b.mv),a.ml+b.mr);
	return c;
}
struct seg2
{
	nd tr[N<<2];
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]={vl[l],vr[l],vl[l]+vr[l]};
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
	nd ask(int k,int l,int r,int a,int b)
	{
		if(l==a&&r==b)
			return tr[k];
		int mid=l+r>>1;
		if(b<=mid) return ask(k<<1,l,mid,a,b);
		else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
		else return ask(k<<1,l,mid,a,mid)+ask(k<<1|1,mid+1,r,mid+1,b);
	}
}t2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int j=0;j<=2;j++)
		for(int i=1;i<=n;i++)
			scanf("%d",&a[j][i]),p[j][i]=p[j][i-1]+a[j][i];
	for(int i=1;i<=n;i++)
	{
		vl[i]=p[0][i]-p[1][i-1];
		vr[i]=p[1][i]+p[2][n]-p[2][i-1];
	}
	for(int i=1;i<=m;i++)
	{
		int l,r,w;
		scanf("%d%d%d",&l,&r,&w);
		q[r].push_back({l,r,w});
	}
	t1.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		for(auto j:q[i])
		{
			long long v=t1.ask(1,1,n,j.l,j.r)-j.w;
			vl[i+1]=max(vl[i+1],v);
			if(i<n)
				t1.upd(1,1,n,i+1);
		}
	}
	t2.build(1,1,n);
	for(int i=1;i<=n;i++)
		for(auto j:q[i])
			ans=max(ans,t2.ask(1,1,n,j.l,j.r).mv-j.w);
	printf("%lld\n",ans);
	return 0;
}