#include<bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>

struct point { int x,y; }a[100010];

const double pi=acos(-1.0);

double d[100010],p[100010];
int n,m,tt;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int fa[400010][20],mx[400010];

pdd h[100010];

double num[200010];

inline double calc(double x)
{
	if (x<0) x+=pi*2;
	if (x>=pi*2) x-=pi*2;
	return x;
}

inline bool check(double mid)
{
	for (int i=1;i<=n;i++) if (mid>d[i]) return false;
	tt=0;
	for (int i=1;i<=n;i++)
	{
		double now=acos(mid/d[i]);
		double h1=calc(p[i]-now),h2=calc(p[i]+now);
		num[++tt]=h1;num[++tt]=h2;
		h[i]=pdd(h1,h2);
	}
	sort(num+1,num+tt+1);
	tt=unique(num+1,num+tt+1)-num-1;
	for (int i=0;i<=18;i++) fa[tt*2+1][i]=tt*2+1;
	for (int i=1;i<=tt*2;i++) mx[i]=tt*2+1;
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(num+1,num+tt+1,h[i].first)-num;
		int r=lower_bound(num+1,num+tt+1,h[i].second)-num;
		if (l<=r)
		{
			mx[l-1]=min(mx[l-1],r);
			mx[l-1+tt]=min(mx[l-1+tt],r+tt);
		}
		else mx[l-1]=min(mx[l-1],r+tt);
	}
	for (int i=tt*2-1;i;i--) mx[i]=min(mx[i],mx[i+1]);
	for (int i=1;i<=tt*2;i++) fa[i][0]=mx[i];
	for (int i=tt*2;i;i--) for (int j=1;j<=18;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
	bool flag=false;
	for (int i=1;i<=tt;i++)
	{
		int now=i;
		for (int j=18;~j;j--) if ((m>>j)&1) now=fa[now][j];
		if (now>=i+tt) flag=true;
	}
	return flag;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++)
	{
		a[i].x=rd();a[i].y=rd();
		d[i]=sqrt((double)a[i].x*a[i].x+(double)a[i].y*a[i].y);
		double now=atan2(a[i].y,a[i].x);
		if (now<0) now+=pi*2;
		p[i]=now;
	}
	double maxn=0;
	for (int i=1;i<=n;i++) maxn=max(maxn,d[i]);
	double l=0,r=maxn;
	for (int i=1;i<=50;i++)
	{
		double mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%.10lf\n",l);
	return 0;
}