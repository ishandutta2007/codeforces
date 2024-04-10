#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 10000000 + 5
#define eps 1e-5

int n, m, sz, q, A[N], Phi[N];

int Get_Phi(int x)
{
	int res = 1;
	for (int i = 2; i * i <= x; i ++)
		if (x % i == 0)
		{
			res *= i - 1, x /= i;
			for (; x % i == 0; x /= i) res *= i;
		}
	if (x > 1) res *= x - 1;
	return res;
}

bool Check(int u, int v, int p)
{
	if (v * log(u) > log(p) + eps) return 1;
	LL res = 1, x = u;
	for (; v; v >>= 1)
	{
		if (v & 1) res = res * x;
		x = x * x;
	}
	return res >= p;
}

int Power(int u, int v, int p, bool &exceed)
{
	exceed = Check(u, v, p);
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1) res = 1LL * res * u % p;
		u = 1LL * u * u % p;
	}
	return res;
}

int Solve(int l, int r, int id)
{
	if (l == r || A[l] == 1 || Phi[id] == 1) return l;
	return Solve(l + 1, r, id + 1);
}

int main()
{
	scanf("%d%d", &n, &m);
	Phi[1] = m;
	for (sz = 1; Phi[sz] > 1; sz ++)
		Phi[sz + 1] = Get_Phi(Phi[sz]);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (scanf("%d", &q); q; q --)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int lim = Solve(l, r, 1);
		int ans = A[lim];
		bool exceed = A[lim] >= Phi[lim - l + 1];
		for (int i = lim - 1, id = lim - l + 1; i >= l; i --, id --)
			ans = Power(A[i], ans % Phi[id] + exceed * Phi[id], Phi[id - 1], exceed);
		printf("%d\n", ans % m);
	}
	return 0;
}