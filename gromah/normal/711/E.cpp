#include <cstdio>
typedef long long LL;
#define Mod 1000003

int fz = 1, fm, Deg[Mod];
LL n, k;

inline int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1) res = (LL) res * u % Mod;
		u = (LL) u * u % Mod;
	}
	return res;
}

inline int Calc(LL u, LL v)
{
	if (v == 1) return u % (Mod - 1);
	int tmp = (v + 1) / 2 % (Mod - 1);
	int _tmp = Calc(u - 1, (v + 1) / 2);
	int res = tmp + _tmp;
	if (res >= Mod - 1) res -= Mod - 1;
	return res;
}

int main()
{
	scanf("%I64d%I64d", &n, &k);
	bool ok = 1;
	for (LL i = 1, m = 2; i <= n && ok; i ++, m <<= 1)
		ok = m < k;
	if (ok) puts("1 1");
	else
	{
		int r = Power(2, n % (Mod - 1));
		int cnt = Calc(n, k);
		if (r < k)
		{
			fz = fm = (LL) Power(r, k % (Mod - 1)) * Power(2, Mod - 1 - cnt) % Mod;
			printf("%d %d\n", fz, fm);
		}
		else
		{
			for (int i = 1; i < Mod; i ++)
				Deg[i] = i & 1 ? 0 : Deg[i >> 1] + 1;
			for (int i = 1; i < k; i ++)
				fz = (LL) fz * (r - i + Mod) % Mod * Power(2, Mod - 1 - Deg[i]) % Mod;
			fm = (LL) Power(r, k % (Mod - 1)) * Power(2, Mod - 1 - cnt) % Mod;
			fz = fm - fz;
			if (fz < 0) fz += Mod;
			printf("%d %d\n", fz, fm);
		}
	}
	return 0;
}