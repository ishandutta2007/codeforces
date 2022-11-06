#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
typedef long double LD;
#define N 10000 + 5

int k, cnt, tot, Pos[N], Rem[N];
bool ok = 1;
LL n, m, lcm, ans, A[N], P[N], q[N], Q[N];

inline LL Inc(LL u, LL v)
{
	return u + v - (u + v >= lcm ? lcm : 0);
}

inline LL Gcd(LL x, LL y)
{
	return !y ? x : Gcd(y, x % y);
}

inline LL Handle()
{
	LL res = 1;
	for (int i = 1; i <= k; i ++)
	{
		LL gcd = Gcd(res, A[i]);
		LD u = log(res), v = log(A[i]), w = log(gcd);
		if (u + v - w > 30.0) return n + 1;
		res = res / gcd * A[i];
	}
	return res;
}

inline void Get(int t)
{
	for (int i = 1; i <= k; i ++)
		if (A[i] % P[t] == 0)
		{
			Pos[t] = i;
			break ;
		}
}

inline LL Multi(LL x, LL y)
{
	LL res = 0;
	for (; y; y >>= 1)
	{
		if (y & 1) res = Inc(res, x);
		x = Inc(x, x);
	}
	return res;
}

inline LL Power(LL x, LL y)
{
	LL res = 1;
	for (; y; y >>= 1)
	{
		if (y & 1) res = Multi(res, x);
		x = Multi(x, x);
	}
	return res;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i ++)
		cin >> A[i];
	lcm = Handle();
	if (lcm > n)
	{
		puts("NO");
		return 0;
	}
	LL x = lcm;
	for (LL i = 2; x > 1 && i * i <= lcm; i ++)
		if (x % i == 0)
		{
			q[++ cnt] = i, Q[cnt] = 1LL;
			for (; x % i == 0; x /= i)
			{
				Q[cnt] *= i;
				P[++ tot] = Q[cnt];
				Get(tot);
			}
		}
	if (x > 1)
	{
		q[++ cnt] = Q[cnt] = P[++ tot] = x;
		Get(tot);
	}
	bool ok = 1;
	for (int i = 1; ok && i <= tot; i ++)
		for (int j = Pos[i] + 1; ok && j <= k; j ++)
			if (((j - Pos[i]) % P[i] == 0) ^ (A[j] % P[i] == 0)) ok = 0;
	if (!ok)
	{
		puts("NO");
		return 0;
	}
	cnt = 0;
	for (int i = 1; i <= tot; i ++)
		if (i == tot || P[i + 1] % P[i] > 0)
			Rem[++ cnt] = (k - Pos[i]) % P[i];
	for (int i = 1; i <= cnt; i ++)
	{
		LL t = Power(lcm / Q[i], Q[i] / q[i] * (q[i] - 1));
		ans = Inc(ans, Multi(Rem[i], t));
	}
	for (int i = 1; i <= k; i ++)
		if (A[i] == lcm) ans += lcm;
	ok = (ans <= m);
	puts(ok ? "YES" : "NO");
	return 0;
}