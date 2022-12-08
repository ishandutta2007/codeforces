#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using ll = long long;

const int MN = 2e3+10, MM = 2e3+10;
const int MOD = 1e9+7;
const ll INF = 1e16;

ll divf(ll n, ll d)
{
	if(d<0) d*=-1, n*=-1;
	if(n<0) return -((-n+d-1)/d);
	return n/d;
}
struct Line//max hull
{
public:
	ll m, b;
	mutable ll r;
	bool operator < (Line o) const {return m < o.m;}
	ll operator * (Line o) const //Last position where you are better than the next
	{
		if(m == o.m) return o.b > b ? -INF : INF;
		return divf(o.b-b, m-o.m);
	}
	ll operator [] (ll x) const 
	{
		return m*x+b;
	}
};
#define IT iterator
struct CHT : public std::multiset<Line>
{
public:
	bool upd(IT c, IT n)
	{
		if(n == end()) return c->r=INF, 0;
		return (c->r=*c**n) >= n->r;
	}
	void ins(Line l)
	{
		//printf("INSERT: %3lldx + %3lld\n", l.m, l.b);
		IT n = insert(l), c=n++, p;
		for(;upd(c, n);) n=erase(n);
		if((p=c)!=begin() && upd(--p, c)) return (void)upd(p, erase(c));
		for(;(c=p)!=begin() && upd(--p, c);) upd(p, erase(c));
	}
	ll get(ll x)// we know that x is increasing
	{
		assert(!empty());
		for(;x > begin()->r;) erase(begin()), assert(!empty());
		return (*begin())[x];
	}
};
CHT cht;
struct edge
{
public:
	int n, w;
};
ll sum(ll v)
{
	return v*(v+1)/2%MOD;
}

std::vector<edge> a[MN];
int max[MN], p, N, M, Q;
ll d[MN][MM], best[MN][MM], ans;

int main(void)
{
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=0,u,v,w;i<M;++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		max[u]=std::max(max[u], w);
		max[v]=std::max(max[v], w);
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	memset(d, -1, sizeof d);
	memset(best, -1, sizeof best);
	d[1][0] = 0;
	for(int i=0;i<=M;++i)//at most M-1 edges, technically; This doesn't insert i == m which is fine bcz other node can get it
		for(int j=1;j<=N;++j)
			if(~d[j][i])
			{
				best[j][i] = (ll)d[j][i]-(ll)max[j]*i;//best base value using >= i edges
				for(auto x:a[j])
					if(!~d[x.n][i+1] || d[j][i]+x.w > d[x.n][i+1])
						d[x.n][i+1] = d[j][i]+x.w;
			}
	cht.ins({max[1], best[1][0]});
	for(int i=1;i<=M;++i)
	{
		for(int j=1;j<=N;++j) //each node can be inserted to the CHT at most 2 times
			if(~best[j][i] && (!~best[j][i-1] || best[j][i] > best[j][i-1]))
				cht.ins({max[j], best[j][i]});
			else if(~best[j][i-1])
				best[j][i] = best[j][i-1];
		//printf("%d: %lld\n", i, cht.get(i));
		ans = (ans+cht.get(i))%MOD;
		if(i == Q) break;
	}
	p=M;
	//find ans for (p, Q]
	for(auto it=cht.begin();p < Q;++it)
	{
		assert(it != cht.end());
		int n = (int)std::min(it->r, (ll)Q);
		if(n<=p) continue;
		ans = (ans+(MOD-(-it->b)%MOD)*(n-p)+(sum(n)-sum(p)+MOD)*it->m)%MOD;
		p=n;
	}
	printf("%lld\n", ans);
	return 0;
}