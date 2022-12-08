#include <cstdio>
#include <cmath>
#include <array>
#include <vector>

using ld = long double;
using ul = std::size_t;
template<typename T, ul C> using ar = std::array<T, C>;

const int MN = 55;
const ld INF = 1e10;
const ld EPS = 1e-9;

template<ul C>
ar<ld, C>& operator *= (ar<ld, C>& a, const ld& v)
{
	for(ul i=0;i<C;++i)
		a[i]*=v;
	return a;
}
template<ul C> ar<ld, C> operator * (ar<ld, C> a, const ld& v) {return a*=v;}

template<ul C>
ar<ld, C>& operator += (ar<ld, C>& a, const ar<ld, C>& b)
{
	for(ul i=0;i<C;++i)
		a[i]+=b[i];
	return a;
}
template<ul C> ar<ld, C> operator + (ar<ld, C> a, const ar<ld, C>& b) {return a+=b;}

inline bool equ(const ld& a, const ld& b) {return std::abs(a-b)<EPS;}
struct vec
{
	public:
		ld x,y;
		vec(ld _x=0, ld _y=0): x(_x), y(_y) {}
		vec& operator += (const vec& o) {return x+=o.x, y+=o.y, *this;}
		vec& operator -= (const vec& o) {return x-=o.x, y-=o.y, *this;}
		vec& operator *= (const ld& o) {return x*=o, y*=o, *this;}

		friend vec operator + (vec a, const vec& b) {return a+=b;}
		friend vec operator - (vec a, const vec& b) {return a-=b;}
		friend vec operator * (vec a, const ld& b) {return a*=b;}

		ld mag() const {return hypot(x,y);}
};

struct range
{
	public:
		ld l,r;
};
using ranges = std::vector<range>;

ranges unite(const ranges& a, const ranges& b)//union
{
	ranges f(0);
	bool rdy=0;
	ld l=-INF-1, r=-INF-1;
	auto add=[&]()
	{
		if(rdy) f.push_back({l,r});
		else rdy=1;
	};
	range t;
	for(int i=0,j=0;i<a.size() || j<b.size();)
	{
		if(j<b.size() && (i==a.size() || b[j].l < a[i].l)) t=b[j++];
		else t=a[i++];
		if(r+EPS<t.l)
			add(), l=t.l;
		r=std::max(r, t.r);
	}
	add();
	return f;
}

ranges isect(const ranges& a, const ranges& b)
{
	ranges f;
	for(int i=0,j=0;i<a.size() && j<b.size();)
	{
		ld l=std::max(a[i].l, b[j].l);
		ld r=std::min(a[i].r, b[j].r);
		if(l+EPS<r)
			f.push_back({l,r});
		if(a[i].r < b[j].r) ++i;
		else ++j;
	}
	return f;
}

int N;
vec p[MN];
ld pf[MN];

//ar<ld, 3>: {1, s, t}
//ar<ld, 6>: {1, s, t, s^2, t^2, st}

ar<ld, 6> sqr(const ar<ld, 3>& a) // (1,s,t)**2
{
	return {a[0]*a[0], 2*a[0]*a[1], 2*a[0]*a[2], a[1]*a[1], a[2]*a[2], 2*a[1]*a[2]};
}

ranges neg(const ar<ld, 3>& a) // ranges where (a0+a1x+a2x^2) is negative
{
	if(equ(a[2], 0))
	{
		if(equ(a[1], 0))
			return a[0]<0?ranges{{-INF,INF}}:ranges();
		else
			return a[1]<0?ranges{{-a[0]/a[1],INF}}:ranges{{-INF,-a[0]/a[1]}};
	}
	else if(a[2]<0)
	{
		ld d=a[1]*a[1]-4*a[0]*a[2];
		if(d>EPS)
		{
			d = sqrt(d)/(2*-a[2]);//ghetto fix for negative 2nd degree coefficient
			ld c = -a[1]/(2*a[2]);
			return ranges{{-INF, c-d}, {c+d, INF}};
		}
		return ranges{{-INF,INF}};
	}
	else//a[2]>0
	{
		ld d=a[1]*a[1]-4*a[0]*a[2];
		if(d>EPS)
		{
			d = sqrt(d)/(2*a[2]);
			ld c = -a[1]/(2*a[2]);
			return ranges{{c-d, c+d}};
		}
		return ranges();
	}
}

ranges eval(const ar<ld, 6>& a) // determine values of $s$ such that there exists $t$ that makes this negative. minimization problem
{
	//printf("%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", a[0], a[1], a[2], a[3], a[4], a[5]);
	//a[4] = y^2 term
	//a[4] = 0: Linear in y -- y = 0 or y = 1
	//a[4] > 0: Most annoying case >:( -- must check for absolute minimum (bottom of parabola)
	//a[4] < 0: try both endpoints -- y = 0 or y = 1. Reasonably simple case

	ranges f;
	//y = 0 case
	f = neg({a[0], a[1], a[3]});
	//y = 1 case
	f = unite(f, neg({a[0]+a[2]+a[4], a[1]+a[5], a[3]}));
	//special minimization case if a[4] > 0
	if(a[4]>EPS)
	{
		if(equ(a[5], 0))
		{
			ld yv=a[2]/(-2*a[4]);
			if(0 < yv && yv < 1)
				f=unite(f, neg({a[0]+a[2]*yv+a[4]*yv*yv, a[1], a[3]}));//a[5] = 0; ignore
		}
		else
		{
			//work this out on paper by hand... solve quadratic to minimize y given fixed x
			range xr = {(-2*a[4]-a[2])/a[5], -a[2]/a[5]};//assume a[5](xy) > 0
			if(a[5]<0) xr = {xr.r, xr.l};
			//printf("!! %.3Lf %.3Lf\n", xr.l, xr.r);
			//more quadratic solving by hand...
			f = unite(f, isect(ranges{xr}, neg({a[0]-a[2]*a[2]/(4*a[4]), a[1]-2*a[2]*a[5]/(4*a[4]), a[3]-a[5]*a[5]/(4*a[4])})));
		}
	}
	return isect(f, ranges{{0,1}});
}

bool ok(const ld& v)
{
	ranges bot, top;
	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
		{
			ld mi = (p[i+1]-p[i]).mag();
			ld mj = (p[j+1]-p[j]).mag();
			ar<ld, 6> L = sqr({pf[j]-pf[i], -mi, mj});
			ar<ld, 6> Dx= sqr({p[j].x-p[i].x, -p[i+1].x+p[i].x, p[j+1].x-p[j].x});
			ar<ld, 6> Dy= sqr({p[j].y-p[i].y, -p[i+1].y+p[i].y, p[j+1].y-p[j].y});

			L *= -1;
			Dx*= v*v;
			Dy*= v*v;

			ar<ld, 6> fin = L+Dx+Dy;
			//bot:
			ranges bot_ = eval(fin);
			std::swap(fin[1], fin[2]);
			std::swap(fin[3], fin[4]);
			ranges top_ = eval(fin);

			for(range& x:bot_) x.l=pf[i]+mi*x.l, x.r=pf[i]+mi*x.r;
			for(range& x:top_) x.l=pf[j]+mj*x.l, x.r=pf[j]+mj*x.r;

			bot = unite(bot, bot_);
			top = unite(top, top_);
		}

	/*
	printf("%.4Lf\n", v);
	for(auto x:bot)
		printf("%.4Lf %.4Lf\n", x.l, x.r);
	printf("\n");
	for(auto x:top)
		printf("%.4Lf %.4Lf\n", x.l, x.r);
		*/

	return isect(bot, top).empty();
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<=N;++i)
	{
		int u,v;
		scanf("%d%d", &u, &v);
		p[i]={(ld)u,(ld)v};
	}
	for(int i=0;i<N;++i)
		pf[i+1]=pf[i]+(p[i+1]-p[i]).mag();
	ld l=1, r=5000;
	for(int i=0;i<100;++i)
	{
		ld m=l+(r-l)/2;
		if(ok(m))
			r=m;
		else
			l=m;
	}
	printf("%.9lf\n", (double)r);
	return 0;
}