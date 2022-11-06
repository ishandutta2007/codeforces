#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define INF 1234567890987654321LL

int n, A[N];
LL Dp[N][3], Max[N][2];
vector <int> Vec[N];

inline void Update(int id, LL x)
{
	if (x > Max[id][1])
	{
		if (x > Max[id][0])
			Max[id][1] = Max[id][0], Max[id][0] = x;
		else Max[id][1] = x;
	}
}

inline void dfs(int z, int fa)
{
	Max[z][0] = Max[z][1] = -INF;
	Dp[z][0] = Dp[z][1] = -INF;
	Dp[z][2] = A[z];
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == fa) continue ;
		dfs(d, z);
		Dp[z][2] += Dp[d][2];
		Dp[z][1] = max(Dp[z][1], Dp[d][1]);
		Dp[z][0] = max(Dp[z][0], Dp[d][0]);
		Update(z, Dp[d][1]);
	}
	Dp[z][1] = max(Dp[z][1], Dp[z][2]);
	if (Max[z][1] > -INF)
		Dp[z][0] = max(Dp[z][0], Max[z][0] + Max[z][1]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(1, 0);
	if (Dp[1][0] > -INF)
		printf("%I64d\n", Dp[1][0]);
	else puts("Impossible");
	return 0;
}