#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
struct point{
	ll x,y;
	point(ll X=0,ll Y=0):x(X),y(Y){}
	friend point operator +(const point a,const point b){return point(a.x+b.x,a.y+b.y);}
	friend point operator -(const point a,const point b){return point(a.x-b.x,a.y-b.y);}
	friend ll operator *(const point a,const point b){return a.x*b.y-a.y*b.x;}
	bool operator <(const point a)const{return x==a.x?y>a.y:x<a.x;}
}p[N],q[N],o;
ll cross(point a,point o,point b){return (a-o)*(b-o);}
double work(point &a,point &b)
{
	ll x0=a*b,x1=a*o,x2=o*b;
	if(x0==0 || 1.0*x1/x0<0 || 1.0*x2/x0<0) return 1e18;
	return 1.0*x1/x0+1.0*x2/x0;
}
int main()
{
	int n,tot=0;
	scanf("%d%lld%lld",&n,&o.x,&o.y);
	ll xm=0,ym=0;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].x,&p[i].y),xm=max(xm,p[i].x),ym=max(ym,p[i].y);
	double ans=1e18;
	for(int i=1;i<=n;i++) ans=min(ans,max(1.0*o.x/p[i].x,1.0*o.y/p[i].y));
	p[++n]=point(xm,0);p[++n]=point(0,ym);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		while(tot>1 && cross(q[tot-1],q[tot],p[i])<=0) --tot;
		q[++tot]=p[i];
	}
	for(int i=2;i<=tot;i++) ans=min(ans,work(q[i-1],q[i]));
	printf("%.8f",ans);
	return 0;
}