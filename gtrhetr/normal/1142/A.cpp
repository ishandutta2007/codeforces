#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll n,k,a,b;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

int main()
{
	n=rd();k=rd();a=rd();b=rd();
	ll mn=inf,mx=0;
	if (a<=b)
	{
		ll hh=b-a;
		for (ll i=0;i<=n;i++)
		{
			if (!hh&&!i) continue;
			ll now=hh+k*i;
			mn=min(mn,n*k/gcd(n*k,now));
			mx=max(mx,n*k/gcd(n*k,now));
		}
		hh=k-b-a;
		for (ll i=0;i<=n;i++)
		{
			if (!hh&&!i) continue;
			ll now=hh+k*i;
			mn=min(mn,n*k/gcd(n*k,now));
			mx=max(mx,n*k/gcd(n*k,now));
		}
		hh=a+b;
		for (ll i=0;i<=n;i++)
		{
			if (!hh&&!i) continue;
			ll now=hh+k*i;
			mn=min(mn,n*k/gcd(n*k,now));
			mx=max(mx,n*k/gcd(n*k,now));
		}
	}
	else
	{
		ll hh=k-b-a;
		for (ll i=0;i<=n;i++)
		{
			if (!hh&&!i) continue;
			ll now=hh+k*i;
			mn=min(mn,n*k/gcd(n*k,now));
			mx=max(mx,n*k/gcd(n*k,now));
		}
		hh=a+b;
		for (ll i=0;i<=n;i++)
		{
			if (!hh&&!i) continue;
			ll now=hh+k*i;
			mn=min(mn,n*k/gcd(n*k,now));
			mx=max(mx,n*k/gcd(n*k,now));
		}
		hh=a-b;
		for (ll i=0;i<=n;i++)
		{
			if (!hh&&!i) continue;
			ll now=hh+k*i;
			mn=min(mn,n*k/gcd(n*k,now));
			mx=max(mx,n*k/gcd(n*k,now));
		}
	}
	printf("%lld %lld\n",mn,mx);
	return 0;
}