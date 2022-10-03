#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll num[233],sum[233],n,b,tot;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();b=rd();
	tot=0;
	for (ll i=2;i*i<=b;i++) if (b%i==0)
	{
		num[++tot]=i;
		while (b%i==0) b/=i,sum[tot]++;
	}
	if (b!=1) num[++tot]=b,sum[tot]=1;
	ll ans=inf;
	for (ll i=1;i<=tot;i++)
	{
		ll hh=num[i],res=0;
		ll m=n;
		while (m>=hh) res+=m/hh,m/=hh;
		ans=min(ans,res/sum[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}