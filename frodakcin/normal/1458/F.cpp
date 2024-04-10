#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using ll = long long;

const int MN = 2e5+10; // for doubling each edge

int N, d[MN], p[MN][20], s[MN], cnt[MN];
bool r[MN];
std::vector<int> a[MN], bcnt[MN];
std::vector<ll> bsum[MN];
ll sum[MN], ans, pfx[MN];

struct Group
{
	public:
		int c, b, d;
};
std::vector<Group> g[MN];

//Tree
void adde(int u, int v) {a[u].push_back(v), a[v].push_back(u);}

void dfs1(int n=1)
{
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];
	for(int x:a[n])
		if(x!=p[n][0])
			p[x][0]=n, d[x]=d[n]+1, dfs1(x);
}

int mu(int n, int v) // move up *by* v, not down to v
{
	for(int i=0;v;++i)
		if(v>>i&1)
			v^=1<<i, n=p[n][i];
	return n;
}

int lca(int a, int b)
{
	if(d[a]<d[b]) std::swap(a,b);
	a=mu(a, d[a]-d[b]);
	if(a==b) return a;
	for(int i=17;i>=0;--i)
		if(p[a][i]!=p[b][i])
			a=p[a][i], b=p[b][i];
	return p[a][0];
}

int go(int a, int b, int l, int v) // v-th node along a->b, where lca=l
{
	if(v>d[a]-d[l])
		return mu(b, d[b]+d[a]-2*d[l]-v); // aka (d[b]-d[l])-(v-(d[a]-d[l])
	return mu(a, v);
}

//Centroid
int dfs2(int n, int p=0)
{
	s[n]=1;
	for(int x:a[n])
		if(!r[x] && x!=p)
			s[n]+=dfs2(x, n);
	return s[n];
}

int get_centroid(int n, int ms, int p=0)
{
	for(int x:a[n])
		if(!r[x] && x!=p && s[x]*2>ms)
			return get_centroid(x, ms, n);
	return n;
}

void centroid(int n=1)
{
	int c=get_centroid(n, dfs2(n));

	int b=0;
	std::function<void(int, int, int)> dfs=[&](int n, int p, int d)
	{
		g[n].push_back({c, b, d});
		for(int x:a[n])
			if(!r[x] && x!=p)
				dfs(x, n, d+1);
	};
	for(int x:a[c])
		if(!r[x])
			dfs(x, c, 1), ++b;
	bcnt[c].assign(b, 0);
	bsum[c].assign(b, 0);

	r[c]=1;
	for(int x:a[c])
		if(!r[x])
			centroid(x);
}

void ins(int n)
{
	for(auto x:g[n])
	{
		++cnt[x.c];
		sum[x.c] += x.d;
		++bcnt[x.c][x.b];
		bsum[x.c][x.b] += x.d;
	}
	++cnt[n];
}

void ers(int n)
{
	for(auto x:g[n])
	{
		--cnt[x.c];
		sum[x.c] -= x.d;
		--bcnt[x.c][x.b];
		bsum[x.c][x.b] -= x.d;
	}
	--cnt[n];
}

ll qry(int n)
{
	ll f=0;
	for(auto x:g[n])
	{
		f += sum[x.c]-bsum[x.c][x.b];
		f += (ll)(cnt[x.c]-bcnt[x.c][x.b])*x.d;
	}
	f += sum[n];
	return f;
}

//Solve
struct Circle
{
	public:
		int c, r;
		Circle(int _c=0, int _r=0): c(_c), r(_r) {}
		bool cover(const Circle& o) const //strict covering (equality doesnt work)
		{
			int l=lca(c, o.c);
			int dis=d[c]+d[o.c]-2*d[l];
			return r>o.r+dis;
		}
		Circle merge(const Circle& o) const
		{
			int l=lca(c, o.c);
			int dis=d[c]+d[o.c]-2*d[l];
			if(r>=o.r+dis) return *this;
			if(o.r>=r+dis) return o;
			assert(!(dis+o.r+r&1));
			return {go(c, o.c, l, dis+o.r-r>>1), r+o.r+dis>>1};
		}
} circ[MN];

void solve(int l, int r)
{
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		pfx[m]=0;
		for(int i=m;i<r;++i)
		{
			circ[i]={i,0};
			if(i>m) circ[i]=circ[i].merge(circ[i-1]);
			pfx[i+1]=pfx[i]+circ[i].r;
		}
		for(int i=m-1;i>=l;--i)
		{
			circ[i]={i,0};
			if(i<m-1) circ[i]=circ[i].merge(circ[i+1]);
		}

		int a=m, b=m;
		for(int i=m-1;i>=l;--i)
		{
			for(;b<r && !circ[b].cover(circ[i]);++b)
				ins(circ[b].c);
			for(;a<r && circ[i].cover(circ[a]);++a)
				ers(circ[a].c);

			ans += (ll)(a-m)*circ[i].r*2;
			ans += (pfx[r]-pfx[b])*2;
			ans += qry(circ[i].c) + (ll)(b-a)*circ[i].r + pfx[b]-pfx[a];
		}
		for(;a<b;++a)
			ers(circ[a].c);

		solve(l, m);
		solve(m, r);
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=1;i<N;++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		adde(a, N+i);
		adde(N+i, b);
	}

	dfs1();
	centroid();
	solve(1, N+1);
	
	printf("%lld\n", ans/2); // cuz doubled each edge
	return 0;
}