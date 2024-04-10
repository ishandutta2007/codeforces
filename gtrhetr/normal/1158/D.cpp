#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct point
{
	ll x,y;
	point() {}
	point(ll xx,ll yy):x(xx),y(yy) {}
}a[2010];

inline point operator -(const point &x,const point &y) { return point(x.x-y.x,x.y-y.y); }
inline ll cross(const point &x,const point &y) { return x.x*y.y-x.y*y.x; }

int ans[2010],n;
char s[2010];
bool vis[2010];

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
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

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	scanf("%s",s+1);
	int vs=1;
	for (int i=2;i<=n;i++) if (a[i].x<a[vs].x||(a[i].x==a[vs].x&&a[i].y<a[vs].y)) vs=i;
	vis[vs]=true;ans[1]=vs;
	int now=vs;
	for (int i=2;i<n;i++)
	{
		if (s[i-1]=='L')
		{
			int hh=0;
			for (int j=1;j<=n;j++) if (!vis[j])
			{
				if (!hh) hh=j;
				else if (cross(a[j]-a[now],a[hh]-a[now])>0) hh=j;
			}
			vis[hh]=true;now=hh;ans[i]=hh;
		}
		else
		{
			int hh=0;
			for (int j=1;j<=n;j++) if (!vis[j])
			{
				if (!hh) hh=j;
				else if (cross(a[j]-a[now],a[hh]-a[now])<0) hh=j;
			}
			vis[hh]=true;now=hh;ans[i]=hh;
		}
	}
	for (int i=1;i<=n;i++) if (!vis[i]) ans[n]=i;
	for (int i=1;i<=n;i++) print(ans[i]);
	putchar('\n');
	return 0;
}