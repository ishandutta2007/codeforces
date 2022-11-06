#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 14
#define M 16

int k, t, mx, Ans[N], T[M];
bool ok = 0;
LL Fac[N], Dp[N][M + 1];

inline LL Calc(int dep)
{
	memset(Dp, 0, sizeof(Dp));
	Dp[0][0] = Fac[dep];
	for (int d = 0; d < M; d ++)
		for (int i = 0; i <= dep; i ++)
		{
			if (!Dp[i][d]) continue ;
			for (int j = 0; j <= t - T[d] && i + j <= dep; j ++)
				Dp[i + j][d + 1] += Dp[i][d] / Fac[j];
		}
	return Dp[dep][M];
}

inline void dfs(int dep, int cur)
{
	if (dep <= 0) return ;
	T[cur] ++;
	LL res = Calc(dep - 1);
	if (!ok && res < k)
	{
		k -= res;
		T[cur] --;
		if (cur == 15) dfs(dep + 1, 1);
		else dfs(dep, cur + 1);
	}
	else if (!ok)
	{
		mx = dep, ok = 1;
		Ans[dep] = cur;
		dfs(dep - 1, 0);
	}
	else if (res < k)
	{
		k -= res;
		T[cur] --;
		dfs(dep, cur + 1);
	}
	else
	{
		Ans[dep] = cur;
		dfs(dep - 1, 0);
	}
}

inline char Trans(int x)
{
	if (x < 10) return x + '0';
	else return x - 10 + 'a';
}

int main()
{
	Fac[0] = 1;
	for (int i = 1; i < N; i ++)
		Fac[i] = Fac[i - 1] * i;
	scanf("%d%d", &k, &t);
	dfs(1, 1);
	for (int i = mx; i; i --)
		printf("%c", Trans(Ans[i]));
	puts("");
	return 0;
}