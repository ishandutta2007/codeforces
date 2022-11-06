#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define Mod 1000000007

int n, Map[N][N], X[N][N], _X[N][N], Y[N];

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

void Gauss(int st, int x)
{
	int k = st - 1;
	for (int i = st; i <= x; i ++)
	{
		int j = k + 1;
		for (; j <= x; j ++)
			if (X[j][i]) break ;
		if (j > x) continue ;
		k ++;
		if (k != j)
		{
			for (int l = st; l <= x; l ++)
				swap(X[k][l], X[j][l]);
			if (!st) swap(Y[k], Y[j]);
		}
		int inv = Power(X[k][i], Mod - 2);
		for (j = k + 1; j <= x; j ++)
		{
			int del = 1LL * inv * X[j][i] % Mod;
			for (int l = st; l <= x; l ++)
				X[j][l] = (X[j][l] + Mod - 1LL * del * X[k][l] % Mod) % Mod;
			if (!st) Y[j] = (Y[j] + Mod - 1LL * del * Y[k] % Mod) % Mod;
		}
	}
}

int MatrixTree(int w)
{
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			X[i][j] = (i == j ? 0 : (Map[i][j] ? (Mod - w) % Mod : Mod - 1));
	for (int i = 1; i <= n; i ++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j ++)
			if (j != i) sum = (sum + Mod - X[i][j]) % Mod;
		X[i][i] = sum;
	}
	Gauss(1, n - 1);
	int res = 1;
	for (int i = 1; i < n; i ++)
		res = 1LL * res * X[i][i] % Mod;
	return res;
}

void Solve()
{
	for (int i = n - 1; ~i; i --)
	{
		int pre = 0;
		for (int j = i + 1; j < n; j ++)
			pre = (pre + 1LL * X[i][j] * Y[j] % Mod) % Mod;
		Y[i] = 1LL * (Y[i] + Mod - pre) * Power(X[i][i], Mod - 2) % Mod;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Map[u][v] = Map[v][u] = 1;
	}
	for (int w = 0; w < n; w ++)
		for (int i = 0, x = 1; i < n; i ++, x = 1LL * x * w % Mod)
			_X[w][i] = x;
	for (int i = 0; i < n; i ++)
		Y[i] = MatrixTree(i);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			X[i][j] = _X[i][j];
	Gauss(0, n - 1);
	Solve();
	for (int i = 0; i < n; i ++)
		printf("%d%c", Y[i], i == n ? '\n' : ' ');
	return 0;
}