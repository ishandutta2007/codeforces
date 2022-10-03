#include<bits/stdc++.h>
using namespace std;

int *num[1000010],*mx1[1000010],*mx2[1000010],*res[1000010];
int *h1[1000010],*h2[1000010];
int n,m;
char s[1000010];

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
	for (int i=0;i<=n+1;i++)
	{
		num[i]=new int[m+2];
		mx1[i]=new int[m+2];
		mx2[i]=new int[m+2];
		res[i]=new int[m+2];
		h1[i]=new int[m+2];
		h2[i]=new int[m+2];
	}
	for (int i=0;i<=m+1;i++) num[0][i]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		num[i][0]=num[i][m+1]=0;
		for (int j=1;j<=m;j++) num[i][j]=(s[j]=='X');
	}
	for (int i=1;i<=n;i++)
	{
		mx1[i][m+1]=0;
		for (int j=m;j;j--) mx1[i][j]=(num[i][j])?mx1[i][j+1]+1:0;
	}
	for (int i=1;i<=m;i++)
	{
		mx2[n+1][i]=0;
		for (int j=n;j;j--) mx2[j][i]=(num[j][i])?mx2[j+1][i]+1:0;
	}
	int ans=2000000;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) if (!num[i][j-1]&&num[i][j]) ans=min(ans,(mx1[i][j]+1)/2);
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (!num[i-1][j]&&num[i][j]) ans=min(ans,(mx2[i][j]+1)/2);
	printf("%d\n",ans-1);
	ans=ans*2-1;
	for (int i=1;i<=n;i++)
	{
		h1[i][m+1]=0;
		for (int j=m;j;j--) h1[i][j]=(mx2[i][j]>=ans)?h1[i][j+1]+1:0;
	}
	for (int i=1;i<=m;i++)
	{
		h2[n+1][i]=0;
		for (int j=n;j;j--) h2[j][i]=(mx1[j][i]>=ans)?h2[j+1][i]+1:0;
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) res[i][j]=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (h1[i][j]>=ans&&h2[i][j]>=ans) res[i+ans/2][j+ans/2]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) putchar((res[i][j])?'X':'.');
		putchar('\n');
	}
	return 0;
}