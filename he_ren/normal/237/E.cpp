#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXL = 1e2 + 5;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct MCMF
{
	struct Edge
	{
		int next,to,flow,w;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add_one(int u,int v,int flow,int w)
	{
		e[++etot] = (Edge){ head[u],v,flow,w};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow,int w){ add_one(u,v,flow,w); add_one(v,u,0,-w);}
	
	int s,t;
	inline void clear(void){ etot=-1; memset(head,-1,sizeof(head));}
	inline void init(int s_,int t_){ s=s_; t=t_;}
	
	int dis[MAXN], pre[MAXN], flow[MAXN];
	bool spfa(void)
	{
		static bool vis[MAXN];
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		queue<int> q;
		dis[s] = 0; pre[s] = -1; flow[s] = inf;
		q.push(s); vis[s] = 1;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			vis[u] = 0;
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dis[v] > dis[u] + e[i].w)
				{
					dis[v] = dis[u] + e[i].w;
					pre[v] = i; flow[v] = min(flow[u], e[i].flow);
					if(!vis[v]) q.push(v), vis[v] = 1;
				}
			}
		}
		return dis[t] < inf;
	}
	inline pii mcmf(void)
	{
		int ansf = 0, ansc = 0;
		while(spfa())
		{
			ansf += flow[t]; ansc += flow[t] * dis[t];
			for(int u=t; u!=s; u = e[pre[u]^1].to)
				e[pre[u]].flow -= flow[t],
				e[pre[u]^1].flow += flow[t];
		}
		return make_pair(ansf, ansc);
	}
};

char t[MAXL];

int main(void)
{
	int n;
	scanf("%s%d",t+1,&n);
	int m = strlen(t+1);
	
	static int freq[30];
	for(int i=1; i<=m; ++i) ++freq[t[i] - 'a'];
	
	static MCMF<MAXN + 30, MAXN * 30> mf;
	static int s = 1, t = 2, id[30], pcnt = 2;
	mf.clear(); mf.init(s,t);
	for(int i=0; i<26; ++i)
		id[i] = ++pcnt, mf.add_edge(id[i], t, freq[i], 0);
	
	for(int k=1; k<=n; ++k)
	{
		static char str[MAXL];
		int x;
		scanf("%s%d",str+1,&x);
		
		static int sfreq[30];
		memset(sfreq,0,sizeof(sfreq));
		for(int i=1; str[i]; ++i) ++sfreq[str[i] - 'a'];
		
		++pcnt;
		mf.add_edge(s, pcnt, x, k);
		for(int i=0; i<26; ++i)
			mf.add_edge(pcnt, id[i], sfreq[i], 0);
	}
	
	pii res = mf.mcmf();
	if(res.first != m) printf("-1");
	else printf("%d",res.second);
	return 0;
}