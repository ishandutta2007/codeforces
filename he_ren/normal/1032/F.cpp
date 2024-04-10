#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int mod = 998244353;

vector<int> g[MAXN];

int f[MAXN][3];
void dfs_f(int u,int fa)
{
	if(fa) g[u].erase(find(g[u].begin(), g[u].end(), fa));
	f[u][1] = f[u][2] = 1;
	for(int v: g[u])
	{
		dfs_f(v, u);
		f[u][1] = (ll)f[u][1] * (2ll * f[v][0] + f[v][2]) %mod;
		f[u][2] = (ll)f[u][2] * (f[v][0] + f[v][2]) %mod;
	}
	if(!g[u].size()) return;
	
	int tot = (int)g[u].size();
	vector<int> pre(tot), suf(tot);
	pre[0] = suf[tot-1] = 1;
	for(int i=0; i+1<tot; ++i)
	{
		int v = g[u][i];
		pre[i+1] = (ll)pre[i] * (2ll * f[v][0] + f[v][2]) %mod;
	}
	for(int i=tot-1; i>0; --i)
	{
		int v = g[u][i];
		suf[i-1] = (ll)suf[i] * (2ll * f[v][0] + f[v][2]) %mod;
	}
	
	for(int i=0; i<tot; ++i)
	{
		int v = g[u][i];
		f[u][0] = (f[u][0] + (ll)pre[i] * suf[i] %mod * f[v][1]) %mod;
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dfs_f(1,0);
	
	printf("%d",(f[1][0] + f[1][2]) %mod);
	return 0;
}