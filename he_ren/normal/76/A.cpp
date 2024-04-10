#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 5e4 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Edge_uvw
{
	int u,v,g,s;
}e[MAXM];
inline bool cmp_g(const Edge_uvw &p,const Edge_uvw &q){ return p.g < q.g;}
inline bool cmp_s(const Edge_uvw &p,const Edge_uvw &q){ return p.s < q.s;}

int n,m,cg,cs;

int fa[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

namespace Subtask1
{
	void solve(void)
	{
		sort(e+1,e+m+1,cmp_g);
		
		init(n);
		int cnt = n;
		
		ll ans = linf;
		for(int k=1; k<=m; ++k)
		{
			if(cnt > 1)
			{
				if(find(e[k].u) != find(e[k].v))
					connect(e[k].u, e[k].v), --cnt;
				if(cnt > 1) continue;
			}
			
			ll res = (ll)cg * e[k].g;
			sort(e+1,e+k+1,cmp_s);
			
			init(n);
			int mx = 0;
			for(int i=1; i<=k; ++i)
			{
				int u = e[i].u, v = e[i].v;
				if(find(u) == find(v)) continue;
				connect(u,v);
				mx = e[i].s;
			}
			
			ans = min(ans, res + (ll)cs * mx);
		}
		
		printf("%lld",ans);
		exit(0);
	}
}

namespace Subtask2
{
	vector<pii> g[MAXN];
	inline void add(int u,int v,int w)
	{
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	
	int begg, endd;
	bool vis[MAXN];
	pii dfs_mx(int u)
	{
		vis[u] = 1;
		if(u == endd) return make_pair(-1, -1);
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i].first;
			if(vis[v]) continue;
			pii res = dfs_mx(v);
			if(!res.first) continue;
			
			if(res.first == -1 || g[res.first][res.second].second < g[u][i].second)
				res = make_pair(u,i);
			return res;
		}
		return make_pair(0,0);
	}
	
	inline void del_from(int u,int v)
	{
		for(int i=0; i<(int)g[u].size(); ++i)
			if(g[u][i].first == v)
			{
				swap(g[u][i], g[u].back());
				g[u].pop_back();
				return;
			}
	}
	
	void solve(void)
	{
		sort(e+1,e+m+1,cmp_g);
		
		init(n);
		int cnt = n;
		
		multiset<int> val;
		
		ll ans = linf;
		for(int k=1; k<=m; ++k)
		{
			if(cnt > 1)
			{
				if(find(e[k].u) != find(e[k].v))
					connect(e[k].u, e[k].v), --cnt;
				if(cnt > 1) continue;
				
				ll res = (ll)cg * e[k].g;
				sort(e+1,e+k+1,cmp_s);
				
				init(n);
				
				for(int i=1; i<=k; ++i)
				{
					int u = e[i].u, v = e[i].v;
					if(find(u) == find(v)) continue;
					
					connect(u,v);
					add(u,v,e[i].s);
					val.insert(e[i].s);
				}
				
				ans = min(ans, res + (ll)cs * (*val.rbegin()));
				continue;
			}
			
			int u = e[k].u, v = e[k].v, w = e[k].s;
			if(u == v) continue;
			
			ll res = (ll)cg * e[k].g;
			
			begg = u; endd = v;
			for(int i=1; i<=n; ++i) vis[i] = 0;
			
			pii id = dfs_mx(u);
			if(id.first == -1) continue;
			int delw = g[id.first][id.second].second;
			if(delw <= w) continue;
			
			int delu = id.first, delv = g[id.first][id.second].first;
			del_from(delu, delv);
			del_from(delv, delu);
			val.erase(val.lower_bound(delw));
			
			val.insert(w);
			add(u,v,w);
			
			ans = min(ans, res + (ll)cs * (*val.rbegin()));
		}
		
		printf("%lld",ans);
		exit(0);
	}
}

int main(void)
{
	scanf("%d%d%d%d",&n,&m,&cg,&cs);
	for(int i=1; i<=m; ++i)
	{
		int u,v,g,s;
		scanf("%d%d%d%d",&u,&v,&g,&s);
		e[i] = (Edge_uvw){u,v,g,s};
	}
	
	init(n);
	for(int i=1; i<=m; ++i)
		connect(e[i].u, e[i].v);
	for(int i=1; i<=n; ++i)
		if(find(i) != find(1))
			return printf("-1"), 0;
	
	if(m <= 1000) Subtask1::solve();
	else Subtask2::solve();
	return 0;
}