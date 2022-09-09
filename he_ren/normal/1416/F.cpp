#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

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
	inline int getmatch(int u)
	{
		for(int i=head[u]; ~i; i=e[i].next)
			if(e[i].flow == 0)
				return e[i].to;
		return 0;
	}
};

int a[MAXN];
Max_Flow< MAXN + 10, MAXN * 10 > mf;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	auto enco = [&] (int x,int y)
	{
		return (x-1) * m + y;
	};
	for(int i=1; i<=n*m; ++i)
		scanf("%d",&a[i]);
	
	int semS = n*m+1, semT = semS+1, S = semT+1, T = S+1;
	mf.init_clear(T, S, T);
	mf.add_edge(semT, semS, inf);
	
	static int type[MAXN];
	int need = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int u = enco(i,j), flag = 0;
			for(int k=0; k<4; ++k)
			{
				int x = i + dx[k], y = j + dy[k];
				if(x < 1 || x > n || y < 1 || y > m) continue;
				int v = enco(x,y);
				
				if(a[v] < a[u])
					flag = v;
				if(a[v] == a[u] && ((i ^ j) & 1) == 0)
					mf.add_edge(u, v, 1);
			}
			
			type[u] = flag;
			if(!flag) ++need;
			
			if(((i ^ j) & 1) == 0)
			{
				if(flag) mf.add_edge(semS, u, 1);
				else mf.add_edge(semS, T, 1), mf.add_edge(S, u, 1);
			}
			else
			{
				if(flag) mf.add_edge(u, semT, 1);
				else mf.add_edge(u, T, 1), mf.add_edge(S, semT, 1);
			}
		}
	
	if(mf.dinic() != need)
	{
		printf("NO\n");
		return;
	}
	
	static int res[MAXN];
	memset(res, 0, (n*m+1)<<2);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			if(((i ^ j) & 1) != 0) continue;
			int u = enco(i,j);
			int v = mf.getmatch(u);
			if(v < 1 || v > n*m) continue;
			res[u] = v; res[v] = u;
		}
	for(int u=1; u<=n*m; ++u)
		if(res[u] == 0) res[u] = type[u];
	
	printf("YES\n");
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=m; ++j)
		{
			int u = enco(i,j);
			if(a[res[u]] < a[u])
				printf("%d ",a[u] - a[res[u]]);
			else if((i ^ j) & 1)
				printf("%d ",a[u] - 1);
			else
				printf("1 ");
		}
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=m; ++j)
		{
			int u = enco(i,j), v = res[u];
			int x = (v - 1) / m + 1, y = (v - 1) % m + 1;
			putchar(x < i? 'U': x > i? 'D': y < j? 'L': 'R');
			putchar(' ');
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}