#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

vector<pii> g[MAXN];
int siz[MAXN], val[MAXN], sumval[MAXN];

void dfs_val(int u,int fa,int faw)
{
	siz[u] = 1;
	int save = sumval[faw];
	for(auto it: g[u]) if(it.first != fa)
	{
		int v = it.first, w = it.second;
		dfs_val(v,u,w);
		siz[u] += siz[v];
	}
	val[u] = siz[u] - (sumval[faw] - save);
	sumval[faw] += val[u];
}

ll ans = 0;
int lst[MAXN];
void dfs_ans(int u,int fa)
{
	for(auto it: g[u]) if(it.first != fa)
	{
		int v = it.first, w = it.second;
		ans += (ll)lst[w] * val[v];
		int save = lst[w];
		lst[w] = val[v];
		dfs_ans(v,u);
		lst[w] = save;
	}
}

int main(void)
{
	int n = read();
	for(int i=1; i<n; ++i)
	{
		int u = read(), v = read(), w = read();
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	
	dfs_val(1,0,0);
	for(int i=1; i<=n; ++i)
		lst[i] = n - sumval[i];
	dfs_ans(1,0);
	
	printf("%lld",ans);
	return 0;
}