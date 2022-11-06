#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000000 + 5
#define Mod 1000000007

int Case, n, m, ans, q[N], F[N], A[N], Pow[N], Fac[N], Inv[N];

void Prepare()
{
	F[1] = 1;
	for (int i = 2; i < N; i ++)
	{
		if (!F[i])
			F[i] = q[++ q[0]] = i;
		for (int j = 1; j <= q[0] && i * q[j] < N; j ++)
		{
			F[i * q[j]] = q[j];
			if (i % q[j] == 0) break ;
		}
	}
	Pow[0] = Fac[0] = Fac[1] = Inv[0] = Inv[1] = 1;
	for (int i = 2; i < N; i ++)
	{
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		Inv[i] = Mod - (1LL * (Mod / i) * Inv[Mod % i] % Mod);
	}
	for (int i = 1; i < N; i ++)
	{
		Inv[i] = 1LL * Inv[i - 1] * Inv[i] % Mod;
		Pow[i] = Pow[i - 1] * 2 % Mod;
	}
}

inline int C(int u, int v)
{
	return 1LL * Fac[u] * Inv[v] % Mod * Inv[u - v] % Mod;
}

inline int Calc(int sum, int cnt)
{
	return C(sum + cnt - 1, sum);
}

int main()
{
	Prepare();
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &m);
		A[0] = 0;
		for (int x = n, last = 0; x > 1; x /= F[x])
		{
			if (F[x] != last) A[0] ++;
			A[A[0]] ++, last = F[x];
		}
		ans = Pow[m - 1];
		for (int i = 1; i <= A[0]; i ++)
		{
			ans = 1LL * ans * Calc(A[i], m) % Mod;
			A[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}