#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5
#define Mod 1000000007
 
int n, t, q[N], P[N], Inv[N], Fac[N], F[N];
 
inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}
 
inline int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1, u = 1LL * u * u % Mod)
		if (v & 1)
			res = 1LL * res * u % Mod;
	return res;
}
 
void Prepare()
{
	P[1] = Inv[1] = 1;
	for (int i = 2, _ = t + 1; i <= _; i ++)
	{
		if (!P[i])
			q[++ q[0]] = i, P[i] = Power(i, t);
		for (int j = 1; j <= q[0] && i * q[j] <= _; j ++)
		{
			P[i * q[j]] = 1LL * P[i] * P[q[j]] % Mod;
			if (i % q[j] == 0)
				break ;
		}
		Inv[i] = Mod - 1LL * Inv[Mod % i] * (Mod / i) % Mod;
	}
	for (int i = 1; i <= t + 1; i ++)
		F[i] = Inc(F[i - 1], P[i]);
	Inv[0] = Fac[0] = 1;
	for (int i = 1; i <= t + 1; i ++)
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
	for (int i = 2; i <= t + 1; i ++)
		Inv[i] = 1LL * Inv[i - 1] * Inv[i] % Mod;
}
 
int Calc(int t, int n)
{
	static int V[N], Pre[N], Suf[N];
	V[0] = n;
	for (int i = 1; i <= t + 1; i ++)
		V[i] = Inc(V[i - 1], Mod - 1);
	Pre[0] = V[0], Suf[t + 1] = V[t + 1];
	for (int i = 1; i <= t + 1; i ++)
	{
		Pre[i] = 1LL * Pre[i - 1] * V[i] % Mod;
		Suf[t + 1 - i] = 1LL * Suf[t + 1 - i + 1] * V[t + 1 - i] % Mod;
	}
	int cz = 0;
	for (int i = 0; i <= t + 1; i ++)
	{
		int tmp = 1LL * (i == 0 ? 1 : Pre[i - 1]) * (i == t + 1 ? 1 : Suf[i + 1]) % Mod;
		tmp = 1LL * tmp * F[i] % Mod;
		tmp = 1LL * tmp * Inv[i] % Mod * Inv[t + 1 - i] % Mod;
		if ((t + 1 - i) & 1)
			tmp = Mod - tmp;
		cz = Inc(cz, tmp);
	}
	return cz;
}
 
int main()
{
	scanf("%d%d", &n, &t);
	Prepare();
	printf("%d\n", Calc(t, n));
	return 0;
}