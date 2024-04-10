#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-8

struct point
{
	ll x,y;
	point() {}
	point(ll xx,ll yy):x(xx),y(yy) {}
};

inline point operator -(const point &x,const point &y) { return point(x.x-y.x,x.y-y.y); }
inline ll cross(const point &x,const point &y) { return x.x*y.y-x.y*y.x; }
inline double calc(const point &x,const double &y) { return y*x.x+(double)x.y; }

point a[100010],b[100010],c[100010],st[100010];

int n,tt,top;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool cmp(const point &x,const point &y) { return (x.x!=y.x)?(x.x<y.x):(x.y>y.y); }

inline void pre_gao()
{
	for (int i=1;i<=tt;i++) c[i]=point(b[i].x,b[i].x*b[i].x-b[i].y);
	st[top=1]=c[1];
	for (int i=2;i<=tt;i++)
	{
		while (top>1&&cross(st[top]-st[top-1],c[i]-st[top-1])<=0) top--;
		st[++top]=c[i];
	}
}

inline double work(double hh)
{
	int l=1,r=top;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (calc(st[mid],hh)<calc(st[mid+1],hh)) r=mid;
		else l=mid+1;
	}
	return calc(st[l],hh);
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	sort(a+1,a+n+1,cmp);
	tt=0;
	for (int i=1;i<=n;i++)
	{
		if (!tt) b[++tt]=a[i];
		else if (a[i].x!=b[tt].x) b[++tt]=a[i];
	}
	pre_gao();
	printf("%d\n",top-1);
	return 0;
}