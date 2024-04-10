#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e3 + 5;
const int MAXA = 1e2 + 5;
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
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow){ add_one(u,v,flow); add_one(v,u,0);}
	
	int n,s,t;
	int dep[MAXN], cur[MAXN];
	inline void clear(void){ memset(head,-1,sizeof(head)); etot = -1;}
	inline void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	Max_Flow(void){ clear();}
	inline bool bfs(void)
	{
		for(int i=1; i<=n; ++i) dep[i] = -1, cur[i] = head[i];
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dep[v] == -1) dep[v] = dep[u] + 1, q.push(v);
			}
		}
		return ~dep[t];
	}
	int dfs(int u,int maxf)
	{
		if(u == t || !maxf) return maxf;
		int res = 0;
		for(int &i=cur[u], f; ~i; i=e[i].next)
			if(e[i].flow && dep[e[i].to] == dep[u] + 1 && (f = dfs(e[i].to, min(maxf, e[i].flow))))
			{
				e[i].flow -= f; e[i^1].flow += f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	inline int dinic(void)
	{
		int res = 0;
		while(bfs()) res += dfs(s,inf);
		return res;
	}
};

int a[MAXN], b[MAXN];
bitset<MAXA> fact[MAXA];
Max_Flow<MAXN, MAXN * MAXA> mf;

int main(void)
{
	for(int i=1; i<=100; ++i)
		for(int j=1; j<=i; ++j)
			if(i%j == 0) fact[i][j] = 1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i)
	{
		bitset<MAXA> cur;
		for(int j=i-1; j>=1; --j) if(a[i] % a[j] == 0)
		{
			if(a[j] == a[i]){ mf.add_edge(i,j,inf); break;}
			if(cur[a[j]]) continue;
			mf.add_edge(i,j,inf); cur |= fact[a[j]];
		}
	}
	
	ll ans = 0;
	int s = n+1, t = n+2;
	for(int i=1; i<=n; ++i)
	{
		if(b[i] < 0) mf.add_edge(i,t,-b[i]);
		else ans += b[i], mf.add_edge(s,i,b[i]);
	}
	mf.init(t,s,t);
	
	printf("%lld",ans - mf.dinic());
	return 0;
}