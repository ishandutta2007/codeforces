#include<bits/stdc++.h>
using namespace std;
#define ll long long

int b[100010],g[100010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) b[i]=rd();
	for (int i=1;i<=m;i++) g[i]=rd();
	sort(b+1,b+n+1);sort(g+1,g+m+1);
	if (b[n]>g[1]) { puts("-1");return 0; }
	if (b[n]==g[1])
	{
		ll ans=0;
		for (int i=1;i<n;i++) ans+=(ll)b[i]*m;
		for (int i=1;i<=m;i++) ans+=g[i];
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=0;
	for (int i=1;i<n;i++) ans+=(ll)b[i]*m;
	for (int i=2;i<=m;i++) ans+=g[i];
	ans+=b[n];ans+=g[1]-b[n-1];
	printf("%lld\n",ans);
	return 0;
}