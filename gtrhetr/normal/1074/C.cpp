#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2123333333

struct point
{
	ll x,y;
	point() {}
	point(ll xx,ll yy):x(xx),y(yy) {}
}a[300010];

int id[5],n;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline ll gao(int x,int y,int z)
{
	ll mn1=inf,mx1=-inf,mn2=inf,mx2=-inf;
	mn1=min(mn1,a[x].x);
	mx1=max(mx1,a[x].x);
	mn2=min(mn2,a[x].y);
	mx2=max(mx2,a[x].y);
	mn1=min(mn1,a[y].x);
	mx1=max(mx1,a[y].x);
	mn2=min(mn2,a[y].y);
	mx2=max(mx2,a[y].y);
	mn1=min(mn1,a[z].x);
	mx1=max(mx1,a[z].x);
	mn2=min(mn2,a[z].y);
	mx2=max(mx2,a[z].y);
	return (mx1-mn1)*2+(mx2-mn2)*2;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	ll mn1=inf,mx1=-inf,mn2=inf,mx2=-inf;
	for (int i=1;i<=n;i++)
	{
		if (a[i].x<mn1) id[1]=i,mn1=a[i].x;
		if (a[i].x>mx1) id[2]=i,mx1=a[i].x;
		if (a[i].y<mn2) id[3]=i,mn2=a[i].y;
		if (a[i].y>mx2) id[4]=i,mx2=a[i].y;
	}
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<4;j++) for (int k=j+1;k<=4;k++) ans=max(ans,gao(i,id[j],id[k]));
	}
	print(ans);
	for (int i=4;i<=n;i++) print((mx1-mn1+mx2-mn2)*2);
	putchar('\n');
	return 0;
}