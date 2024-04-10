#include<cstdio>
#include<iostream>
using namespace std;
const int N=500;
const double eps=1e-8;
struct point
{
	double x,y;
	point(double X=0.0,double Y=0.0) { x=X,y=Y;}
};
struct line
{
	double a,b,c;
	line(double A=0.0,double B=0.0,double C=0.0) { a=A,b=B,c=C;}
};
point p[N],q[N];
int cnt,n,m;
double ans[N];
int a[N][N];
inline line getline(double a,double b,double c)
{
	return line(a,b,c);
}
inline line getline(point a,point b)
{
	return line(a.y-b.y,b.x-a.x,b.x*a.y-a.x*b.y);
}
inline point intersect(line a,line b)
{
	double tmp=a.a*b.b-a.b*b.a;
	double x=a.c*b.b-a.b*b.c,y=a.a*b.c-a.c*b.a;
	x/=tmp;y/=tmp;
	return point(x,y);
}
inline void cut(double a,double b,double c) 
{
	// x= 1  a*x+b*y>=c
	// x=-1  a*x+b*y<=c
	int tot=0;
	
	if ( a*p[1].x+b*p[1].y<c ) q[++tot]=point(p[1].x,(c-a*p[1].x)/b);
	
	for (int i=1;i<=cnt;i++)
	if ( (a*p[i].x+b*p[i].y)+eps>=c ) q[++tot]=p[i];else
	{
		if ( a*p[i-1].x+b*p[i-1].y+eps>=c&&i>1 ) q[++tot]=intersect(getline(p[i-1],p[i]),getline(a,b,c));
		if ( a*p[i+1].x+b*p[i+1].y+eps>=c&&i<n ) q[++tot]=intersect(getline(p[i+1],p[i]),getline(a,b,c));
	}
	
	if ( a*p[cnt].x+b*p[cnt].y<c ) q[++tot]=point(p[cnt].x,(c-a*p[cnt].x)/b);
	
	cnt=tot;
	for (int i=1;i<=cnt;i++) p[i]=q[i];
}
double calc()
{
	double res=0;
	for (int i=1;i<=cnt-1;i++) res+=(p[i].y+p[i+1].y)*(p[i+1].x-p[i].x)/2;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=0;j<=m;j++)
		scanf("%d",&a[i][j]);
	for (int j=0;j< m;j++)
	{
		cnt=2;
		p[1]=point(0,0);p[2]=point(1,0);
		for (int i=1;i<=n;i++)
		{
			double A=a[i][j]-a[i][j+1],b=1,c=a[i][j];
			cut(A,b,c);
			ans[i]+=calc();
		}
	}
	for (int i=n;i>=1;i--) ans[i]-=ans[i-1];
	for (int i=1;i<=n;i++) printf("%.6lf\n",ans[i]);
	return 0;//a.y-b.y,b.x-a.x,b.x*a.y-a.x*b.y);
}