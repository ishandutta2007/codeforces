#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}
inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int n,m;
vector<pii> g[MAXN];

void dijkstra(int beg,ll dis[])
{
	static bool vis[MAXN];
	memset(dis,0x3f,(n+1)<<3); memset(vis,0,n+1);
	priority_queue< pair<ll,int> > q;
	dis[beg] = 0; q.emplace(0, beg);
	while(q.size())
	{
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto it: g[u])
		{
			int v = it.first;
			if(dis[u] + it.second < dis[v])
				dis[v] = dis[u] + it.second,
				q.emplace(-dis[v], v);
		}
	}
}

int a[MAXN];

struct Data
{
	int beg;
	ll dis[MAXN];
	
	vector<int> p[MAXN];
	ll pval[MAXN];
	int pos[MAXN], len;
	
	void build(int _beg)
	{
		beg = _beg;
		dijkstra(beg, dis);
		dis[0] = -linf; dis[n+1] = linf;
		
		memcpy(pval, dis, sizeof(pval));
		sort(pval+1,pval+n+1);
		len = unique(pval+1,pval+n+1) - pval - 1;
		pval[0] = -linf; pval[n+1] = linf;
		
		for(int i=1; i<=n; ++i)
		{
			pos[i] = lower_bound(pval+1,pval+len+1,dis[i]) - pval;
			p[pos[i]].push_back(i);
		}
	}
	
	ll getchs(Data &oth,int i,int j)
	{
		assert(i <= len && j <= oth.len);
		bool ok = 0;
		ll sum = 0;
		for(int u: p[i]) if(oth.dis[u] >= oth.pval[j])
			sum += a[u],
			ok = 1;
		return ok? sum: linf;
	}
	void getchs(Data &oth,ll chs[MAXN][MAXN])
	{
		for(int i=1; i<=len; ++i)
			for(int j=1; j<=oth.len; ++j)
				chs[i][j] = getchs(oth, i, j);
	}
};

int main(void)
{
	int beg0, beg1;
	scanf("%d%d%d%d",&n,&m,&beg0,&beg1);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	
	static Data dat0, dat1;
	dat0.build(beg0);
	dat1.build(beg1);
	
	static ll chs0[MAXN][MAXN], chs1[MAXN][MAXN];
	dat0.getchs(dat1, chs0);
	dat1.getchs(dat0, chs1);
	
	static ll f0[MAXN][MAXN], f1[MAXN][MAXN];
	for(int i=dat0.len; i>=1; --i)
		for(int j=dat1.len; j>=1; --j)
		{
			if(chs0[i][j] == linf)
				f0[i][j] = f0[i+1][j];
			else
				f0[i][j] = chs0[i][j] + max(f1[i+1][j], f0[i+1][j]);
			
			if(chs1[j][i] == linf)
				f1[i][j] = f1[i][j+1];
			else
				f1[i][j] = -chs1[j][i] + min(f0[i][j+1], f1[i][j+1]);
		}
	
	if(f0[1][1] > 0)
		printf("Break a heart");
	if(f0[1][1] == 0)
		printf("Flowers");
	if(f0[1][1] < 0)
		printf("Cry");
	return 0;
}