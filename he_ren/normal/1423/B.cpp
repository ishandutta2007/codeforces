#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge_uvw
{
	int u,v,w;
}ee[MAXM];
inline bool cmp(const Edge_uvw &p,const Edge_uvw &q){ return p.w < q.w;}

namespace Dinic
{
	const int MAXE = MAXM + MAXN * 2;
	
	struct Edge
	{
		int next,to,f;
	}e[MAXE<<1];
	int head[MAXN*2], etot=1;
	inline void add(int u,int v,int f)
	{
		e[++etot] = (Edge){ head[u],v,f};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int f){ add(u,v,f); add(v,u,0);}
	
	int n,s,t;
	
	void clear(int nn,int ss,int tt)
	{
		n = nn; s = ss; t = tt;
		for(int i=1; i<=n; ++i) head[i] = 0;
		etot = 1;
	}
	
	int dep[MAXN*2], cur[MAXN*2];
	bool bfs(void)
	{
		for(int i=1; i<=n; ++i)
			dep[i] = -1, cur[i] = head[i];
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; i; i=e[i].next)
			{
				int v = e[i].to;
				if(e[i].f && dep[v] == -1)
					dep[v] = dep[u] + 1,
					q.push(v);
			}
		}
		return ~dep[t];
	}
	
	int dfs(int u,int minf)
	{
		if(u==t || !minf) return minf;
		int res=0;
		for(int &i=cur[u], f; i; i=e[i].next)
		{
			int v = e[i].to;
			if(dep[v] == dep[u]+1 && e[i].f && (f = dfs(v, min(minf, e[i].f))))
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
		while(bfs())
			res += dfs(s,inf);
		return res;
	}
}

int n;

bool check(int mid)
{
	int s = n*2 + 1, t = n*2 + 2;
	Dinic::clear(n*2+2, s, t);
	
	for(int i=1; i<=n; ++i)
		Dinic::add_edge(s,i,1),
		Dinic::add_edge(i+n,t,1);
	
	for(int i=1; i<=mid; ++i)
		Dinic::add_edge(ee[i].u, ee[i].v, 1);
	
	return Dinic::dinic() >= n;
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ee[i] = (Edge_uvw){ u,v+n,w};
	}
	sort(ee+1,ee+m+1,cmp);
	
	int l=1, r=m;
	if(!check(r)) return printf("-1"), 0;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d",ee[l].w);
	return 0;
}