#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { ll a,b;double p; }a[100010];

struct point
{
	double x,y;
	point() {}
	point(double xx,double yy):x(xx),y(yy) {}
}h[100010],st[100010];

inline point operator -(const point &x,const point &y) { return point(x.x-y.x,x.y-y.y); }
inline double cross(const point &x,const point &y) { return x.x*y.y-x.y*y.x; }

struct matrix
{
	double a[3][3];
	matrix() { memset(a,0,sizeof(a)); }
	inline void init() { memset(a,0,sizeof(a)); }
};

matrix f[100010],f1[233],f2[233];

inline matrix operator *(const matrix &x,const matrix &y)
{
	matrix res;
	for (int i=0;i<3;i++) for (int k=0;k<3;k++) for (int j=0;j<3;j++) res.a[i][j]+=x.a[i][k]*y.a[k][j];
	return res;
}

inline matrix ksm(matrix x,ll y)
{
	matrix res;
	for (int i=0;i<3;i++) res.a[i][i]=1;
	for (;y;y>>=1,x=x*x) if (y&1) res=res*x;
	return res;
}

ll t,n,top;
double mx;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const point &x,const point &y) { return (x.x!=y.x)?x.x<y.x:x.y<y.y; }

inline void pre_gao()
{
	sort(h+1,h+n+1,cmp);
	st[top=1]=h[1];
	for (int i=2;i<=n;i++)
	{
		while (top>1&&cross(h[i]-st[top-1],st[top]-st[top-1])<=0) top--;
		st[++top]=h[i];
	}
}

int main()
{
	n=rd();t=rd();
	for (int i=1;i<=n;i++) a[i].a=rd(),a[i].b=rd(),scanf("%lf",&a[i].p);
	for (int i=1;i<=n;i++) h[i].x=a[i].p,h[i].y=a[i].p*a[i].a;
	mx=0;
	for (int i=1;i<=n;i++) mx=max(mx,a[i].p*a[i].b);
	pre_gao();
	int now=1;
	while (now<top&&st[now].y<st[now+1].y) now++;
	matrix res;
	res.a[0][2]=1;
	for (int i=1;i<=top;i++)
	{
		f[i].a[0][0]=1-st[i].x;
		f[i].a[1][0]=st[i].x*mx;
		f[i].a[2][0]=st[i].y;
		f[i].a[1][1]=f[i].a[2][1]=f[i].a[2][2]=1;
	}
	for (;now<top;now++)
	{
		f1[0].init();
		for (int i=0;i<3;i++) f1[0].a[i][i]=1;
		f2[0]=f1[0]*f[now];
		int tt=0;
		for (int i=1;(1LL<<i)<=t;i++)
		{
			tt=i;
			f1[i]=(f1[i-1]*f1[i-1])*f[now];
			f2[i]=f1[i]*f[now];
		}
		for (int i=tt;~i;i--) if ((1LL<<i)<=t)
		{
			double cur1=((res*f1[i])*f[now+1]).a[0][0],cur2=(res*f2[i]).a[0][0];
			if (cur2>=cur1) res=res*f2[i],t-=(1LL<<i);
		}
		if (!t) break;
	}
	res=res*ksm(f[top],t);
	printf("%.10lf\n",res.a[0][0]);
	return 0;
}