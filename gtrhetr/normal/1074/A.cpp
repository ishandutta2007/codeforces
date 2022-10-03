#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333

struct node { int x1,x2,y; }a[100010];

int num[100010],h[100010],n,m,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();tt=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=m;i++) a[i].x1=rd(),a[i].x2=rd(),a[i].y=rd();
	int res=0;
	for (int i=1;i<=m;i++) if (a[i].x1==1)
	{
		if (a[i].x2<1000000000) h[++tt]=a[i].x2;
		else res++;
	}
	sort(h+1,h+tt+1);sort(num+1,num+n+1);
	int now=1;
	int ans=inf;
	for (int i=0;i<=tt;i++)
	{
		while (now<=n&&num[now]<=h[i]) now++;
		ans=min(ans,tt-i+(now-1));
	}
	printf("%d\n",ans+res);
	return 0;
}