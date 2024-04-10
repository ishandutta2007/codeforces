#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200010],b[200010];
int n,m,ta,tb,k;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	n=rd();m=rd();ta=rd();tb=rd();k=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=m;i++) b[i]=rd();
	for (int i=1;i<=n;i++) a[i]+=ta;
	if (k>=n||k>=m) { puts("-1");return 0; }
	bool flag=true;
	for (int i=0;i<=min(n,k);i++)
	{
		if ((k-i)>m) continue;
		if (a[i+1]>b[m-(k-i)]) { flag=false;break; }
	}
	if (!flag) { puts("-1");return 0; }
	int now=1,hh=1;
	ll ans=0;
	for (int i=0;i<=k;i++)
	{
		while (b[now]<a[i+1]) now++;
		ans=max(ans,b[now+(k-i)]);
	}
	printf("%lld\n",ans+tb);
	return 0;
}