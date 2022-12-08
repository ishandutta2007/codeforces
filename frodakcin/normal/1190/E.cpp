#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}

using ld = long double;
#define tld(X) static_cast<ld>(X)

const int MN = 1e5 + 100;
const ld EPS = 1e-12;
const ld PI = acosl(-1);
inline bool equ(ld a, ld b) {return fabs(a-b)<EPS;}
inline bool leq(ld a, ld b) {return (a<b||equ(a,b));}
inline bool geq(ld a, ld b) {return (a>b||equ(a,b));}

int N, M;
int x[MN], y[MN];
ld L[MN], D[MN];

struct seg
{
	ld a, b;
	bool operator < (const seg& o) const {return equ(a,o.a) ? b > o.b : a < o.a;}
	seg jump(void) const {return {a+2*PI, b+2*PI};}
};
vector<seg> g, r;
int nx[MN*2];
int v[MN];
bool test(int K)
{
	//for(auto x : g) printf("%.9Lg %.9Lf\n", x.a, x.b); printf("\n\n");
	nx[K*2] = K*2;
	for(int i = 0, j = 0;i < K*2;i++)
	{
		for(;j < g.size() && leq(g[j].a, g[i].b);j++);
		nx[i] = j;
	}
	for(int i = 0;i < K;i++)
		v[i] = 0;
	int s = 0;
	for(int i = 1;;i++, s=nx[s])
	{
		assert(i < K*10);
		if(s>=K)s-=K;
		if(v[s]) break;
		v[s] = i;
	}
	int t = s;
	for(int i = 0;i < M;i++)
		t = nx[t];
	return t-s>=K;
}

int main(void)
{
	ld l = 0.0, h = 1e10;
	scanf("%d%d", &N, &M);
	for(int i = 0;i < N;i++)
		scanf("%d%d", x+i,y+i), mn(h, L[i]=hypotl(x[i],y[i])), D[i] = atan2l(y[i],x[i]);
	if(h < EPS)
		return printf("0\n"), 0;
	for(int i = 0;i < 100;i++)
	{
		ld m = (l+h)/2;
		ld b = 2*PI;
		for(int j = 0;j < N;j++)
		{
			ld d = acosl(m/L[j]);
			if(geq(D[j]-d, 0.0)) r.push_back({D[j]-d, D[j]+d}), mn(b, D[j]+d);
			else r.push_back({D[j]-d+2*PI, D[j]+d+2*PI});
		}
		b += 2*PI;
		sort(r.begin(), r.end());
		for(seg& x : r)
		{
			for(;!g.empty() && leq(x.b, g.back().b);) g.pop_back();
			if(!geq(x.b, b)) g.push_back(x);
		}
		r.clear();
		int K = g.size();
		for(int i = 0, j = g.size();i < j;i++)
			g.push_back(g[i].jump());
		if(test(K))
			l = m;
		else
			h = m;
		g.clear();
	}
	printf("%.9lf\n", (double)l);
	return 0;
}