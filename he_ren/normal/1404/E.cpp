#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 2e2 + 5;
const int MAXP = MAXN * MAXM * 2;
const int MAXE = MAXN * MAXM * 4 + MAXP;
const int inf = 0x3f3f3f3f;

struct Max_Flow
{
	struct Edge
	{
		int next,to,f;
	}e[MAXE<<1];
	int head[MAXP], etot;
	inline void add(int u,int v,int f)
	{
		e[++etot] = (Edge){ head[u],v,f};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int f){ add(u,v,f); add(v,u,0);}
	
	int s,t,pcnt;
	
	Max_Flow(): etot(-1) { memset(head,-1,sizeof(head));}
	
	int cur[MAXP], dis[MAXP];
	bool bfs(void)
	{
		for(int i=1; i<=pcnt; ++i)
			cur[i] = head[i],
			dis[i] = -1;
		queue<int> q;
		dis[s]=0; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next)
				if(e[i].f && dis[e[i].to] == -1)
					dis[e[i].to] = dis[u] + 1,
					q.push(e[i].to);
		}
		return ~dis[t];
	}
	int dfs(int u,int minf)
	{
		if(u==t || !minf) return minf;
		int res = 0, f;
		for(int &i=cur[u]; ~i; i=e[i].next)
		{
			int v = e[i].to;
			if(dis[v] == dis[u]+1 && e[i].f && (f = dfs(v, min(minf, e[i].f))))
			{
				e[i].f -= f; e[i^1].f += f;
				res += f; minf -= f;
			}
		}
		return res;
	}
	int dinic(void)
	{
		int res = 0;
		while(bfs()) res += dfs(s, inf);
		return res;
	}
};

char s[MAXN][MAXM];

int atlef[MAXP];
Max_Flow solver;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	static vector<int> hori[MAXN][MAXM], vert[MAXN][MAXM];
	
	int ans = 0;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) if(s[i][j] == '#')
		{
			++ans;
			if(s[i-1][j] == '#')
			{
				atlef[++solver.pcnt] = 1;
				hori[i][j].push_back(solver.pcnt);
				hori[i-1][j].push_back(solver.pcnt);
			}
			if(s[i][j-1] == '#')
			{
				atlef[++solver.pcnt] = 0;
				vert[i][j].push_back(solver.pcnt);
				vert[i][j-1].push_back(solver.pcnt);
			}
		}
	solver.s = ++solver.pcnt;
	solver.t = ++solver.pcnt;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) if(s[i][j] == '#')
		{
			for(int x=0; x<(int)hori[i][j].size(); ++x)
				for(int y=0; y<(int)vert[i][j].size(); ++y)
					solver.add_edge(hori[i][j][x], vert[i][j][y], 1);
		}
	for(int i=1; i<solver.s; ++i)
	{
		if(atlef[i]) solver.add_edge(solver.s, i, 1);
		else solver.add_edge(i, solver.t, 1);
	}
	
	ans -= solver.pcnt-2 - solver.dinic();
	printf("%d", ans);
	return 0;
}