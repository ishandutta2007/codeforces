#include<bits/stdc++.h>
using namespace std;

const int maxn=15000000;

int num[300010],mn[15000010],p[15000010],sum[15000010],n,tot;
bool bo[15000010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int gcd(int x,int y) { return (!y)?x:gcd(y,x%y); }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int hh=num[1];
	for (int i=2;i<=n;i++) hh=gcd(hh,num[i]);
	bool flag=true;
	for (int i=1;i<=n;i++) if (num[i]!=hh) flag=false;
	if (flag) { puts("-1");return 0; }
	for (int i=2;i<=15000000;i++)
	{
		if (!bo[i]) p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<=15000000;j++)
		{
			bo[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
	for (int i=1;i<=n;i++) sum[num[i]]++;
	int ans=n+1;
	for (int i=1;i<=tot&&p[i]*hh<=15000000;i++)
	{
		int hhh=0,now=hh*p[i];
		for (int j=now;j<=15000000;j+=now) hhh+=sum[j];
		ans=min(ans,n-hhh);
	}
	printf("%d\n",ans);
	return 0;
}