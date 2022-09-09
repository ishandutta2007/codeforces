#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXA = 2e4 + 5;
const int inf = 0x3f3f3f3f;

bool isnp[MAXA];
int pri[MAXA], pcnt=0;
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i;
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=n; ++j)
		{
			isnp[i*pri[j]] = 1;
			if(!(i%pri[j])) break;
		}
	}
}

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
		for(int i=1; i<=n; ++i) cur[i] = head[i];
		memset(dep,-1,sizeof(dep));
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
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
				if(!maxf) break;
			}
		return res;
	}
	int dinic(void)
	{
		int res=0;
		while(bfs()) res += dfs(s,inf);
		return res;
	}
	
	vector<int> get_to(int u)
	{
		vector<int> res;
		for(int i=head[u]; ~i; i=e[i].next)
			if(!e[i].flow) res.push_back(e[i].to);
		return res;
	}
};

int a[MAXN];

int main(void)
{
	sieve(MAXA-1);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	if(n&1) return printf("Impossible"), 0;
	
	static Max_Flow<MAXN, MAXN * MAXN / 2> mf;
	mf.clear();
	
	int s = n+1, t = n+2, cnt = 0;
	mf.init(n+2,s,t);
	for(int i=1; i<=n; ++i)
	{
		if(a[i]&1) mf.add_edge(s,i,2), ++cnt;
		else mf.add_edge(i,t,2);
	}
	if(cnt != n/2) return printf("Impossible"), 0;
	
	for(int i=1; i<=n; ++i) if(a[i]&1)
		for(int j=1; j<=n; ++j)
			if(!isnp[a[i] + a[j]])
				mf.add_edge(i, j, 1);
	if(mf.dinic() != n) return printf("Impossible"), 0;
	
	static vector<int> neib[MAXN];
	for(int i=1; i<=n; ++i) if(a[i]&1)
	{
		neib[i] = mf.get_to(i);
		sort(neib[i].begin(), neib[i].end());
		neib[i].pop_back();
		neib[neib[i][0]].push_back(i);
		neib[neib[i][1]].push_back(i);
	}
	
	static bool vis[MAXN];
	vector< vector<int> > ans;
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		ans.push_back(vector<int>());
		vector<int> &cur = ans.back();
		int u = i;
		while(!vis[u])
		{
			vis[u] = 1;
			cur.push_back(u);
			u = vis[neib[u][0]]? neib[u][1]: neib[u][0];
		}
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i, putchar('\n'))
	{
		printf("%d ",(int)ans[i].size());
		for(int j=0; j<(int)ans[i].size(); ++j)
			printf("%d ",ans[i][j]);
	}
	return 0;
}