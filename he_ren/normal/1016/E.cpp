#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
typedef long double ldb;
const int MAXN = 2e5 + 5;

inline int read(void)
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') res=res*10+c-'0', c=getchar();
	return res*f;
}

struct Seg
{
	ldb l,r;
}a[MAXN];
ldb sum[MAXN];

inline bool cmpl(const Seg &p,const Seg &q){ return p.l<q.l;}
inline bool cmpr(const Seg &p,const Seg &q){ return p.r<q.r;}

struct Point
{
	ldb x,y;
};

ldb passx(Point u,Point v)
{
	ldb dx=u.x-v.x, dy=u.y-v.y;
	return u.x - u.y/dy*dx;
}

int main(void)
{
	ldb sy=read(),sl=read(),sr=read();
	Point A={sl,sy}, B={sr,sy};
	int n=read();
	for(int i=1; i<=n; ++i)
		a[i].l=read(), a[i].r=read();
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1]+(a[i].r-a[i].l);
	
	int q=read();
	while(q--)
	{
		ldb x=read(), y=read();
		Point p={x,y};
		
		ldb u=passx(p,A), v=passx(p,B);
		int s1=lower_bound(a+1,a+n+1,(Seg){0,u},cmpr)-a;
		int s2=upper_bound(a+1,a+n+1,(Seg){v,0},cmpl)-a-1;
		//printf("%Lf %Lf\n",u,v);
		//printf("%d %d\n",s1,s2);
		
		if(s2<s1){ printf("0\n"); continue;}
		ldb len = sum[s2]-sum[s1-1];
		if(a[s1].l<=u) len -= u-a[s1].l;
		if(a[s2].r>=v) len -= a[s2].r-v;
		
		ldb ans = (y-sy)/y*len;
		printf("%.20lf\n",(db)ans);
	}
	return 0;
}