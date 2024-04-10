#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <array>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return a>b?a=b,1:0;}

using ll = long long;
using ld = long double;

const int MX = 1e5+10;
const int MN = 1e5+10;
const ld EPS = 1e-12;

struct vec
{
	public:
		int x,y;
		void in(){scanf("%d%d", &x, &y), x+=MX;}
		ll operator / (vec o){return (ll)x*o.y-(ll)o.x*y;}
		vec& operator += (vec o){return x+=o.x, y+=o.y, *this;}
		vec& operator -= (vec o){return x-=o.x, y-=o.y, *this;}
		friend vec operator + (vec a, vec b){return a+=b;}
		friend vec operator - (vec a, vec b){return a-=b;}
} a[MN], b[MN];
int N, M, Q, q[MX*2];
ld f[MN];
struct qua : public std::array<ld, 3>
{
	public:
		qua(ld a=0, ld b=0, ld c=0) {at(0)=a, at(1)=b, at(2)=c;}
		ld operator () (ld t) {return at(0)+(at(1)+at(2)*t)*t;}
		qua& operator += (const qua& o) {return at(0)+=o[0], at(1)+=o[1], at(2)+=o[2], *this;}
		qua& operator -= (const qua& o) {return at(0)-=o[0], at(1)-=o[1], at(2)-=o[2], *this;}
		qua& operator *= (ld x) {return at(0)*=x, at(1)*=x, at(2)*=x, *this;}

		friend qua operator + (qua a, const qua& b) {return a+=b;}
		friend qua operator - (qua a, const qua& b) {return a-=b;}
		friend qua operator * (qua a, ld b) {return a*=b;}
} p[MX*2], cur;

bool equ(ld a, ld b){return std::abs(a-b)<EPS;}

void add(int x0, int x1, ld y0, ld y1, ld z0, ld z1)//y0,y1 starts on top, z0,z1 slide up. All pre-reverse. NOTE: Swap definition of x,y
{
	//printf("ADD(%d, %d, %.3lf, %.3lf, %.3lf, %.3lf);\n", x0, x1, y0, y1, z0, z1);
	{//upper bound: +y,-z
		qua v0((y0+y1)*(x1-x0)/2, x0-x1);
		qua v2((z0+z1)*(x0-x1)/2, x1-x0);//negate (aka flip) z0 and z1, because upper bound. This is equivalent to negating x0,x1
		p[0]+=v0;

		ld t0=(y0+z0)/2;//intersect
		ld t1=(y1+z1)/2;//2nd intersect

		if(equ(t0, t1))
			p[(int)std::ceil(t0)] += v2-v0;
		else
		{
			if(t0>t1) std::swap(t0, t1);
			// lower + formed triangle:
			// 0.5 * base * height
			// 0.5 * ((x1-x0)*(t1-t)/(t1-t0)) * (abs((y1+z1)-(y0+z0)))*(t1-t)/(t1-t0)
			// abs(y1+z1-y0-z0) = 2*(t1-t0)
			qua v1 = v2 + qua(t1*t1, -2*t1, 1)*((x1-x0)/(t1-t0));
			p[(int)std::ceil(t0)]+=v1-v0;
			p[(int)std::ceil(t1)]+=v2-v1;
		}
	}

	//Actually, lower bound can be entirely handled separately, without doing any sort of range overlap checking, but w/e its the same code

	{//lower bound: +z
		qua v0((z0+z1)*(x1-x0)/2, x0-x1);
		if(equ(z0, z1))
			p[0]-=v0, p[(int)std::ceil(z0)]+=v0;
		else
		{
			if(z0>z1) std::swap(z0,z1);
			qua v1 = qua(z1*z1, -2*z1, 1)*(0.5*(x1-x0)/(z1-z0));//((z1-t)/(z1-z0))^2 * 0.5 * (x1 - x0) * (z1 - z0)
			p[0] -= v0;
			p[(int)std::ceil(z0)] -= v1-v0;
			p[(int)std::ceil(z1)] += v1;
		}
	}

	{//lower bound: -y
		qua v2((y0+y1)*(x0-x1)/2, x1-x0);
		if(equ(y0, y1))
			p[(int)std::ceil(y0)]-=v2;
		else
		{
			if(y0>y1) std::swap(y0,y1);
			qua v1 = qua(y0*y0, -2*y0, 1)*(0.5*(x1-x0)/(y1-y0));//((t-y0)/(y1-y0))^2 * 0.5 * (x1 - x0) * (y1 - y0)
			p[(int)std::ceil(y0)]-=v1;
			p[(int)std::ceil(y1)]-=v2-v1;
		}
	}
}
void add(int i, int j, int t1)
{
	int t0 = std::max(a[i].y, b[j].y);
	add(t0, t1,
			a[i].x+(ld)(a[i+1].x-a[i].x)*(t0-a[i].y)/(a[i+1].y-a[i].y),
			a[i].x+(ld)(a[i+1].x-a[i].x)*(t1-a[i].y)/(a[i+1].y-a[i].y),
			b[j].x+(ld)(b[j+1].x-b[j].x)*(t0-b[j].y)/(b[j+1].y-b[j].y),
			b[j].x+(ld)(b[j+1].x-b[j].x)*(t1-b[j].y)/(b[j+1].y-b[j].y)
			);
}

int main()
{
	memset(q, -1, sizeof q);
	scanf("%d%d", &N, &Q);
	for(int i=0;i<N;++i)
		a[i].in();
	for(int i=0,x;i<Q;++i)
		scanf("%d", &x), q[x+MX]=i;
	{
		int m=MX, x;
		for(int i=0;i<N;++i)
			if(ckmin(m, a[i].y)) x=i;
		std::rotate(a, a+x, a+N);
		if((a[1]-a[0])/(a[N-1]-a[0])<0)
			std::reverse(a+1, a+N);
		m=-MX;
		for(int i=0;i<N;++i)
			if(ckmax(m, a[i].y)) x=i;
		memcpy(b, a+x, (N-x)*sizeof*a);
		b[N-x]=a[0];

		M=N-x+1;
		N=x+1;

		std::reverse(b, b+M);
	}
	//printf("A:\n"); for(int i=0;i<N;++i) printf("(%d, %d)\n", a[i].x-MX, a[i].y);
	//printf("B:\n"); for(int i=0;i<M;++i) printf("(%d, %d)\n", b[i].x-MX, b[i].y);
	for(int i=0, j=0, t;i+1<N;)//i+1==N and j+1==M should occur simultaneously
	{
		t = std::min(a[i+1].y, b[j+1].y);
		add(i, j, t);
		if(t==a[i+1].y) ++i;
		if(t==b[j+1].y) ++j;
		assert(!(i+1==N^j+1==M));
	}
	for(int i=0;i<MX*2;++i)
	{
		cur += p[i];
		if(~q[i])
			f[q[i]] = cur(i);
	}
	for(int i=0;i<Q;++i)
		printf("%.12lf\n", (double)f[i]);
	return 0;
}