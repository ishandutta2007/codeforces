#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = MAXN * MAXN / 2;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	vector<int> g[MAXN], rev[MAXN];
	vector<ll> fl[MAXN];
	inline void add_edge(int u,int v,ll flow)
	{
		rev[u].push_back(g[v].size()); rev[v].push_back(g[u].size());
		g[u].push_back(v); g[v].push_back(u);
		fl[u].push_back(flow); fl[v].push_back(0);
	}
	
	int n,s,t;
	inline void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	int dep[MAXN], cur[MAXN];
	inline bool bfs(void)
	{
		for(int i=1; i<=n; ++i) dep[i] = -1, cur[i] = 0;
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=0; i<(int)g[u].size(); ++i) if(fl[u][i])
			{
				int v = g[u][i];
				if(dep[v] == -1) dep[v] = dep[u] + 1, q.push(v);
			}
		}
		return ~dep[t];
	}
	ll dfs(int u,ll maxf)
	{
		if(u == t || !maxf) return maxf;
		ll res = 0, f;
		for(int &i=cur[u]; i<(int)g[u].size(); ++i)
			if(fl[u][i] && dep[g[u][i]] == dep[u] + 1 && (f = dfs(g[u][i], min(fl[u][i], maxf))))
			{
				fl[u][i] -= f; fl[g[u][i]][rev[u][i]] += f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	inline ll dinic(void)
	{
		ll res = 0;
		while(bfs()) res += dfs(s,linf);
		return res;
	}
};

Max_Flow<MAXN * MAXN, MAXN * MAXN + MAXN * MAXM> mf;

ll val[MAXN];
int id[MAXN][MAXN], pcnt = 0;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) id[i][j] = ++pcnt;
	
	int s = ++pcnt, t = ++pcnt;
	for(int i=1; i<=n; ++i) id[i][n+1] = t;
	mf.init(pcnt, s, t);
	
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		for(int j=1; j<=n; ++j)
			mf.add_edge(id[v][j], id[u][j+1], linf);
		val[u] += w; val[v] -= w;
	}
	
	const ll C = 1e13;
	for(int i=1; i<=n; ++i)
	{
		mf.add_edge(s, id[i][1], linf);
		for(int j=1; j<=n; ++j)
			mf.add_edge(id[i][j], id[i][j+1], val[i] * j + C);
	}
	mf.dinic();
	
	mf.bfs();
	for(int i=1; i<=n; ++i)
	{
		int cnt = 0;
		for(int j=1; j<=n; ++j)
			if(~mf.dep[id[i][j]]) ++cnt;
		printf("%d ",cnt);
	}
	return 0;
}