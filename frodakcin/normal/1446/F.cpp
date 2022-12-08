#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using ll = long long;
using ld = long double;

const ld PI = 4*atanl(1);
const ld EPS = 1e-12;
const int MN = 1e5+10;

struct vec
{
	public:
		int x, y;
		void in() {scanf("%d%d", &x, &y);}

		ld mag() const {return hypotl(x,y);}
		ld ang() const {return atan2l(y,x);}
};

struct Evt
{
	public:
		ld t;
		int v;
		Evt(ld _t=0, int _v=0): t(_t), v(_v) {}
		bool operator < (const Evt& o) const {return t < o.t;}
};

struct BIT
{
	public:
		int a[MN*2], L;
		void reset(int _L) {memset(a, 0, L*sizeof*a); L=_L;}
		void upd(int n, int v)
		{
			for(++n;n<=L;n+=-n&n)
				a[n-1]+=v;
		}
		int qry(int n)
		{
			int f=0;
			for(;n;n-=-n&n)
				f+=a[n-1];
			return f;
		}
		int qry(int l, int r) {return qry(r)-qry(l);}
};

int N, p[MN];
ll K;
vec a[MN];
std::vector<Evt> evt;
BIT bit;

ll count(ld d) // USACO Line of Sight, basically... LOL JK im stupid... hope this is right
{
	ll f = (ll)N*(N-1)/2; // subtract those that are farther out
	int ctr=0;
	for(int i=0;i<N;++i)
		if(d < a[i].mag()) // I'd do a[i].mag()+EPS, but I don't want to accidentally make acosl not exist
		{
			ld m=a[i].ang(); // [-pi, pi]
			ld dif = acosl(d/a[i].mag()); // [0, pi]
			//[m-dif, m+dif]
			ld s=m-dif, e=m+dif; // s: [-2pi, pi]
			if(s+EPS<0) s += 2*PI, e += 2*PI;
			if(2*PI<e+EPS) e -= 2*PI;
			if(e<s) std::swap(s,e);
			evt.push_back({s, ctr});
			evt.push_back({e, ctr});
			ctr++;
		}

	std::sort(evt.begin(), evt.end());
	memset(p, -1, ctr*sizeof*p);
	bit.reset(ctr*2);
	for(int i=0;i<evt.size();++i)
	{
		int v=evt[i].v;
		if(~p[v])
			bit.upd(p[v], -1), f -= bit.qry(p[v]+1, i);
		else
			p[v]=i, bit.upd(i, 1);
	}
	evt.clear();
	return f;
}

int main()
{
	scanf("%d%lld", &N, &K);
	for(int i=0;i<N;++i) a[i].in();

	ld l=-logl(1e8), r=logl(2e4), m;
	for(int i=0;i<100;++i)
	{
		ld m=(r+l)/2;
		//printf("%.3lf: %d\n", (double)exp(m), count(exp(m)));
		if(count(exp(m))<K)
			l=m;
		else
			r=m;
	}

	printf("%.9lf\n", (double)exp(r));
	return 0;
}