#include<bits/stdc++.h>
using namespace std;

int p[3010],n,tot;
bool bo[3010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void pre_gao()
{
	for (int i=2;i<=3000;i++)
	{
		if (!bo[i]) p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<=3000;j++)
		{
			bo[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
}

int main()
{
	n=rd();pre_gao();
	for (int i=0;i<n/2;i++) if (!bo[n+i])
	{
		printf("%d\n",n+i);
		for (int i=1;i<=n;i++) printf("%d %d\n",i,i%n+1);
		for (int j=1;j<=i;j++) printf("%d %d\n",j,j+n/2);
		exit(0);
	}
	return 0;
}