#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll num[100010],d[100010],sum[100010],n,m;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	sort(num+1,num+n+1);
	for (int i=1;i<n;i++) d[i]=num[i+1]-num[i];
	d[n]=inf;
	sort(d+1,d+n+1);
	for (int i=1;i<n;i++) sum[i]=sum[i-1]+d[i];
	m=rd();
	while (m--)
	{
		ll x=rd(),y=rd(),now=y-x+1;
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (d[mid]>=now) r=mid;
			else l=mid+1;
		}
		printf("%lld ",sum[l-1]+(ll)(n-l+1)*now);
	}
	puts("");
	return 0;
}