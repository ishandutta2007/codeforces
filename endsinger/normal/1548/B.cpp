#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long a[N],tr[N<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=__gcd(tr[k<<1],tr[k<<1|1]);
}
long long ask(int k,int l,int r,int a,int b)
{
	if(a>b)
		return 0;
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	return __gcd(ask(k<<1,l,mid,a,mid),ask(k<<1|1,mid+1,r,mid+1,b));
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==1)
	{
		puts("1");
		return;
	}
	for(int i=1;i<n;i++)
		a[i]=abs(a[i]-a[i+1]);
	n--;
	build(1,1,n);
	int ans=0;
	for(int l=1,r=0;l<=n;l++)
	{
		while(r+1<=n&&ask(1,1,n,l,r+1)!=1)
			r++;
		if(ask(1,1,n,l,r)!=1)
			ans=max(ans,r-l+1);
	}
	printf("%d\n",ans+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}