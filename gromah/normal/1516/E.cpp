#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 400 + 5
#define Mod 1000000007

int n, k, Comb[N][N], Combn[N], Inv[N], Dp[N][N], Ans[N];

inline int Inc(int u, int v)
{
	return u >= Mod - v ? u - (Mod - v) : u + v;
}

inline int C(int u, int v)
{
	if (u < v)
		return 0;
	int ret = 1;
	for (int i = 1; i <= v; i++)
		ret = 1LL * ret * (u - i + 1) % Mod * Inv[i] % Mod;
	return ret;
}

void Prepare()
{
	Inv[0] = Inv[1] = 1;
	for (int i = 2; i < N; i++)
		Inv[i] = Mod - 1LL * Inv[Mod % i] * (Mod / i) % Mod;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			Comb[i][j] = !j ? 1 : Inc(Comb[i - 1][j], Comb[i - 1][j - 1]);
	Dp[0][0] = 1;
	for (int s = 1; s < N; s++)
		for (int i = 1; i * 2 <= s; i++)
			for (int j = 2, c = 1; j + (i - 1) * 2 <= s; j++)
			{
				c = 1LL * c * (s - j + 1) % Mod;
				Dp[s][i] = (1LL * c * Dp[s - j][i - 1] + Dp[s][i]) % Mod;
			}
	for (int i = 0; i < N; i++)
		Combn[i] = C(n, i);
}

int main()
{
	scanf("%d%d", &n, &k);
	Prepare();
	Ans[0] = 1;
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= j; i++)
			Ans[j] = (1LL * Dp[j + i][i] * Combn[j + i] + Ans[j]) % Mod;
	for (int i = 2; i <= k; i++)
		Ans[i] = Inc(Ans[i], Ans[i - 2]);
	for (int i = 1; i <= k; i++)
		printf("%d%c", Ans[i], i == k ? '\n' : ' ');
	return 0;
}