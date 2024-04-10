#include <iostream>
#include <cstdio>

#include <vector>
#include <array>
#include <queue>

using namespace std;

template<class T> bool ckmn(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
const int MN = 3e5 + 1000;
const int MQ = 6e5 + 1000;
using ll = long long;

using l2 = array<ll, 2>;
struct E
{
	int u;
	l2 w;
	E(int a, l2 b): u(a), w(b) {}
};
using l4 = array<ll, 4>;
struct C
{
	int p;
	l4 d;//0 = even, 1 = odd, 0 = this, 1 = par
	C(int x): p(x) {}
	C(int x, l4 d): p(x), d(d) {}
};
using vc = vector<C>;
using ve = vector<E>;
#define pb push_back
#define bk back()
#define sz size()
int N, Q;
ll w[MN];
ve a[MN];
vc c[MN];
bool r[MN];
int s[MN];
int dfs(int n, int p = -1)
{
	s[n] = 1;
	for(E x : a[n])
		if(x.u!=p&&!r[x.u])
			s[n] += dfs(x.u, n);
	return s[n];
}
int get_centroid(int n, int m, int p = -1)
{
	for(E x : a[n])
		if(x.u!=p&&!r[x.u]&&s[x.u]<<1 > m)
			return get_centroid(x.u, m, n);
	return n;
}
void dfs2(int n, int p, int t)
{
	l4 d = c[n].bk.d;
	for(E x : a[n])
	{
		if(r[x.u]||x.u==p)
			continue;
		l4 y;
		for(int i = 0;i < 2;i++)
		{
			y[i<<1] = min(d[i<<1] + x.w[0], d[i<<1|1] + x.w[1] + w[x.u]);
			y[i<<1|1] = min(d[i<<1|1] + x.w[1], d[i<<1] + x.w[0] + w[x.u]);
		}
		c[x.u].pb(C(t, y));
		dfs2(x.u, n, t);
	}
}
void work(int n)
{
	c[n].pb(C(n, {0LL, w[n], w[n], 0LL}));
	dfs2(n, -1, n);
}
void cdc(int n)
{
	int x = get_centroid(n, dfs(n));
	work(x);
	r[x] = 1;
	for(E y : a[x])
		if(!r[y.u])
			cdc(y.u);
}
const ll INF = 1e18;
void AQ(void)
{
	int u, v, i, j;
	scanf("%d%d", &u, &v), u++, v++;
	for(i=0, j=min(c[u>>1].sz, c[v>>1].sz);i<j;i++)
		if(c[u>>1][i].p!=c[v>>1][i].p)
			break;
	i--;
	ll f = INF;
	for(int k : {0,1})
		ckmn(f, c[u>>1][i].d[k<<1|u&1] + c[v>>1][i].d[k<<1|v&1]);
	printf("%lld\n", f);
}
struct S
{
	int n;
	ll w;
	S(int n = 0, ll w = -1LL): n(n), w(w) {}
	bool operator < (const S& o) const {return w > o.w || (!(o.w > w)&&n > o.n);}//flipped for pq
};
using vs = vector<S>;
using qs = priority_queue<S>;
qs q;
bool v[MN];
void pcpw(void)
{
	for(int i = 1;i <= N;i++)
		q.push({i, w[i]});
	for(;!q.empty();)
	{
		S s = q.top(); q.pop();
		if(v[s.n])
			continue;
		v[s.n] = 1;
		for(E x : a[s.n])
			if(!v[x.u]&&ckmn(w[x.u], w[s.n] + x.w[0] + x.w[1]))
				q.push({x.u, w[x.u]});
	}
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 1;i <= N;i++)
		scanf("%lld", w + i);
	for(int i = 1;i < N;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		l2 x;
		scanf("%lld%lld", &x[0], &x[1]);
		a[u].pb({v, x});
		a[v].pb({u, x});
	}
	pcpw();
	cdc(1);
	scanf("%d", &Q);
	for(;Q--;)
		AQ();
	return 0;
}