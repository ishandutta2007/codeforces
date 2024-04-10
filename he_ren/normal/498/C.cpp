#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;
const int LB = 30 + 2;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to,flow;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add(int u,int v,int flow)
	{
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow){ add(u,v,flow); add(v,u,0);}
	
	int n,s,t;
	inline void clear(void){ etot=-1; memset(head,-1,sizeof(head));}
	inline void init(int n_,int s_,int t_){ n=n_; s=s_; t=t_;}
	
	int dep[MAXN], cur[MAXN];
	bool bfs(void)
	{
		for(int i=1; i<=n; ++i) cur[i] = head[i], dep[i] = -1;
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v=e[i].to;
				if(dep[v] == -1)
					dep[v] = dep[u]+1, q.push(v);
			}
		}
		return ~dep[t];
	}
	int dfs(int u,int maxf)
	{
		if(u==t || !maxf) return maxf;
		int res=0;
		for(int &i=cur[u], f; ~i; i=e[i].next)
			if(e[i].flow && dep[e[i].to] == dep[u]+1 && (f = dfs(e[i].to, min(maxf, e[i].flow))))
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

int a[MAXN];
vector<int> frac[MAXN], id[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int pcnt = 0;
	for(int k=1; k<=n; ++k)
	{
		int x = a[k];
		for(int i=2; i*i<=x; ++i) if(x%i == 0)
		{
			while(x%i == 0) x/=i;
			frac[k].push_back(i);
			id[k].push_back(++pcnt);
		}
		if(x>1) frac[k].push_back(x), id[k].push_back(++pcnt);
	}
	int s = ++pcnt, t = ++pcnt;
	
	static Max_Flow<MAXN * LB, MAXM * LB> mf;
	mf.clear();
	mf.init(pcnt, s, t);
	
	for(int k=1; k<=n; ++k)
	{
		int x = a[k];
		for(int i=0; i<(int)frac[k].size(); ++i)
		{
			int cnt = 0;
			while(x%frac[k][i] == 0) ++cnt, x /= frac[k][i];
			if(k&1) mf.add_edge(s, id[k][i], cnt);
			else mf.add_edge(id[k][i], t, cnt);
		}
	}
	
	for(int k=1; k<=m; ++k)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		if(v&1) swap(u,v);
		for(int i=0, j=0; i<(int)frac[u].size(); ++i)
		{
			while(j<(int)frac[v].size() && frac[v][j] < frac[u][i]) ++j;
			if(j >= (int)frac[v].size()) break;
			if(frac[u][i] == frac[v][j])
				mf.add_edge(id[u][i], id[v][j], inf);
		}
	}
	
	printf("%d",mf.dinic());
	return 0;
}