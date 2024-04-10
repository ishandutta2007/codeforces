#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, Max, Col[N], Dp[N][2][2];
vector <int> Vec[N];

inline void dfs(int z, int fa)
{
	Dp[z][0][0] = Dp[z][0][1] = Dp[z][1][0] = 0;
	Dp[z][1][1] = 1;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == fa) continue ;
		dfs(d, z);
		if (Col[d] != Col[z])
		{
			int Min = n;
			Min = min(Min, (Dp[z][1][0] >> 1) + (Dp[d][1][1] + 1 >> 1));
			Min = min(Min, (Dp[z][1][1] + 1 >> 1) + (Dp[d][1][0] >> 1));
			Max = max(Max, Min);
			Dp[z][0][0] = max(Dp[d][1][1], Dp[z][0][0]);
			Dp[z][0][1] = max(Dp[d][1][0], Dp[z][0][1]);
			Dp[z][1][0] = max(Dp[d][1][1] + 1, Dp[z][1][0]);
			Dp[z][1][1] = max(Dp[d][1][0] + 1, Dp[z][1][1]);
		}
		else
		{
			int Min = n;
			Min = min(Min, (Dp[z][1][0] >> 1) + (Dp[d][0][0] + 1 >> 1));
			Min = min(Min, (Dp[z][1][1] + 1 >> 1) + (Dp[d][0][1] >> 1));
			Max = max(Max, Min);
			for (int u = 0; u < 2; u ++)
				for (int v = 0; v < 2; v ++)
					Dp[z][u][v] = max(Dp[z][u][v], Dp[d][u][v]);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", Col + i);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", Max);
	return 0;
}