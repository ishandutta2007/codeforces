#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ldb;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Convex_Hull
{
	struct Line
	{
		bool type;
		ll k,b;
		mutable ldb x;
		Line(void){}
		Line(ll k,ll b): type(0), k(k), b(b), x(linf) {}
		Line(ldb x): type(1), x(x) {}
		
		inline friend bool operator < (const Line &p,const Line &q)
		{
			if(p.type || q.type) return p.x < q.x;
			return p.k == q.k? p.b > q.b: p.k > q.k;
		}
	};
	
	set<Line> t;
	typedef set<Line>::iterator Iter;
	
	Convex_Hull(void){}
	Convex_Hull(ll k,ll b){ t.insert(Line(k,b));}
	
	Iter prev(Iter it) const { return --it;}
	Iter next(Iter it) const { return ++it;}
	inline bool has_prev(const Iter &it) const { return it != t.begin();}
	inline bool has_next(const Iter &it) const { return it != t.end() && next(it) != t.end();}
	
	inline ldb inter(const Line &p,const Line &q) const { return (ldb)(p.b - q.b) / (q.k - p.k);}
	inline ldb inter(const Iter &p,const Iter &q) const { return inter(*p, *q);}
	
	inline bool bad(const Iter &it) const
	{
		return has_prev(it) && has_next(it) && inter(prev(it), it) >= inter(prev(it), next(it));
	}
	inline bool check_bad(const Iter &it){ return bad(it)? t.erase(it), 1: 0;}
	
	inline void insert(ll k,ll b)
	{
		pair<Iter, bool> res = t.insert(Line(k,b));
		Iter it = res.first;
		if(!res.second)
		{
			if(has_next(it)) it -> x = inter(it, next(it));
			return;
		}
		
		if(has_next(it) && next(it) -> k == k){ t.erase(it); return;}
		if(has_prev(it) && prev(it) -> k == k) t.erase(prev(it));
		if(check_bad(it)) return;
		
		while(has_next(it) && check_bad(next(it)));
		while(has_prev(it) && check_bad(prev(it)));
		
		if(has_prev(it)) prev(it) -> x = inter(prev(it), it);
		if(has_next(it)) it -> x = inter(it, next(it));
	}
	
	inline ll query(ll x) const
	{
		Line res = *t.lower_bound(Line(x));
		return res.k * x + res.b;
	}
	
	inline void merge(const Convex_Hull &oth)
	{
		for(Iter it = oth.t.begin(); it != oth.t.end(); ++it)
			insert(it -> k, it -> b);
	}
};

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int a[MAXN],b[MAXN];

int siz[MAXN], son[MAXN];
void dfs_son(int u,int fa)
{
	siz[u] = 1; son[u] = -1;
	for(int i = head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_son(v,u);
		
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

ll dp[MAXN];
Convex_Hull* hull[MAXN];

void dfs_dp(int u,int fa)
{
	if(son[u] == -1)
	{
		dp[u] = 0;
		hull[u] = new Convex_Hull(b[u], dp[u]);
		return;
	}
	
	dfs_dp(son[u], u);
	hull[u] = hull[son[u]];
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || v == son[u]) continue;
		dfs_dp(v,u);
		
		hull[u] -> merge(*hull[v]);
		delete hull[v];
	}
	
	dp[u] = hull[u] -> query(a[u]);
	hull[u] -> insert(b[u], dp[u]);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_son(1,0);
	dfs_dp(1,0);
	
	for(int i=1; i<=n; ++i) printf("%lld ",dp[i]);
	return 0;
}