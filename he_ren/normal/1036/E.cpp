#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;
const int MAXN = 1e3 + 5;
const ll linf = 1e18;
const ldb eps = 1e-8;

inline void swap(int &a,int &b){ int t=a; a=b; b=t;}

inline ldb Fabs(ldb x){ return x<0? -x: x;}
inline bool eq(ldb x,ldb y){ return Fabs(x-y)<=eps;}

int gcd(int a,int b){ return b? gcd(b,a%b): a;}
inline int Abs(int x){ return x<0? -x: x;}

inline bool in(int l,int r,ll x){ return (l<=x && x<=r) || (r<=x && x<=l);}

struct Point
{
	int x,y;
	inline void read(void){ scanf("%d%d",&x,&y);}
	inline friend bool operator < (const Point &p,const Point &q){ return p.x==q.x? p.y<q.y: p.x<q.x;}
	inline friend bool operator == (const Point &p,const Point &q){ return p.x==q.x && p.y==q.y;}
};

struct Seg
{
	Point p,q;
	ldb k,b;
	inline void calc(void)
	{
		if(p.x==q.x){ k=linf; b=-linf; return;}
		k = (ldb)(p.y-q.y)/(p.x-q.x);
		b = p.y - k*p.x;
	}
	inline void read(void)
	{
		p.read(); q.read();
		if(p.x>q.x) swap(p,q);
		calc();
	}
	inline bool inx(ll x){ return in(p.x,q.x,x);}
	inline bool iny(ll y){ return in(p.y,q.y,y);}
}a[MAXN];

Point crs[MAXN];
int cnt=0;
void chk(Seg a,Seg b)
{
	if(eq(a.k,b.k)) return;
	if(eq(b.k,linf)) swap(a,b);
	
	ldb k1=a.k, b1=a.b;
	ldb k2=b.k, b2=b.b;
	
	if(eq(k1,linf))
	{
		int x=a.p.x;
		if(!b.inx(x)) return;
		ldb yy = k2*x + b2;
		ll y=roundl(yy);
		if(!eq(y,yy) || !a.iny(y)) return;
		crs[++cnt]=(Point){x,(int)y};
		return;
	}
	
	ldb xx = (b2-b1)/(k1-k2), yy = k1*xx + b1;
	ll x=roundl(xx), y=roundl(yy);
	
	if(eq(x,xx) && eq(y,yy))
		if(a.inx(x) && a.iny(y) && b.inx(x) && b.iny(y))
			crs[++cnt]=(Point){(int)x,(int)y};
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		a[i].read();
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		cnt=0;
		for(int j=i+1; j<=n; ++j)
			chk(a[i],a[j]);
		sort(crs+1,crs+cnt+1);
		cnt = unique(crs+1,crs+cnt+1)-crs-1;
		
		int dx = Abs(a[i].p.x - a[i].q.x);
		int dy = Abs(a[i].p.y - a[i].q.y);
		ans += gcd(dx,dy)+1-cnt;
	}
	
	printf("%lld",ans);
	return 0;
}