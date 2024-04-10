#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct point
{
	int x,y;
	point() {}
	point(int xx,int yy):x(xx),y(yy) {}
}a[310];

inline point operator -(const point &x,const point &y) { return point(x.x-y.x,x.y-y.y); }
inline ll cross(const point &x,const point &y) { return (ll)x.x*y.y-(ll)x.y*y.x; }

struct node
{
	int vs,vt,x,y;
}h[100010];

ll f[310][310][6],g[310][310][6];
int n,tot;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool cmp(const node &x,const node &y)
{
	return cross(point(x.x,x.y),point(y.x,y.y))>0;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	tot=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
	{
		if (i==j) continue;
		if (a[j].y==a[i].y&&a[j].x>a[i].x) continue;
		if (a[j].y<a[i].y) continue;
		h[++tot]=(node){i,j,a[j].x-a[i].x,a[j].y-a[i].y};
	}
	sort(h+1,h+tot+1,cmp);
	for (int i=1;i<=tot;i++)
	{
		int x=h[i].vs,y=h[i].vt;
		f[x][y][1]=1;
		for (int j=1;j<=n;j++) if (j!=x&&j!=y)
		{
			f[j][y][2]+=f[j][x][1];
			f[j][y][3]+=f[j][x][2];
			f[j][y][4]+=f[j][x][3];
			f[j][y][5]+=f[j][x][4];
		}
	}
	tot=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
	{
		if (i==j) continue;
		if (a[j].y==a[i].y&&a[j].x<a[i].x) continue;
		if (a[j].y>a[i].y) continue;
		h[++tot]=(node){i,j,a[j].x-a[i].x,a[j].y-a[i].y};
	}
	sort(h+1,h+tot+1,cmp);
	for (int i=1;i<=tot;i++)
	{
		int x=h[i].vs,y=h[i].vt;
		g[x][y][1]=1;
		for (int j=1;j<=n;j++) if (j!=x&&j!=y)
		{
			g[j][y][2]+=g[j][x][1];
			g[j][y][3]+=g[j][x][2];
			g[j][y][4]+=g[j][x][3];
			g[j][y][5]+=g[j][x][4];
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i!=j)
	{
		for (int k=1;k<5;k++) ans+=f[i][j][k]*g[j][i][5-k];
	}
	printf("%lld\n",ans);
	return 0;
}