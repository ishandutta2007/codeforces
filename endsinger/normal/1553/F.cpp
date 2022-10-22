#include<bits/stdc++.h>
using namespace std;
const int N=300005,mx=300000;
int n,a[N],sz[N<<2];
long long tr[N<<2],tg[N<<2],s,v1[N<<2],v2[N<<2];
void build(int k,int l,int r)
{
	sz[k]=r-l+1;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pd(int k)
{
	if(tg[k])
	{
		tr[k<<1]+=tg[k]*sz[k<<1];
		tg[k<<1]+=tg[k];
		tr[k<<1|1]+=tg[k]*sz[k<<1|1];
		tg[k<<1|1]+=tg[k];
		tg[k]=0;
	}
}
void add(int k,int l,int r,int a,int b,long long v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v*sz[k];
		tg[k]+=v;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
long long ask(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return ask(k<<1,l,mid,a,mid)+ask(k<<1|1,mid+1,r,mid+1,b);
}
void upd(int k,int l,int r,int x)
{
	if(l==r)
	{
		v1[k]++;
		v2[k]+=l;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) upd(k<<1,l,mid,x);
	else upd(k<<1|1,mid+1,r,x);
	v1[k]=v1[k<<1]+v1[k<<1|1];
	v2[k]=v2[k<<1]+v2[k<<1|1];
}
long long ask1(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return v1[k];
	int mid=l+r>>1;
	if(b<=mid) return ask1(k<<1,l,mid,a,b);
	else if(a>mid) return ask1(k<<1|1,mid+1,r,a,b);
	else return ask1(k<<1,l,mid,a,mid)+ask1(k<<1|1,mid+1,r,mid+1,b);
}
long long ask2(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return v2[k];
	int mid=l+r>>1;
	if(b<=mid) return ask2(k<<1,l,mid,a,b);
	else if(a>mid) return ask2(k<<1|1,mid+1,r,a,b);
	else return ask2(k<<1,l,mid,a,mid)+ask2(k<<1|1,mid+1,r,mid+1,b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,mx);
	for(int i=1;i<=n;i++)
	{
		s+=ask(1,1,mx,1,a[i]);
		if(a[i]>1)
		{
			int l=0,r;
			while(l<=mx)
			{
				r=l+a[i]-1;
				s+=ask2(1,1,mx,max(l,1),min(r,mx))-l*ask1(1,1,mx,max(l,1),min(r,mx));
				l=r+1;
			}
		}
		if(a[i]>1)
		{
			int p=1;
			while(p<=mx)
			{
				int q=p+a[i]-1;
				add(1,1,mx,p,min(q-1,mx),1);
				if(q<=mx)
					add(1,1,mx,q,q,-a[i]+1);
				p=q+1;
			}
		}
		upd(1,1,mx,a[i]);
		printf("%lld ",s);
	}
	return 0;
}