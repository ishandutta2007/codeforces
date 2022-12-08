#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <functional>
#include <set>

#include <cassert>

using namespace std;

using ll = long long;
using comp = function<bool(const int&, const int&)>;
using compll = function<bool(const ll&, const ll&)>;
using vi = vector<int>;
using vl = vector<ll>;
#define sz size()
#define pb push_back
#define ALL(X) X.begin(),X.end()
using si = multiset<ll>;
#define IT iterator
using sit = si::IT;

const int MN = 2.5e5 + 1000;
const ll INF = 1e13;

struct E
{
	int n;
	int w;
};
using ve = vector<E>;

int N;
ve a[MN];
ll d[MN][2];
int deg[MN];
int p[MN];
ll v[MN];
int u[MN];

const comp cmp = [](const int& x, const int& y){return deg[x] > deg[y] || (!(deg[y] > deg[x]) && x < y);};//> instead of < to reverse
const function<bool(const E&, const E&)> cmp_e = [](const E& x, const E& y){return cmp(x.n, y.n);};

void dfs(int n = 1)
{
	for(int i = 0;i < a[n].sz;i++)
		if(a[n][i].n == p[n])
			u[n] = a[n][i].w, a[n].erase(a[n].begin() + i--);
		else
			p[a[n][i].n] = n, dfs(a[n][i].n);
	sort(ALL(a[n]), cmp_e);
}
vi alive;
bool isalive[MN];
bool vis[MN];
ll f;
int Q;
struct G
{
	si a, b;
	ll w;
	void adda(ll x)
	{
		a.insert(x);
		w += x;
	}
	void dela(ll x)
	{
		a.erase(a.find(x));
		w -= x;
	}
	void fixO(void)
	{
		while(a.sz > Q)
			b.insert(*a.rbegin()), w -= *a.rbegin(), a.erase(prev(a.end()));
	}
	void fixU(void)
	{
		while(a.sz < Q&&!b.empty()&&*b.begin() < 0)
			a.insert(*b.begin()), w += *b.begin(), b.erase(b.begin());
	}
	void fix(void)
	{
		fixU();
		fixO();
	}
	void ins(ll v)
	{
		if(v < 0)
		{
			if(a.empty() || v < *a.rbegin())
				adda(v), fixO();
			else
				b.insert(v);
		}
		else
			b.insert(v);
	}
	void del(ll v)
	{
		if(b.empty()||v < *b.begin())
			dela(v), fixU();
		else
			b.erase(b.find(v));
	}
};
G chw[MN];
void rem(int n)
{
	if(p[n])
	{
		v[p[n]] += u[n];
		chw[p[n]].ins(-u[n]);
		//assert(a[p[n]].back().n == n);
		a[p[n]].pop_back();
	}
}
void dfsf(int n)
{
	vis[n] = 1;
	ll z = v[n];
	for(E x : a[n])
	{
		if(!vis[x.n])
			dfsf(x.n);
		z += d[x.n][0] + x.w;
		chw[n].ins(d[x.n][1] - (d[x.n][0] + x.w));
	}
	chw[n].fix();
	d[n][0] = z + chw[n].w;
	d[n][1] = z + chw[n].w - (chw[n].a.sz == Q ? *chw[n].a.rbegin() : 0LL);
	//printf("%d %lld %lld %lld\n", n, z, d[n][0], d[n][1]);
	for(E x : a[n])
		chw[n].del(d[x.n][1] - (d[x.n][0] + x.w));
	if(!isalive[p[n]])
		f += min(d[n][1], d[n][0] + u[n]);		//this should work for root as well
}
void resolve()
{
	for(int x : alive)
		vis[x] = 0;
	f = 0LL;
	for(int x : alive)
		if(!vis[x])
			dfsf(x);
}
ll totw;
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, u, v, w;i < N-1;i++)
		scanf("%d%d%d", &u, &v, &w), a[u].pb({v, w}), a[v].pb({u, w}), totw += w;
	for(int i = 1;i <= N;i++)
		deg[i] = a[i].sz, alive.pb(i), isalive[i] = 1;
	dfs();
	sort(ALL(alive), cmp);
	printf("%lld\n", totw);
	for(Q = 1;Q < N;Q++)
	{
		for(;!alive.empty()&&deg[alive.back()] == Q;alive.pop_back())
			rem(alive.back()), isalive[alive.back()] = 0;
		resolve();
		printf("%lld\n", f);
	}
	return 0;
}