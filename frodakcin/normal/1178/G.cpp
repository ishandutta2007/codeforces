#include <cstdio>
#include <cassert>

#include <queue>
#include <vector>
#include <algorithm>

using std::sort;

template<class T> bool mx(T& a, const T& b) {return a<b?a=b,1:0;}

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int RS = 200;
const int RC = 1010;

const ll INF = 4e18;

ll divf(ll n, ll d)
{
	if(d<0) d*=-1,n*=-1;
	return n<0?-((-n+d-1)/d):n/d;
}
struct Line
{
public:
	ll m, b;
	mutable ll r;
	ll operator [] (ll x) const {return m*x+b;}
	ll operator * (const Line* o) const
	{
		if(m==o->m) return o->b > b ? INF : -INF;
		return divf(b-o->b,o->m-m);
	}
};
struct CHT : std::deque<Line> //Insert smallest slope first, pop smallest slope out
{
public:
	void ins(Line l)
	{
		if(empty()) return l.r = INF, push_front(l);
		if(front().m == l.m){if(l.b > front().b) pop_front(); else return;}
		for(;!empty() && (l.r=l*&front()) >= front().r;pop_front());
		if(empty()) l.r = INF;
		push_front(l);
	}
	ll operator [] (ll x)
	{
		for(;x > front().r;) pop_front();
		return front()[x];
	}
};
struct Range
{
private:
	int S, x; ll f;
	int *a, *b, *o;
	CHT v[2];
	void gen_cht(void)
	{
		v[0].clear(), v[1].clear();
		for(int i = S-1;i >= 0;i--)
			v[0].ins({b[o[i]], tl(a[o[i]])*b[o[i]]});
		for(int i = 0;i < S;i++)
			v[1].ins({-b[o[i]], tl(-a[o[i]])*b[o[i]]});
		f = std::max(v[0][0], v[1][0]), x=0;
	}
public:
	void init(int S, int *a, int *b, int *o)
	{
		this->S = S, this->a = a, this->b = b, this->o = o;
		for(int i = 0;i < S;i++) o[i] = i;
		sort(o,o+S,[&](int x, int y){return b[x]<b[y];});
		gen_cht();
	}
	void updall(int d)//a value increases by d
	{
		x += d;
		f = std::max(v[0][x], v[1][x]);
	}
	void updrange(int l, int r, int d)
	{
		//if(l == 0 && r == S) return updall(d);
		for(int i = 0;i < S;i++)
			a[i] += x;
		for(int i = l;i < r;i++)
			a[i] += d;
		gen_cht();
	}
	ll get(void) {return f;}
	ll getrange(int l, int r)
	{
		//if(l == 0 && r == S) return get();
		ll z = 0;
		for(int i = l;i < r;i++)
			mx(z, std::max(tl(a[i]+x)*b[i], tl(-a[i]-x)*b[i]));
		return z;
	}
};
Range r[RC];

const int MN = RC*RS;
static_assert(MN > 2e5, "set bounds wrong");
int a[MN], b[MN], N, Q, o[MN][2], t, s[MN], w[MN];
std::vector<int> c[MN];
void dfs(int n = 1)
{
	o[n][0] = t++;
	for(int x : c[n])
		a[x]+=a[n], b[x]+=b[n], dfs(x);
	if(b[n]<0) b[n]*=-1;
	o[n][1] = t;
}
void sub(int *x)
{
	for(int i = 1;i <= N;i++)
		w[i] = x[i];
	for(int i = 1;i <= N;i++)
		x[o[i][0]] = w[i];
}

int main(void)
{
	scanf("%d%d", &N, &Q);
	for(int i = 2, j;i <= N;i++)
		scanf("%d", &j), c[j].push_back(i);
	for(int i = 1;i <= N;i++)
		scanf("%d", a+i);
	for(int i = 1;i <= N;i++)
		scanf("%d", b+i);
	dfs();
	sub(a), sub(b);
	for(int i = 0;i*RS < N;i++)
		if(i*RS+RS <= N)
			r[i].init(RS, a+i*RS, b+i*RS, s+i*RS);
		else
			r[i].init(N-i*RS, a+i*RS, b+i*RS, s+i*RS);
	for(int i = 0, v, x, a, b;i < Q;i++)
	{
		scanf("%d%d", &t, &v);
		a = o[v][0], b=o[v][1];
		if(t==1)
		{
			scanf("%d", &x);
			if(a/RS == (b-1)/RS)
				r[a/RS].updrange(a%RS, (b-1)%RS+1, x);
			else
			{
				r[a/RS].updrange(a%RS, RS, x);
				r[(b-1)/RS].updrange(0, (b-1)%RS+1, x);
				for(int i = a/RS+1;i < (b-1)/RS;i++)
					r[i].updall(x);
			}
		}
		else
		{
			ll f = 0LL;
			if(a/RS == (b-1)/RS)
				printf("%lld\n", r[a/RS].getrange(a%RS, (b-1)%RS+1));
			else
			{
				mx(f, r[a/RS].getrange(a%RS, RS));
				mx(f, r[(b-1)/RS].getrange(0, (b-1)%RS+1));
				for(int i = a/RS+1;i < (b-1)/RS;i++)
					mx(f, r[i].get());
				printf("%lld\n", f);
			}
		}
	}
	return 0;
}