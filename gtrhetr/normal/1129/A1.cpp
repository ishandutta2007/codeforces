#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333

int sum[5010],mn[5010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline int to(int x,int y)
{
	if (x<=y) return y-x;
	return y+n-x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) mn[i]=inf;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd(),z=to(x,y);
		sum[x]++;mn[x]=min(mn[x],z);
	}
	for (int i=1;i<=n;i++)
	{
		int ans=0;
		for (int j=1;j<=n;j++) if (sum[j]) ans=max(ans,to(i,j)+(sum[j]-1)*n+mn[j]);
		print(ans);
	}
	putchar('\n');
	return 0;
}