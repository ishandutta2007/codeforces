#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

pll b[200010],num[200010];

ll a[200010],c[200010],n,m;
bool bo[200010];

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
	for (int i=1;i<=n;i++) a[i]=b[i].first=rd(),b[i].second=i;
	m=n;
	for (int i=1;i<=m;i++) num[i]=b[i];
	int ans=0;
	while (m)
	{
		int res=0;
		for (int i=1;i<=m;i++) if (num[i].first&1) res++;
		if (res>ans)
		{
			ans=res;
			memset(bo,false,sizeof(bo));
			for (int i=1;i<=m;i++) if (num[i].first&1) bo[num[i].second]=true;
		}
		int tt=0;
		for (int i=1;i<=m;i++) if (num[i].first%2==0) b[++tt]=num[i],b[tt].first/=2;
		m=tt;
		for (int i=1;i<=m;i++) num[i]=b[i];
	}
	printf("%d\n",n-ans);
	for (int i=1;i<=n;i++) if (!bo[i]) printf("%lld ",a[i]);
	return 0;
}