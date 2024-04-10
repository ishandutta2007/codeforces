#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;
const int MAXM = 2e3 + 5;
const int MAXK = 10 + 5;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to,flow;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add_one(int u,int v,int flow)
	{
		e[++etot]=(Edge){ head[u],v,flow};
		head[u]=etot;
	}
	inline void add_edge(int u,int v,int flow)
	{
		add_one(u,v,flow); add_one(v,u,0);
	}
	
	int n,s,t;
	int dep[MAXN], cur[MAXN];
	inline void clear(void){ etot=-1; memset(head,-1,sizeof(head));}
	inline void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	Max_Flow(void){ clear();}
	inline bool bfs(void)
	{
		memset(dep,-1,(n+1)<<2); memcpy(cur,head,(n+1)<<2);
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(q.size())
		{
			int u=q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v=e[i].to;
				if(dep[v] == -1)
				{
					dep[v] = dep[u] + 1; q.push(v);
					if(v == t) return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int u,int maxf)
	{
		if(u == t || !maxf) return maxf;
		int res=0;
		for(int &i=cur[u], f; ~i; i=e[i].next)
			if(e[i].flow && dep[e[i].to] == dep[u]+1 && (f = dfs(e[i].to, min(e[i].flow, maxf))))
			{
				e[i].flow -= f; e[i^1].flow += f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	int dinic(void)
	{
		int res=0;
		while(bfs()) res += dfs(s,inf);
		return res;
	}
};

Max_Flow<MAXN + MAXM, MAXN + MAXM * MAXK> mf;

int a[MAXN], val[MAXN];

int main(void)
{
	int n,m,G;
	scanf("%d%d%d",&n,&m,&G);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&val[i]);
	
	int S = n+m+1, T = S+1;
	mf.init(T, S, T);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i])
			mf.add_edge(S, i, val[i]);
		else
			mf.add_edge(i, T, val[i]);
	}
	
	for(int i=1; i<=m; ++i)
	{
		int need,w,k;
		scanf("%d%d%d",&need,&w,&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			if(need) mf.add_edge(n+i, x, inf);
			else mf.add_edge(x, n+i, inf);
		}
		int is;
		scanf("%d",&is);
		if(is) ans -= G, w += G;
		
		if(need) ans += w, mf.add_edge(S, n+i, w);
		else ans += w, mf.add_edge(n+i, T, w);
	}
	
	printf("%d",ans - mf.dinic());
	return 0;
}