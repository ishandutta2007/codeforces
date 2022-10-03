#include<bits/stdc++.h>
using namespace std;

int num[100010],from[110],cnt[110],n;

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
	for (int i=1;i<=n;i++)
	{
		int x=num[i];
		for (int j=0;j<30;j++)
		{
			int hh=x&1;
			if (hh) cnt[j]++,from[j]=i;
			x>>=1;
		}
	}
	for (int i=29;~i;i--) if (cnt[i]==1)
	{
		printf("%d ",num[from[i]]);
		for (int j=1;j<=n;j++) if (j!=from[i]) printf("%d ",num[j]);
		puts("");return 0;
	}
	for (int i=1;i<=n;i++) printf("%d ",num[i]);
	return 0;
}