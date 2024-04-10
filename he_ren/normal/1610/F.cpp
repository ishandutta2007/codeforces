#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;

int us[MAXM], vs[MAXM], ew[MAXM];
vector<int> g[MAXN][3];

int fa[MAXM], siz[MAXM], fu[MAXM], fv[MAXM];
bool rev[MAXM];
int find(int u){ return fa[u] == u? u: find(fa[u]);}
inline void upd_rev(int id){ rev[id] ^= 1; swap(fu[id], fv[id]);}
inline bool get_rev(int u){ return fa[u] == u? rev[u]: rev[u] ^ get_rev(fa[u]);}

int fres[MAXM];

inline void connect(int u,int v,int mid)
{
	u = find(u); v = find(v);
	if(siz[u] > siz[v]) swap(u,v);
	if(fu[u] == mid) upd_rev(u);
	if(fv[v] == mid) upd_rev(v);
//	printf("merge: (%d, %d) (%d, %d) %d\n",fu[u],fv[u],fu[v],fv[v],mid);
	
	if(fu[u] == fv[v])
	{
		fres[u] = fres[v] = 1;
		return;
	}
	
	fu[v] = fu[u]; siz[v] += siz[u];
	fa[u] = v; rev[u] ^= rev[v];
}

void dfs_res(int u)
{
	if(g[u][1].size() + g[u][2].size() <= 1)
	{
		int x = g[u][1].size()? g[u][1][0]: g[u][2][0];
		if(fres[x]) return;
		fres[x] = 1;
		dfs_res(fu[x] ^ fv[x] ^ u);
		return;
	}
	
	int x = g[u][1][0], y = g[u][2][0];
	if(fres[x] && fres[y]) return;
	if(fres[y]) swap(x, y);
	if(!fres[x])
	{
		fres[x] = 1;
		dfs_res(fu[x] ^ fv[x] ^ u);
	}
	
	fres[y] = ((fu[x] == u) ^ (fu[y] == u) ^ (fres[x] == 2))? 1: 2;
	dfs_res(fu[y] ^ fv[y] ^ u);
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		us[i] = u; vs[i] = v; ew[i] = w;
		g[u][w].push_back(i);
		g[v][w].push_back(i);
	}
	
	for(int i=1; i<=m; ++i)
	{
		fa[i] = i; siz[i] = 1;
		fu[i] = us[i]; fv[i] = vs[i];
		rev[i] = 0;
	}
	
	auto trim = [&] (vector<int> &vec)
	{
		vector<int> nxt;
		for(int x: vec)
		{
			x = find(x);
			if(!fres[x]) nxt.push_back(x);
		}
		vec = nxt;
	};
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=2; ++j)
		{
			trim(g[i][j]);
			while(g[i][j].size() >= 2)
			{
				int u = g[i][j].back(); g[i][j].pop_back();
				int v = g[i][j].back(); g[i][j].pop_back();
				connect(u, v, i);
			}
		}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=2; ++j)
			trim(g[i][j]);
	
	for(int i=1; i<=n; ++i)
		if(g[i][1].size() && !fres[g[i][1][0]])
			dfs_res(i);
	
	for(int i=1; i<=m; ++i) if(!fres[i]) fres[i] = 1;
	
//	for(int i=1; i<=m; ++i) if(fa[i] == i)
//	{
//		if(fres[i] == 1)
//			printf("fin: u = %d, v = %d, w = %d\n",fu[i],fv[i],ew[i]);
//		else
//			printf("fin: u = %d, v = %d, w = %d\n",fv[i],fu[i],ew[i]);
//	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		ans += g[i][1].size();
	
	printf("%d\n",ans);
	for(int i=1; i<=m; ++i)
	{
		bool t = get_rev(i);
		int u = find(i);
		putchar(((fres[u]-1) ^ t) + 1 + '0');
	}
	return 0;
}