#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int mod = 998244353;

vector<int> g[MAXN];

int anc[MAXN], dfnl[MAXN], dfnr[MAXN], cur_dfn = 0;
void dfs_dfn(int u,int fa)
{
	anc[u] = fa;
	dfnl[u] = ++cur_dfn;
	for(int v: g[u]) if(v != fa)
		dfs_dfn(v, u);
	dfnr[u] = cur_dfn;
}

int clr[MAXN];

int f[MAXN][2];
void dfs_f(int u,int fa)
{
	f[u][clr[u] != 0] = 1;
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v, u);
		
		int nf[2] = {0,0};
		for(int i=0; i<=1; ++i)
			for(int j=0; j<=1; ++j)
			{
				if(j)
					nf[i] = (nf[i] + (ll)f[u][i] * f[v][j]) %mod;
				if(i+j <= 1)
					nf[i+j] = (nf[i+j] + (ll)f[u][i] * f[v][j]) %mod;
			}
		f[u][0] = nf[0]; f[u][1] = nf[1];
	}
}

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&clr[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dfs_dfn(1,0);
	
	static int cmn[MAXN], cmx[MAXN];
	memset(cmn, 0x3f, sizeof(cmn));
	for(int i=1; i<=n; ++i) if(clr[i])
		cmn[clr[i]] = min(cmn[clr[i]], dfnl[i]),
		cmx[clr[i]] = max(cmx[clr[i]], dfnl[i]);
	
	for(int i=1; i<=n; ++i)
	{
		int u = i, k = clr[i];
		auto chk = [&] (void){ return dfnl[u] <= cmn[k] && cmx[k] <= dfnr[u];};
		while(!chk())
		{
			u = anc[u];
			if(clr[u])
			{
				if(clr[u] != k)
				{
					printf("0");
					return 0;
				}
				break;
			}
			clr[u] = k;
		}
	}
	
	dfs_f(1,0);
	
	printf("%d",f[1][1]);
	return 0;
}