#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100
#define K 10000 + 5
#define Mod 1000000007

LL n, P[N];
int k, sz, ans = 1, Q[N], Inv[K], Dp[N], T[N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

void Prepare()
{
	for (int i = 2; 1LL * i * i <= n; i ++)
		if (n % i == 0)
		{
			P[++ sz] = i;
			for (; n % i == 0; n /= i)
				Q[sz] ++;
		}
	if (n > 1)
		P[++ sz] = n, Q[sz] = 1;

	Inv[0] = Inv[1] = 1;
	for (int i = 2; i < K; i ++)
		Inv[i] = Mod - (1LL * Inv[Mod % i] * (Mod / i) % Mod);
}

int DP(LL p, int q)
{
	for (int i = 0; i <= q; i ++)
		Dp[i] = T[i] = 0;
	Dp[q] = 1;
	for (int t = 1; t <= k; t ++)
	{
		for (int i = 0; i <= q; i ++)
			T[i] = Inc(T[i], 1LL * Dp[i] * Inv[i + 1] % Mod);
		for (int i = q; i >= 0; i --)
		{
			Dp[i] = Inc(T[i], i == q ? 0 : Dp[i + 1]);
			T[i] = 0;
		}
	}
	int res = 0;
	T[0] = 1;
	for (int i = 1; i <= q; i ++)
		T[i] = 1LL * T[i - 1] * (p % Mod) % Mod;
	for (int i = 0; i <= q; i ++)
		res = Inc(res, 1LL * T[i] * Dp[i] % Mod);
	return res;
}

int main()
{
	scanf("%lld%d", &n, &k);
	Prepare();
	for (int i = 1; i <= sz; i ++)
		ans = 1LL * ans * DP(P[i], Q[i]) % Mod;
	printf("%d\n", ans);
	return 0;
}