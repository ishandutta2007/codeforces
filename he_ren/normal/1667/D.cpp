#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

vector<int> g[MAXN];

bool has[MAXN];
int anc[MAXN], dep[MAXN], val[MAXN];
void dfs_tree(int u,int fa)
{
	has[u] = (dep[u] & 1) ^ (g[u].size() & 1);
	val[u] = has[u] - ((g[u].size() & 1) ^ has[u]);
	for(int v: g[u]) if(v != fa)
	{
		anc[v] = u; dep[v] = dep[u] + 1;
		dfs_tree(v,u),
		val[u] += val[v];
	}
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dep[1] = 0;
	dfs_tree(1,0);
	{
		bool ok = val[1] == 0;
		for(int i=1; i<=n && ok; ++i)
			ok &= -1 <= val[i] && val[i] <= 1;
		if(!ok)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	
	static bool del[MAXN], inq[MAXN];
	static vector<int> f[MAXN][2], q;
	
	fill(del+1, del+n+1, 0);
	fill(inq+1, inq+n+1, 1);
	
	del[1] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=1; ++j)
			f[i][j].clear();
	
	for(int i=2; i<=n; ++i)
		f[anc[i]][val[i] == 1].push_back(i);
	q.resize(n);
	iota(q.begin(), q.end(), 1);
	
	auto chk = [&] (int u) -> int
	{
		int t = has[u];
		vector<int> &vec = f[u][!t];
		while(vec.size())
		{
			int v = vec.back();
			if(del[v] || has[v] == has[u]){ vec.pop_back(); continue;}
			return v;
		}
		return 0;
	};
	auto push = [&] (int u)
	{
		if(u && chk(u) && !inq[u]) q.push_back(u), inq[u] = 1;
	};
	
	while(q.size())
	{
		int u = q.back(); q.pop_back(); inq[u] = 0;
		int v = chk(u);
		if(!v) continue;
		del[v] = 1;
		printf("%d %d\n",u,v);
		
		has[u] ^= 1; has[v] ^= 1;
		push(u); push(v);
		if(anc[u] && !del[u])
		{
			f[anc[u]][val[u] == 1].push_back(u);
			push(anc[u]);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}