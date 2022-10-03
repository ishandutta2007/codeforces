#include<bits/stdc++.h>
using namespace std;

int num[200010],h[200010],t,n,tt;
bool bo[200010];
char s[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) num[i]=s[i]-'0';
	for (int i=-1;i<=10;i++)
	{
		int mn=n+1,mx=0;
		for (int j=1;j<=n;j++)
		{
			if (num[j]>i) mn=min(mn,j);
			if (num[j]<i) mx=max(mx,j);
		}
		bool flag=true;
		for (int j=1;j<=n;j++) if (num[j]==i&&(j>=mn&&j<=mx)) flag=false;
		if (!flag) continue;
		for (int j=1;j<=n;j++) if (num[j]!=i) bo[j]=(num[j]>i)?1:0;
		for (int j=1;j<=n;j++) if (num[j]==i)
		{
			if (j<mn) bo[j]=1;
			else bo[j]=0;
		}
		tt=0;
		for (int j=1;j<=n;j++) if (!bo[j]) h[++tt]=num[j];
		for (int j=1;j<=n;j++) if (bo[j]) h[++tt]=num[j];
		flag=true;
		for (int j=2;j<=n;j++) if (h[j]<h[j-1]) flag=false;
		if (flag)
		{
			for (int j=1;j<=n;j++) putchar(bo[j]+'1');
			putchar('\n');
			return;
		}
	}
	putchar('-');putchar('\n');
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}