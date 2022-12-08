#include <cstdio>
#include <vector>
#include <set>

template<class T> bool ckmx(T * a, T b){return *a<b?*a=b,1:0;}
using ll = long long;
const int MN = 1.5e5 + 100;

int N;
std::vector<int> a[MN];
int b[MN];
ll ans = 0;

ll divf(ll n, ll d)
{
	if(d<0) n*=-1, d*=-1;
	return n<0?-((-n+d-1)/d):n/d;
}
#define IT iterator
const ll INF = 1e17;
bool Q;
struct Line
{
public:
	ll m, b;
	mutable ll r;
	bool operator < (Line o) const
	{
		if(Q) return r < o.r;
		else return m < o.m;
	}
	ll operator * (Line o) const
	{
		if(m == o.m) return b > o.b ? INF : -INF;
		return divf(o.b-b, m-o.m);
	}
	ll operator [] (ll x) const
	{
		return m*x+b;
	}
};
struct CHT : std::multiset<Line>
{
public:
	bool upd(IT c, IT n)
	{
		if(n == end()) return c->r = INF, 0;
		return (c->r=*c**n)>=n->r;
	}
	void ins(Line l)
	{
		IT n = insert(l), c = n++, p;
		for(;upd(c, n);) n = erase(n);
		if((p=c) != begin() && upd(--p, c)) upd(p, erase(c));
		for(;(c=p) != begin() && upd(--p, c);) upd(p, erase(c));
	}
	ll operator [] (ll x)
	{
		if(empty()) return 0;
		Q = 1;
		Line l = *lower_bound({-1, -1, x});
		Q = 0;
		return l[x];
	}
};
CHT cht;

bool r[MN];
int s[MN];
int dfs(int n, int p = 0)
{
	s[n] = 1;
	for(int x : a[n])
		if(x != p && !r[x])
			s[n] += dfs(x, n);
	return s[n];
}
int get_centroid(int n, int ms, int p = 0)
{
	for(int x : a[n])
		if(x != p && !r[x])
			if(s[x]*2 > ms)
				return get_centroid(x, ms, n);
	return n;
}
ll sum, pre;
int d = 1;
void add(int n, int p)
{
	++d, sum += (ll)b[n]*d, pre += b[n];
	if(a[n].size() == 1)
		cht.ins({pre, sum});
	//printf("INSERT %lldx+%lld\n", pre, sum);
	for(int x : a[n])
		if(x != p && !r[x])
			add(x, n);
	sum -= (ll)b[n]*d, pre -= b[n], --d;
}
void query(int n, int p)
{
	++d, sum += pre += b[n];
	//printf("QUERIED max(b + %lld(m))+%lld -> %lld\n", d, sum, cht[d]+sum);
	if(a[n].size() == 1)
		ckmx(&ans, cht[d] + sum);
	for(int x : a[n])
		if(x != p && !r[x])
			query(x, n);
	sum -= pre, pre -= b[n], --d;
}
void centroid(int n = 1)
{
	int C = get_centroid(n, dfs(n));
	//printf("%d\n", C);

	//printf("CHECKPOINT 1\n");
	for(int i = 0;i < a[C].size();++i)
		if(!r[a[C][i]])
		{
			sum = pre = b[C], d = 1;
			query(a[C][i], C);
			sum = pre = 0, d = 0;
			add(a[C][i], C);
		}
	ckmx(&ans, cht[1]+b[C]);
	cht.clear();

	//printf("CHECKPOINT 2\n");
	for(int i = a[C].size()-1;i >= 0;--i)
		if(!r[a[C][i]])
		{
			sum = pre = b[C], d = 1;
			query(a[C][i], C);
			sum = pre = 0, d = 0;
			add(a[C][i], C);
		}
	ckmx(&ans, cht[1]+b[C]);
	cht.clear();

	//printf("CHECKPOINT 3\n");
	r[C] = 1;
	for(int x : a[C])
		if(!r[x])
			centroid(x);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, u, v;i < N-1;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	for(int i = 1;i <= N;++i)
		scanf("%d", b+i);
	centroid();
	printf("%lld\n", ans);
	return 0;
}