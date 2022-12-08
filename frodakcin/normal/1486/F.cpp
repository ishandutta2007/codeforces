#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

#define f first
#define s second

using ll = long long;
using pii = std::pair<int, int>;

const int MN = 3e5+10;

ll ans;
int N, M, p[MN][20], id[MN], d[MN], val[MN], sub[MN];
std::vector<int> a[MN];
std::vector<pii> q[MN];

void dfs(int n=1)
{
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];
	int i=0;
	for(int x:a[n])
		if(x!=p[n][0])
			id[x]=i++, d[x]=d[n]+1, p[x][0]=n, dfs(x);
}

int mu(int a, int x)
{
	for(int i=0;x;++i)
		if(x>>i&1)
			x^=1<<i, a=p[a][i];
	return a;
}

int lca(int a, int b)
{
	if(d[a]<d[b]) std::swap(a,b);
	a=mu(a, d[a]-d[b]);
	if(a==b) return a;
	assert(d[a]>0);
	for(int i=31-__builtin_clz(d[a]);i>=0;--i)
		if(p[a][i]!=p[b][i])
			a=p[a][i], b=p[b][i];
	assert(a!=b&&p[a][0]==p[b][0]);
	return p[a][0];
}

void solve(int n=1)
{
	std::vector<int> del(a[n].size(), 0); // technically 1 larger than necessary, but that's ok
	int i=0;
	for(auto x:a[n])
		if(x!=p[n][0])
		{
			solve(x);
			val[n] += val[x];
			del[i++] += val[x];
		}
	ll tot=val[n];
	std::map<pii, int> ctr;
	for(pii& x:q[n])
	{
		ans += tot++;
		if(~x.f) ans-=del[x.f]++;
		if(~x.s)
		{
			ans-=del[x.s]++;

			auto it=ctr.find(x);
			if(it==ctr.end()) it=ctr.insert({x, 0}).first;
			ans+=it->second++;
		}
	}
	val[n] -= sub[n];
}

int main()
{
	scanf("%d", &N);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	dfs();
	
	//computation: top * all
	scanf("%d", &M);
	for(int i=0,u,v;i<M;++i)
	{
		scanf("%d%d", &u, &v);
		if(u==v) q[u].push_back({-1, -1});
		else
		{
			int l=lca(u,v);
			if(l==v) std::swap(u,v);
			if(l==u)
			{
				int vv=mu(v, d[v]-d[l]-1);
				++val[v], ++sub[vv];
				q[l].push_back({id[vv], -1});
			}
			else
			{
				int uu=mu(u, d[u]-d[l]-1), vv=mu(v, d[v]-d[l]-1);
				assert(uu != vv);
				++val[u], ++val[v], ++sub[uu], ++sub[vv];
				if(id[vv]<id[uu]) std::swap(uu, vv);
				q[l].push_back({id[uu], id[vv]});
			}
		}
	}
	solve();

	printf("%lld\n", ans);
	return 0;
}