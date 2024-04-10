#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans1[100010],ans2[100010];
ll a[100010],b[100010],c[100010],n,tt;
char s1[100010],s2[100010];

inline void gao(ll x,ll y)
{
	if (!y) return;
	a[x]+=y;a[x+1]+=y;
	if (a[x+1]>9) gao(x+1,9-a[x+1]);
	if (a[x+1]<0) gao(x+1,0-a[x+1]);
	for (ll i=1;i<=abs(y);i++)
	{
		tt++;
		printf("%lld %lld\n",x,(y<0)?-1LL:1LL);
		if (tt==100000) exit(0);
	}
}

int main()
{
	scanf("%lld%s%s",&n,s1+1,s2+1);
	for (ll i=1;i<=n;i++) c[i]=a[i]=s1[i]-'0',b[i]=s2[i]-'0';
	ll ans=0;
	for (ll i=1;i<n;i++)
	{
		ll hh=b[i]-c[i];
		ans+=abs(hh);
		c[i+1]+=hh;
	}
	if (c[n]!=b[n]) { puts("-1");return 0; }
	printf("%lld\n",ans);
	tt=0;
	for (ll i=1;i<n;i++) gao(i,b[i]-a[i]);
	return 0;
}