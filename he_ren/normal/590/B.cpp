#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long double ldb;
const ldb inf = 1e13;
const ldb eps = 1e-7;

inline ldb Fabs(ldb x){ return x<0? -x: x;}
inline bool eq(ldb x,ldb y){ return Fabs(x-y)<=eps;}
inline bool geq(ldb x,ldb y){ return x>y || eq(x,y);}

struct Node
{
	ldb x,y;
	inline void read(void)
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		x=xx; y=yy;
	}
}s,to,v,w;
typedef Node Vec;

inline ldb dist(Node p,Node q){ return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));}

int vm,t;

inline bool chk(ldb mid)
{
	Node a={0,0};
	if(mid>t)
	{
		a.x = v.x*t + w.x*(mid-t);
		a.y = v.y*t + w.y*(mid-t);
	}
	else
	{
		a.x = v.x*mid;
		a.y = v.y*mid;
	}
	
	return geq(mid*vm, dist(a,to));
}

int main(void)
{
	s.read(); to.read();
	scanf("%d%d",&vm,&t);
	v.read(); w.read();
	
	to.x-=s.x; to.y-=s.y;
	
	ldb l=0, r=inf;
	while(r-l > eps)
	{
		ldb mid = (l+r)/2;
		if(chk(mid)) r=mid;
		else l=mid+eps;
	}
	
	printf("%.15lf",(double)l);
	return 0;
}