#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define Mod 1000000007

int n, ans = 1, Miu[N], q[N];
bool Flag[N];

void Prepare()
{
	Miu[1] = 1;
	for (int i = 2; i <= n; i ++)
	{
		if (!Flag[i])
			Miu[i] = -1, q[++ q[0]] = i;
		for (int j = 1; j <= q[0] && i * q[j] <= n; j ++)
		{
			Flag[i * q[j]] = 1;
			if (i % q[j] == 0)
			{
				Miu[i * q[j]] = 0;
				break ;
			}
			Miu[i * q[j]] = -Miu[i];
		}
	}
}

inline Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1)
			res = 1LL * res * u % Mod;
		u = 1LL * u * u % Mod;
	}
	return res;
}

inline int Calc(int x)
{
	return 1LL * x * Power(Mod + 1 - x, Mod - 2) % Mod;
}

int main()
{
	scanf("%d", &n);
	Prepare();
	for (int i = 2, inv_n = Power(n, Mod - 2); i <= n; i ++)
		ans = (ans + 1LL * Calc(1LL * (n / i) * inv_n % Mod) * (Mod - Miu[i])) % Mod;
	printf("%d\n", ans);
	return 0;
}