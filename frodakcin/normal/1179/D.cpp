#include <cstdio>
#include <vector>
#include <set>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}
using ll = long long;
#define tl(X) static_cast<ll>(X)

const ll INF = 1e18;
const int MN = 5e5 + 100;

ll divf(ll n, ll d)
{
	if(d<0) n*=-1, d*=-1;
	if(n<0) return -((-n+d-1)/d);
	return n/d;
}
bool Q;
struct Line
{
public:
	ll m, b;
	mutable ll r;
	Line(ll m, ll b) : m(m), b(b) {}
	Line(ll r) : r(r) {}
	bool operator < (const Line& o) const
	{
		if(Q) return r < o.r;
		return m > o.m;
	}
	ll operator * (const Line& o) const
	{
		if(m == o.m) return o.m < m ? -INF : INF;
		return divf(o.b-b, m-o.m);
	}
	ll operator [] (const ll& x) const {return m * x + b;}
};
#define IT iterator
struct CHT : public multiset<Line>
{
public:
	bool upd(IT c, IT n)
	{
		if(n==end()) return c->r = INF, 0;
		if((c->r=*c**n)>=n->r) return 1;
		return 0;
	}
	void ins(const Line& l)
	{
		IT n = insert(l), c = n++, p = c;
		for(;upd(c, n);n=erase(n));
		if(p!=begin()&&upd(--p, c)) return upd(p, erase(c)), void();
		for(;(c=p)!=begin()&&upd(--p, c);upd(p, erase(c)));
	}
	ll operator [] (const ll& x) const
	{
		Q = 1;
		IT t = lower_bound({x});
		Q = 0;
		return (*t)[x];
	}
};
int N;
vector<int> a[MN];

int p[MN], s[MN];
ll dp[MN];
ll c2(ll s) {return s*(s-1)>>1;}
ll c22(ll s) {return s*(s-1);}
ll sqr(ll x) {return x*x;}
ll ans;
void dfs(int n)
{
	s[n] = 1;
	for(int x : a[n])
		if(x != p[n])
			p[x] = n, dfs(x), s[n] += s[x];
}
void dfs2(int n)
{
	CHT cht;
	dp[n] = INF;
	for(int x : a[n])
		if(x != p[n])
		{
			dfs2(x), mn(dp[n], dp[x]+c2(s[n]-s[x]));
			if(!cht.empty())
				mn(ans, (cht[s[x]]+sqr(s[x])>>1)+dp[x]);
			cht.ins({-(s[1]<<1)+(s[x]<<1)+1, (dp[x]<<1)+c22(s[1]-s[x])});
		}
	cht.clear();
	if(dp[n] == INF)
		dp[n] = 0LL;
	if(!p[n])
		mn(ans, dp[n]);
}

int main(void)
{
	scanf("%d", &N);
	for(int i = 0, u, v;i < N-1;i++)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	dfs(1);
	ans = INF;
	dfs2(1);
	printf("%lld\n", c22(N)-ans);
	return 0;
}