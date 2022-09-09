#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e4 + 5;
const int MAXA = 5e4 + 5;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to,flow;
	}e[MAXM<<1];
	int head[MAXN], etot;
	inline void add_one(int u,int v,int flow)
	{
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow)
	{
		add_one(u,v,flow); add_one(v,u,0);
	}
	
	int n,s,t;
	int dep[MAXN], cur[MAXN];
	void init_clear(int _n,int _s,int _t)
	{
		n = _n; s = _s; t = _t;
		etot = -1; memset(head, -1, (n+1)<<2);
	}
	inline bool bfs(void)
	{
		memset(dep,-1,(n+1)<<2); memcpy(cur,head,(n+1)<<2);
		queue<int> q;
		dep[s] = 1; q.emplace(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dep[v] == -1)
				{
					dep[v] = dep[u] + 1; q.emplace(v);
					if(v == t) return 1;
				}
			}
		}
		return 0;
	}
	inline int dfs(int u,int maxf)
	{
		if(u == s || !maxf) return maxf;
		int res = 0, f;
		for(int &i=cur[u]; ~i; i=e[i].next)
			if(e[i^1].flow && dep[e[i].to] == dep[u]-1 && (f = dfs(e[i].to, min(maxf, e[i^1].flow))))
			{
				e[i].flow += f; e[i^1].flow -= f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	inline int dinic(void)
	{
		int res = 0;
		while(bfs()) res += dfs(t, inf);
		return res;
	}
};

vector<int> fact[MAXA];

int a[MAXN];
Max_Flow< MAXN * 4 + 10, (int)2e6 > mf;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	static int id[MAXA];
	for(int i=1; i<=n; ++i)
		id[a[i]] = i;
	
	int S = 4 * n + 1, T = 4 * n + 2;
	mf.init_clear(T, S, T);
	for(int i=1; i<=n; ++i)
	{
		mf.add_edge(        S, 4*(i-1)+1, 2);
		mf.add_edge(4*(i-1)+1, 4*(i-1)+2, 1);
		mf.add_edge(4*(i-1)+2, 4*(i-1)+3, 2);
		mf.add_edge(4*(i-1)+3, 4*(i-1)+4, 1);
		mf.add_edge(4*(i-1)+4,         T, 2);
		
		for(int t: fact[a[i]]) if(id[t])
		{
			int j = id[t];
			mf.add_edge(4*(j-1)+1, 4*(i-1)+2, 1);
			mf.add_edge(4*(j-1)+3, 4*(i-1)+4, 1);
		}
	}
	
	printf("%d\n",mf.dinic() - n);
	
	for(int i=1; i<=n; ++i)
		id[a[i]] = 0;
}

int main(void)
{
	for(int i=1; i<MAXA; ++i)
		for(int j=2*i; j<MAXA; j+=i)
			fact[j].push_back(i);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}