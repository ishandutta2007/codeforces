#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 6e2 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int n,m;
vector<pii> g[MAXN];

ll dis[MAXN];
bool vis[MAXN];

void solve(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	for(int T=1; T<=n; ++T)
	{
		int u = -1;
		for(int i=1; i<=n; ++i) if(!vis[i])
			if(u == -1 || dis[i] < dis[u])
				u = i;
		vis[u] = 1;
		
		static int f[MAXN];
		memset(f, 0x3f, (n+1) << 2);
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int pos = (g[u][i].first - 1 + dis[u]) % n + 1;
			chk_min(f[pos], g[u][i].second);
		}
		
		for(int i=2; i<=n; ++i) chk_min(f[i], f[i-1] + 1);
		chk_min(f[1], f[n] + 1);
		for(int i=2; i<=n; ++i) chk_min(f[i], f[i-1] + 1);
		
		for(int i=1; i<=n; ++i)
			chk_min(dis[i], dis[u] + f[i]);
	}
	
	for(int i=1; i<=n; ++i) printf("%lld ",dis[i]);
	putchar('\n');
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x+1].push_back(make_pair(y+1, z));
	}
	
	for(int i=1; i<=n; ++i) solve(i);
	return 0;
}