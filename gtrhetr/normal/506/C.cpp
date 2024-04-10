#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll h[100010],a[100010],l[100010],cnt[5010],n,m,k,p;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check(ll mid)
{
	ll sum=0;
	for (int i=1;i<=n;i++)
	{
		l[i]=h[i]+a[i]*m;
		if (l[i]>mid) sum+=(l[i]-mid+p-1)/p;
	}
	if (sum>m*k) return false;
	for (int i=1;i<=m;i++) cnt[i]=0;
	for (int i=1;i<=n;i++) if (l[i]>mid)
	{
		for (ll hh=(l[i]-mid-1)%p+1;hh<=l[i]-mid;hh+=p)
		{
			if (hh<=h[i]) cnt[1]++;
			else
			{
				ll now=(hh-h[i]+a[i]-1)/a[i]+1;
				if (now>m) return false;
				cnt[now]++;
			}
		}
	}
	ll res=0;
	for (int i=1;i<=m;i++) res=max(res+cnt[i]-k,0LL);
	return res==0;
}

int main()
{
	n=rd();m=rd();k=rd();p=rd();
	for (int i=1;i<=n;i++) h[i]=rd(),a[i]=rd();
	ll l=0,r=6000000000000LL;
	while (l<r)
	{
		ll mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}