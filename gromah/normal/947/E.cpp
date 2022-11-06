#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 262144 + 5
#define Mod 998244353
#define g 3

int n, len, d, Inv[N], Inv_pow[N], Fac[N], A[M], B[M], T[M], e[2][M], Rev[M], q[N];
LL m;

int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1) res = 1LL * res * u % Mod;
		u = 1LL * u * u % Mod;
	}
	return res;
}

void Prepare()
{
	Fac[0] = Inv[0] = Inv[1] = 1;
	for (int i = 1; i <= n; i ++)
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
	for (int i = 2; i <= n + 1; i ++)
		Inv[i] = Mod - (1LL * Inv[Mod % i] * (Mod / i) % Mod);
		
	Inv_pow[1] = 1;
	for (int i = 2; i <= n + 1; i ++)
	{
		if (!Inv_pow[i])
		{
			Inv_pow[i] = Power(Inv[i], m % (Mod - 1));
			q[++ q[0]] = i;
		}
		for (int j = 1; j <= q[0] && i * q[j] <= n + 1; j ++)
		{
			Inv_pow[i * q[j]] = 1LL * Inv_pow[i] * Inv_pow[q[j]] % Mod;
			if (i % q[j] == 0) break ;
		}
	}
	
	for (int i = 2; i <= n + 1; i ++)
		Inv[i] = 1LL * Inv[i - 1] * Inv[i] % Mod;
		
	for (len = n << 1 | 1; len != (len & -len); len += (len & -len)) ;
	for (int i = len; i > 1; i >>= 1) d ++;
	for (int i = 0, w = Power(g, (Mod - 1) / len); i < len; i ++)
	{
		if (!i) e[0][i] = e[1][i] = 1;
		else e[0][i] = e[1][len - i] = 1LL * e[0][i - 1] * w % Mod;
		Rev[i] = 0;
		for (int j = 0; j < d; j ++)
			if (i >> j & 1)
				Rev[i] |= (1 << d - j - 1);
	}
}

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

void FFT(int *p, int op)
{
	for (int i = 0; i < len; i ++)
		if (Rev[i] > i) swap(p[i], p[Rev[i]]);
	for (int k = 1, s = 1; k < len; k <<= 1, s ++)
		for (int i = 0; i < len; i ++)
		{
			if (i & k) continue ;
			int t = e[op][(i & k - 1) << d - s];
			int u = p[i], v = 1LL * p[i | k] * t % Mod;
			p[i] = Inc(u, v);
			p[i | k] = Inc(u, Mod - v);
		}
}

void Convol(int *u, int *v)
{
	FFT(u, 0), FFT(v, 0);
	for (int i = 0; i < len; i ++)
		u[i] = 1LL * u[i] * v[i] % Mod;
	FFT(u, 1);
	for (int i = 0, Inv_len = Power(len, Mod - 2); i < len; i ++)
		u[i] = 1LL * u[i] * Inv_len % Mod;
}

void Handle()
{
	for (int i = 0; i <= n; i ++)
		A[i] = 1LL * A[i] * Fac[i] % Mod, B[i] = Inv[i];
	reverse(A, A + n + 1);
	Convol(A, B);
	reverse(A, A + n + 1);
	for (int i = 0; i <= n; i ++)
		A[i] = 1LL * A[i] * Inv[i] % Mod;
	for (int i = n + 1; i < len; i ++)
		A[i] = 0;
		
		
	for (int i = 0; i <= n; i ++)
		A[i] = 1LL * A[i] * Inv_pow[i + 1] % Mod;
		
	for (int i = 0; i < len; i ++)
		B[i] = 0;
	for (int i = 0; i <= n; i ++)
		A[i] = 1LL * A[i] * Fac[i] % Mod * (i & 1 ? Mod - 1 : 1) % Mod, B[i] = Inv[i];
	reverse(A, A + n + 1);
	Convol(A, B);
	reverse(A, A + n + 1);
	for (int i = 0; i <= n; i ++)
		A[i] = 1LL * A[i] * Inv[i] % Mod * (i & 1 ? Mod - 1 : 1) % Mod;
}

int main()
{
	scanf("%d%lld", &n, &m);
	Prepare();
	for (int i = 0; i <= n; i ++)
		scanf("%d", A + i);
	Handle();
	for (int i = 0; i <= n; i ++)
		printf("%d%c", A[i], i == n ? '\n' : ' ');
	return 0;
}