#include<bits/stdc++.h>
using namespace std;
#define ll long long

int s1[1048576],s2[1048576];
int num[300010],sum[300010],n;

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
	ll ans=0;
	for (int i=0;i<=n;i++)
	{
		if (i) sum[i]=sum[i-1]^num[i];
		if (i&1)
		{
			ans+=s1[sum[i]];s1[sum[i]]++;
		}
		else
		{
			ans+=s2[sum[i]];s2[sum[i]]++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}