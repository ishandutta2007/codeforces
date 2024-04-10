#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
long long ans=LLONG_MAX;
long long sol(int x)
{
	long long s=0,v;
	v=0;
	for(int i=x-1;i>=1;i--)
	{
		v++;
		s+=(v+a[i]-1)/a[i];
		v=(v+a[i]-1)/a[i]*a[i];
	}
	v=0;
	for(int i=x+1;i<=n;i++)
	{
		v++;
		s+=(v+a[i]-1)/a[i];
		v=(v+a[i]-1)/a[i]*a[i];
	}
	return s;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		ans=min(ans,sol(i));
	printf("%lld\n",ans);
	return 0;
}