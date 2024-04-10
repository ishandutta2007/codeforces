#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll num[300010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	sort(num+1,num+n+1);
	ll ans=0;
	for (int i=1;i<=n/2;i++) ans+=(num[i]+num[n-i+1])*(num[i]+num[n-i+1]);
	printf("%I64d\n",ans);
	return 0;
}