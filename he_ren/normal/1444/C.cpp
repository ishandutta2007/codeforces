#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;

template<const int MAXN,const int MAXM>
struct Graph
{
	struct Edge
	{
		int next,to;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add(int u,int v)
	{
		e[++etot] = (Edge){ head[u],v};
		head[u] = etot;
	}
	Graph(): etot(0) {}
	
	inline Edge& operator [] (const int x){ return e[x];}
	inline const Edge operator [] (const int x) const { return e[x];}
};

int fa[MAXN*2];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

// g = before, h = after
Graph<MAXN,MAXM> g;
Graph<MAXN*2,MAXM> h;

int c[MAXN];// c[u]: group
vector<int> nodes[MAXN];
bool illegal[MAXN];

int clr[MAXN];// clr[u]: black / white
vector<int> cur_part;

bool dfs_clr(int u)
{
	cur_part.push_back(u);
	for(int i=g.head[u]; i; i=g[i].next)
	{
		int v = g[i].to;
		if(c[v] == c[u])
		{
			if(clr[v] == -1)
			{
				clr[v] = !clr[u];
				if(!dfs_clr(v)) return 0;
			}
			else if(clr[v] == clr[u]) return 0;
		}
	}
	return 1;
}

int pcnt = 0;
int at_part[MAXN];
vector<int> partss[MAXN];

int part_clr[MAXN*2], oth[MAXN*2];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g.add(u,v); g.add(v,u);
	}
	
	for(int i=1; i<=n; ++i)
		nodes[c[i]].push_back(i);
	
	int icnt = 0;
	
	memset(clr,-1,sizeof(clr));
	for(int k=1; k<=d; ++k)
	{
		vector<int> &node = nodes[k];
		for(int i=0; i<(int)node.size(); ++i) if(clr[node[i]] == -1)
		{
			int u = node[i];
			
			cur_part.clear();
			
			clr[u] = 0;
			if(!dfs_clr(u))
			{
				illegal[k] = 1;
				++icnt;
				break;
			}
			
			part_clr[pcnt+1] = part_clr[pcnt+2] = k;
			oth[pcnt+1] = pcnt+2;
			oth[pcnt+2] = pcnt+1;
			
			partss[k].push_back(pcnt+1);
			partss[k].push_back(pcnt+2);
			
			for(int j=0; j<(int)cur_part.size(); ++j)
			{
				int v = cur_part[j];
				at_part[v] = pcnt + clr[v] + 1;
			}
			pcnt += 2;
		}
	}
	
	for(int u=1; u<=n; ++u) if(!illegal[c[u]])
	{
		for(int i=g.head[u]; i; i=g[i].next)
		{
			int v = g[i].to;
			if(illegal[c[v]]) continue;
			
			if(c[v] != c[u])
				h.add(at_part[u], at_part[v]);
		}
	}
	
	init(pcnt);
	
	ll ans = 0;
	for(int k=1; k<=d; ++k) if(!illegal[k])
	{
		vector<int> &parts = partss[k];
		
		vector<int> has_e;
		static vector<pii> es[MAXN];
		
		for(int i=0; i<(int)parts.size(); ++i)
		{
			int u = parts[i];
			for(int i=h.head[u]; i; i=h[i].next)
			{
				int v = h[i].to;
				has_e.push_back(part_clr[v]);
				es[part_clr[v]].push_back(make_pair(u,v));
			}
		}
		
		int can = d - 1 - icnt;
		for(int j=0; j<(int)has_e.size(); ++j) if(es[has_e[j]].size())
		{
			vector<pii> &e = es[has_e[j]];
			
			for(int i=0; i<(int)e.size(); ++i)
			{
				int u = e[i].first, v = e[i].second;
				connect(oth[u], v);
				connect(u, oth[v]);
			}
			
			bool flag = 1;
			for(int i=0; i<(int)e.size(); ++i)
			{
				int u = e[i].first, v = e[i].second;
				if(find(u) == find(v) || find(u) == find(oth[u]) || find(v) == find(oth[v]) || find(oth[u]) == find(oth[v]))
				{
					flag = 0;
					break;
				}
			}
			
			if(!flag) --can;
			
			for(int i=0; i<(int)e.size(); ++i)
			{
				int u = e[i].first, v = e[i].second;
				fa[u] = u; fa[v] = v;
				fa[oth[u]] = oth[u];
				fa[oth[v]] = oth[v];
			}
			
			e.clear();
		}
		
		ans += can;
	}
	
	printf("%lld",ans/2);
	return 0;
}