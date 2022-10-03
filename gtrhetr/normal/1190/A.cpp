#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll num[100010],n,m,k;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();k=rd();
	for (int i=1;i<=m;i++) num[i]=rd();
	ll ans=0;
	int cur=1;
	while (cur<=m)
	{
		ll hh=((num[cur]-(cur-1))+k-1)/k;
		int pre=cur-1;
		while (cur<=m&&(num[cur]-pre)<=hh*k) cur++;
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}