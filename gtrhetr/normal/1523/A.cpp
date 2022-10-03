#include<bits/stdc++.h>
using namespace std;

int num[1010],num1[1010],t,n,m;
char s[1010],s1[1010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();m=rd();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) num[i]=s[i]-'0';
	for (int i=1;i<=min(m,n);i++)
	{
		num[0]=num[n+1]=0;
		for (int j=1;j<=n;j++) if (!num[j])
		{
			if (num[j-1]+num[j+1]==1) num1[j]=1;
			else num1[j]=0;
		}
		else num1[j]=1;
		for (int j=1;j<=n;j++) num[j]=num1[j];
	}
	for (int i=1;i<=n;i++) putchar(num[i]+'0');
	putchar('\n');
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}