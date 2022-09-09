#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXQ = 1e5 + 5;
const int MAXA = 1e7 + 5;
const int MAXP = 6.7e5 + 5;
const int LB = 17 + 2;
const int LBA = 23 + 2;
const int mod = 1e9 + 7;

int lb[MAXN];

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

bool isnp[MAXA];
int p[MAXP], mnp[MAXA], pcnt = 0;
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) p[++pcnt] = i, mnp[i] = pcnt;
		for(int j=1; j<=pcnt && (ll)i*p[j] <= n; ++j)
		{
			isnp[i*p[j]] = 1; mnp[i*p[j]] = j;
			if(!(i%p[j])) break;
		}
	}
}

inline vector<pii> get_fact(int x)
{
	vector<pii> res;
	while(x > 1)
	{
		int k = mnp[x], cnt = 0, pk = p[k];
		while(x%pk == 0) x /= pk, ++cnt;
		res.push_back(make_pair(k, cnt));
	}
	return res;
}

template<const int N>
struct BIT
{
	int tree[N+1];
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=N)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r) - query(l-1);}
};

template<const int N>
struct BIT_rev
{
	BIT<N> tree;
	inline void update(int x,int k){ tree.update(N-x+1, k);}
	inline int query(int x){ return tree.query(N-x+1);}
	inline int query(int l,int r){ return query(l) - query(r+1);}
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

int dep[MAXN], pre[MAXN][LB];
void lca_init(int u,int fa)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
		pre[u][i] = pre[pre[u][i-1]][i-1];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dep[v] = dep[u]+1; pre[v][0] = u;
		lca_init(v,u);
	}
}
inline int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	while(dep[u] > dep[v]) u = pre[u][lb[dep[u] - dep[v]]];
	if(u == v) return u;
	for(int i=lb[dep[u]]; pre[u][0] != pre[v][0]; --i)
		if(i<=lb[dep[u]] && pre[u][i] != pre[v][i])
			u = pre[u][i], v = pre[v][i];
	return pre[u][0];
}

int a[MAXN];

struct Query
{
	int u,v,uv,x;
}qry[MAXQ];
vector<pii> b[MAXQ];
vector<int> res[MAXQ];

BIT<LBA> tsum[MAXP];
BIT_rev<LBA> tcnt[MAXP];
vector< pair<pii,int> > tag[MAXN];

void dfs_res(int u,int fa)
{
	vector<pii> vec = get_fact(a[u]);
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int k = vec[i].first, cnt = vec[i].second;
		tsum[k].update(cnt, cnt);
		tcnt[k].update(cnt, 1);
	}
	
	for(int i=0; i<(int)tag[u].size(); ++i)
	{
		int px = tag[u][i].first.first, py = tag[u][i].first.second, coef = tag[u][i].second;
		int pid = b[px][py].first, cnt = b[px][py].second;
		
		res[px][py] += coef * (tsum[pid].query(cnt) + cnt * tcnt[pid].query(cnt+1));
	}
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_res(v,u);
	}
	
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int k = vec[i].first, cnt = vec[i].second;
		tsum[k].update(cnt, -cnt);
		tcnt[k].update(cnt, -1);
	}
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	sieve(MAXA-1);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	lca_init(1,0);
	
	int Q;
	scanf("%d",&Q);
	for(int k=1; k<=Q; ++k)
	{
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		int uv = lca(u,v);
		qry[k] = (Query){ u,v,uv,x};
		
		vector<pii> &vec = b[k] = get_fact(x);
		res[k].resize(vec.size());
		for(int i=0; i<(int)vec.size(); ++i)
		{
			pii pos = make_pair(k, i);
			tag[u].push_back(make_pair(pos, 1));
			tag[v].push_back(make_pair(pos, 1));
			tag[uv].push_back(make_pair(pos, -2));
		}
	}
	
	dfs_res(1,0);
	
	for(int k=1; k<=Q; ++k)
	{
		ll ans = gcd(qry[k].x, a[qry[k].uv]);
		for(int i=0; i<(int)res[k].size(); ++i)
			ans = (ans * pw(p[b[k][i].first], res[k][i])) %mod;
		printf("%lld\n",ans);
	}
	return 0;
}