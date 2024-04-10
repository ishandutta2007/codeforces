#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long double db;
const int MAXN = 1e3 + 5;
const db eps = 1e-7;
using namespace std;

inline db Fabs(db x){ return x<0? -x: x;}
inline bool eq(db x,db y){ return Fabs(x-y)<=eps;}

struct Point
{
	db x,y;
}p[MAXN];
inline db dist(const Point &u,const Point &v){ return sqrt((u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y));}

struct Line
{
	db a,b;
	inline void calc(Point u,Point v)
	{
		a = (u.y-v.y)/(u.x-v.x),
		b = u.y - a * u.x;
	}
	inline int pos(Point u)
	{
		db y = a*u.x + b;
		if(eq(y,u.y)) return 0;
		if(y < u.y) return 1;
		return -1;
	}
	
	inline Line(Point u,Point v){ calc(u,v);}
};

struct Point_
{
	Point u;
	int id;
}q[MAXN];
int ql;
inline void push(Point u,int id){ q[++ql].u=u; q[ql].id=id;}
inline bool cmp(const Point_ &u,const Point_ &v){ return u.u.x<v.u.x;}

int n;
inline void solve(Point u,Point v)
{
	Line l(u,v);
	
	ql=0;
	for(int i=1; i<=n; ++i)
	{
		int p1=l.pos(p[i-1]), p2=l.pos(p[i]), p3=l.pos(p[i+1]);
		if(!p2)
		{
			if(p1!=p3) push(p[i], p1+p3);
		}
		else if(p2+p3==0)
		{
			if(eq(p[i].x, p[i+1].x)) push((Point){ p[i].x, l.a*p[i].x + l.b},0);
			else
			{
				Line l2(p[i],p[i+1]);
				db x = (l.b - l2.b)/(l2.a - l.a);
				push((Point){x, l.a*x + l.b},0);
			}
		}
	}
	
	sort(q+1,q+ql+1,cmp);
	db ans=0;
	int flag=0,flag2=0;
	for(int i=1; i<ql; ++i)
	{
		if(q[i].id && !flag2)
		{
			flag2=1;
			ans+=dist(q[i].u,q[i+1].u);
			if(q[i].id==q[i+1].id) flag^=1;
			continue;
		}
		
		flag2=0;
		flag^=1;
		if(flag) ans+=dist(q[i].u,q[i+1].u);
	}
	printf("%.20lf\n",(double)ans);
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		p[i] = (Point){x,y};
	}
	p[0]=p[n];
	p[n+1]=p[1];
	
	while(m--)
	{
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		if(eq(x1,x2))
		{
			swap(x1,y1); swap(x2,y2);
			for(int i=0; i<=n+1; ++i) swap(p[i].x,p[i].y);
			solve((Point){x1,y1}, (Point){x2,y2});
			for(int i=0; i<=n+1; ++i) swap(p[i].x,p[i].y);
		}
		else solve((Point){x1,y1}, (Point){x2,y2});
	}
	return 0;
}