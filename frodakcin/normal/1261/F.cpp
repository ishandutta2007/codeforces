#include <cstdio>
#include <algorithm>
#include <vector>
//#define NDEBUG
#include <cassert>

const int MN = 105;
const int MOD = 998244353;
const int MB = 62;
const int M2 = MOD+1>>1;
using ll = long long;
ll F;

bool is_submask(ll x, ll y)
{
	return (x&y)==x;
}
struct S
{
public:
	ll l, r;
	void in(void){scanf("%lld%lld", &l, &r), ++r;}
	bool operator < (const S& o) const {return l < o.l || !(o.l < l) && r > o.r;}
};
struct R
{
public:
	ll v;
	int b;
	bool operator < (R o) const {return v < o.v || !(o.v < v) && b > o.b;}
	bool operator == (R o) const {return v == o.v && b == o.b;}
	bool rem(R o) const
	{
		if(!~b) return false;
		return is_submask(o.v&~((1LL<<b)-1), v);
	}
	/*
	bool comb(R o) const
	{
		return b == o.b && (v|1LL<<b) == (o.v|1LL<<b);
	}
	void inc(void)
	{
		v &= ~(1LL<<b);
		++b;
	}
	*/
};

void compress(std::vector<S> * a, std::vector<S> * b)
{
	std::sort(a->begin(), a->end());
	b->clear();
	S c = a->front();
	for(S x : *a)
		if(c.r < x.l)
			b->push_back(c), c = x;
		else if(x.r > c.r)
			c.r = x.r;
	b->push_back(c);
	a->clear();
}
void transferSR(std::vector<S> * a, std::vector<R> * b, std::vector<ll> * c)
{
	ll l0, l, r;
	int i;
	bool r0;
	for(S x : *a)
	{
		for(i=r0=0, l0=l=x.l, r=x.r;l < r;l0>>= 1, l>>=1, r>>=1, ++i)
		{
			if(l0 < l) c[i].push_back(l0<<i);
			if(r0) c[i].push_back(r<<i);
			if(l&1) c[i].push_back(l<<i), b->push_back({l<<i, i}), ++l;
			if(r&1) --r, c[i].push_back(r<<i), b->push_back({r<<i, i}), r0=1;
		}
		for(;i < MB;l0>>=1, r>>=1, ++i)
		{
			c[i].push_back(l0<<i);
			if(r0 && l0<r) c[i].push_back(r<<i);
		}
	}
	a->clear();
}

int N[2];
std::vector<S> a[2];
std::vector<S> b[2];
std::vector<R> c[2];
std::vector<ll> d[2][MB];
std::vector<R> e;

int main(void)
{
	for(int i = 0;i < 2;++i)
	{
		a[i].reserve(MN);
		b[i].reserve(MN);
		c[i].reserve(MN*MB*2);
		for(int j = 0;j < MB;++j)
			d[i][j].reserve(MN*4);
	}
	e.reserve(MN*4*MN*MB*2);

	for(int i : {0,1})
	{
		scanf("%d", N+i);
		a[i].assign(N[i], {-1,-1});
		for(int j = 0;j < N[i];++j) a[i][j].in();
		compress(a+i, b+i);
		transferSR(b+i, c+i, d[i]);
		for(int j = 0;j < MB;++j)
			d[i][j].resize(std::distance(d[i][j].begin(), std::unique(d[i][j].begin(), d[i][j].end())));
	}
	for(int i : {0,1})
		for(R x : c[i])
			for(ll y : d[!i][x.b])
				e.push_back({x.v^y, x.b});
	std::sort(e.begin(), e.end());
	R t = {-1LL, -1};
	ll q;
	for(R x : e)
		if(!t.rem(x))
			t=x, q=(1LL<<x.b)%MOD, F = (F + x.v%MOD*q + q*(q-1)/2)%MOD;
	printf("%d\n", static_cast<int>(F));
	return 0;
}