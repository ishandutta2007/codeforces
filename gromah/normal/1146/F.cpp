#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define Mod 998244353

int n, Dp[N][3];
vector <int> Vec[N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

void dfs(int z)
{
	if (Vec[z].empty())
		Dp[z][0] = Dp[z][1] = 0, Dp[z][2] = 1;
	else
	{
		Dp[z][0] = 1, Dp[z][1] = Dp[z][2] = 0;
		for (int d : Vec[z])
		{
			dfs(d);
			int t0 = Inc(Dp[d][0], Dp[d][2]), t1 = Inc(Dp[d][1], Dp[d][2]);
			Dp[z][2] = Inc(1LL * Dp[z][2] * Inc(t0, t1) % Mod, 1LL * Dp[z][1] * t1 % Mod);
			Dp[z][1] = Inc(1LL * Dp[z][1] * t0 % Mod, 1LL * Dp[z][0] * t1 % Mod);
			Dp[z][0] = 1LL * Dp[z][0] * t0 % Mod;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2, p; i <= n; i ++)
	{
		scanf("%d", &p);
		Vec[p].push_back(i);
	}
	dfs(1);
	printf("%d\n", Inc(Dp[1][0], Dp[1][2]));
	return 0;
}