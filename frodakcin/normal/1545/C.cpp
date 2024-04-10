#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using ll = long long;

const int MOD = 998244353;
const int MN = 500+10;

int N, a[MN*2][MN];
bool vis[MN*2], forced[MN*2];
std::vector<int> adj[MN*2], ans;

bool bad(int u, int v)
{
	for(int i=0;i<N;++i)
		if(a[u][i]==a[v][i])
			return 1;
	return 0;
}

void dfs(int n, bool col=0)
{
	if(col)
		ans.push_back(n);
	vis[n]=1;
	for(int x:adj[n])
		if(!vis[x])
			dfs(x, !col);
}

void solve()
{
	scanf("%d", &N);
	for(int i=0;i<N*2;++i)
		for(int j=0;j<N;++j)
			scanf("%d", a[i]+j), --a[i][j];

	for(int i=0;i<N*2;++i)
		for(int j=i+1;j<N*2;++j)
			if(bad(i, j))
				adj[i].push_back(j), adj[j].push_back(i);

	memset(vis, 0, N*2*sizeof*vis);
	//memset(forced, 0, N*2*sizeof*forced);

	for(bool repeat=1;repeat;)
	{
		repeat=0;
		for(int i=0;i<N;++i)
		{
			std::vector<int> cnt(N, 0);
			for(int j=0;j<N*2;++j)
				if(!vis[j])
					++cnt[a[j][i]];
			for(int j=0;j<N*2;++j)
				if(!vis[j])
					if(cnt[a[j][i]] == 1)
					{
						repeat=1;
						ans.push_back(j);
						vis[j]=1;
						for(int x:adj[j])
							vis[x]=1;
					}
		}
	}
	//printf("test %u\n", ans.size());

	int cc=0;
	for(int i=0;i<N*2;++i)
		if(!vis[i])
			dfs(i, 1), ++cc;

	int ansv=1;
	for(int i=0;i<cc;++i) ansv=ansv*2%MOD;
	printf("%d\n", ansv);
	//printf("%u\n", ans.size());
	assert(ans.size() == N);
	std::sort(ans.begin(), ans.end());
	for(int i=0;i<N;++i)
		printf("%d%c", ans[i]+1, " \n"[i+1==N]);

	for(int i=0;i<N*2;++i)
		adj[i].clear();
	ans.clear();
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}