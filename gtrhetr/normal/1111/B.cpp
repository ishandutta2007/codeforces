#include<bits/stdc++.h>
using namespace std;
#define ll long long

double a[100010],sum[100010];
ll n,k,m;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();m=rd();
	for (ll i=1;i<=n;i++) a[i]=rd();
	double ans=0;
	sort(a+1,a+n+1);
	for (ll i=n;i;i--) sum[i]=sum[i+1]+a[i];
	for (ll i=1;i<=n;i++)
	{
		if (i-1>m) break;
		double res=sum[i];
		res+=min((n-i+1)*k,m-(i-1));
		ans=max(ans,res/(n-i+1));
	}
	printf("%.10lf\n",ans);
	return 0;
}