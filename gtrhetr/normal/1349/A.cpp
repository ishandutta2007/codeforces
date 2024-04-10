#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll num[100010],pre[100010],suf[100010],n;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll getlcm(ll x,ll y) { return x/__gcd(x,y)*y; }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) pre[i]=__gcd(pre[i-1],num[i]);
	for (int i=n;i;i--) suf[i]=__gcd(suf[i+1],num[i]);
	ll ans=0;
	for (int i=1;i<=n;i++) ans=__gcd(ans,getlcm(num[i],__gcd(pre[i-1],suf[i+1])));
	printf("%lld\n",ans);
	return 0;
}