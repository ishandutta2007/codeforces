#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define inf 2333333333LL

priority_queue<pll,vector<pll>,greater<pll> > q;

ll d[400010],m,a,b,ans;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

inline ll calc(ll x,ll y) { return (x+y)*(y-x+1)/2+(y-x+1); }

inline void gao(ll n)
{
	for (int i=0;i<=n;i++) d[i]=inf;
	d[0]=0;q.push(pll(0,0));
	while (!q.empty())
	{
		pll hh=q.top();q.pop();
		int x=hh.second;
		if (d[x]<hh.first) continue;
		if (x+a<=n)
		{
			if (d[x+a]>max((ll)x+a,d[x]))
			{
				d[x+a]=max((ll)x+a,d[x]);
				q.push(pll(d[x+a],x+a));
			}
		}
		if (x>=b)
		{
			if (d[x-b]>max((ll)x,d[x]))
			{
				d[x-b]=max((ll)x,d[x]);
				q.push(pll(d[x-b],x-b));
			}
		}
	}
	for (int i=0;i<=n;i++) if (d[i]<inf) ans+=(n-d[i]+1);
}

int main()
{
	m=rd();a=rd();b=rd();
	ans=0;
	ll hh=gcd(a,b);
	if (m>=(a+b)*2)
	{
		ll l=(a+b)*2,r=m/hh*hh;
		if (l<r)
		{
			r-=hh;
			ans+=calc(l/hh,r/hh)*hh;
			r+=hh;
		}
		for (ll i=r;i<=m;i++) ans+=(i/hh+1);
	}
	gao(min(m,(a+b)*2-1));
	printf("%lld\n",ans);
	return 0;
}