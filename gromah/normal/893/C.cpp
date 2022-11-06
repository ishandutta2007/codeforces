#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define INF 1234567890

int n, m, W[N];
LL ans;
vector <int> Vec[N];

int dfs(int z)
{
	if (!~W[z]) return INF;
	int res = W[z];
	W[z] = -1;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		res = min(res, dfs(d));
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", W + i);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++)
		if (~W[i]) ans += dfs(i);
	printf("%lld\n", ans);
	return 0;
}