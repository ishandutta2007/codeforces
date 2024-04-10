#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXC = 2e5 + 5;
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
	inline void clear(void){ memset(head,-1,sizeof(head)); etot=-1;}
	inline void init(int _n,int _s,int _t){ n = _n; s = _s; t = _t;}
	inline bool bfs(void)
	{
		memset(dep,-1,(n+1)<<2); memcpy(cur,head,(n+1)<<2);
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
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
		while(bfs()) res += dfs(s, inf);
		return res;
	}
};

bool isnp[MAXC];

Max_Flow<MAXN, MAXN * MAXN + MAXN> mf;

int n, d;
int p[MAXN], c[MAXN], lvl[MAXN];

inline bool chk(int lim)
{
	vector<int> cs, ps;
	int mx1 = 0;
	for(int i=1; i<=n; ++i) if(lvl[i] <= lim)
	{
		if(c[i] == 1) mx1 = max(mx1, p[i]);
		else cs.push_back(c[i]), ps.push_back(p[i]);
	}
	if(mx1) cs.push_back(1), ps.push_back(mx1);
	
	int m = (int)cs.size();
	int S = m+1, T = m+2;
	mf.clear();
	mf.init(m+2, S, T);
	
	int sum = 0;
	for(int i=0; i<m; ++i)
	{
		sum += ps[i];
		if(cs[i] % 2) mf.add_edge(S, i+1, ps[i]);
		else mf.add_edge(i+1, T, ps[i]);
	}
	
	for(int i=0; i<m; ++i) if(cs[i] % 2)
		for(int j=0; j<m; ++j) if(cs[j] % 2 == 0 && !isnp[cs[i] + cs[j]])
			mf.add_edge(i+1, j+1, inf);
	
	int res = sum - mf.dinic();
	return res >= d;
}

int main(void)
{
	isnp[1] = 1;
	for(int i=2; i<MAXC; ++i)
		for(int j=i+i; j<MAXC; j+=i)
			isnp[j] = 1;
	
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d%d%d",&p[i],&c[i],&lvl[i]);
	
	int l = 0, r = n + 1;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l > n? -1: l);
	return 0;
}