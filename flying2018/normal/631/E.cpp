#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
ll f[N],a[N];
ll s[N];
int q[N],qt;
int solve(ll v)
{
	int l=2,r=qt,res=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(s[q[mid]]-s[q[mid-1]]<=v*(q[mid]-q[mid-1])) l=mid+1,res=mid;
		else r=mid-1;
	}
	return q[res];
}
int main()
{
	int n;
	ll sm=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),s[i]=s[i-1]+a[i],sm+=1ll*a[i]*i;
	q[qt=1]=0;
	for(int i=1;i<=n;i++)
	{
		for(;qt>1 && (s[q[qt]]-s[q[qt-1]])*(i-q[qt])>=(s[i]-s[q[qt]])*(q[qt]-q[qt-1]);--qt);
		q[++qt]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int p=solve(a[i]);
		ans=max(ans,(p-i)*a[i]+s[i]-s[p]);
	}
	printf("%lld\n",sm+ans);
	return 0;
}