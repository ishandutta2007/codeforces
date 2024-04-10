#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1010][1010],b[1010][1010];
int num[1010][1010],len1[1010],len2[1010],n,m;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) num[i][j]=rd();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) a[i][j]=num[i][j];
		sort(a[i]+1,a[i]+m+1);
		len1[i]=unique(a[i]+1,a[i]+m+1)-a[i]-1;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++) b[i][j]=num[j][i];
		sort(b[i]+1,b[i]+n+1);
		len2[i]=unique(b[i]+1,b[i]+n+1)-b[i]-1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int h1=lower_bound(a[i]+1,a[i]+len1[i]+1,num[i][j])-a[i];
			int h2=lower_bound(b[j]+1,b[j]+len2[j]+1,num[i][j])-b[j];
			printf("%d ",max(h1-1,h2-1)+max(len1[i]-h1,len2[j]-h2)+1);
		}
		putchar('\n');
	}
	return 0;
}