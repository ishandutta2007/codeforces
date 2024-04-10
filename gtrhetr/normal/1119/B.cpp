#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll num[1010],h[1010],n,m;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool check(ll mid)
{
	int tt=0;
	for (int i=1;i<=mid;i++) h[++tt]=num[i];
	sort(h+1,h+tt+1);
	if (!(tt&1))
	{
		ll hh=0;
		for (int i=2;i<=tt;i+=2) hh+=h[i];
		return (hh<=m);
	}
	ll hh=0;
	for (int i=1;i<=tt;i+=2) hh+=h[i];
	return (hh<=m);
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int l=1,r=n;
	while (l<r)
	{
		int mid=((l+r)>>1)+1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}