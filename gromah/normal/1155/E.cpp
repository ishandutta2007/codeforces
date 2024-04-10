#include <cstdio>
#include <algorithm>
using namespace std;
#define N 11
#define Mod 1000003

int res = -1, X[N][N], Y[N], Inv[Mod];

int Query(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

void Gauss()
{
	int k = -1;
	for (int i = 0; i < N; i ++)
	{
		int j = k + 1;
		for (; j < N && !X[j][i]; j ++) ;
		if (j == N) continue ;
		swap(Y[j], Y[++ k]);
		for (int l = 0; l < N; l ++)
			swap(X[j][l], X[k][l]);
		for (int r = k + 1; r < N; r ++)
		{
			int div = 1LL * X[r][i] * Inv[X[k][i]] % Mod;
			Y[r] = (Y[r] + Mod - 1LL * Y[k] * div % Mod) % Mod;
			for (int l = i; l < N; l ++)
				X[r][l] = (X[r][l] + Mod - 1LL * X[k][l] * div % Mod) % Mod;
		}
	}
	for (int i = N - 1; i >= 0; i --)
	{
		int sum = 0;
		for (int j = i + 1; j < N; j ++)
			sum = (1LL * X[i][j] * Y[j] + sum) % Mod;
		Y[i] = 1LL * (Y[i] + Mod - sum) * Inv[X[i][i]] % Mod;
	}
}

int Calc(int x)
{
	int res = 0;
	for (int i = 0, m = 1; i < N; i ++, m = 1LL * m * x % Mod)
		res = (1LL * m * Y[i] + res) % Mod;
	return res;
}

int main()
{
	Inv[0] = Inv[1] = 1;
	for (int i = 2; i < Mod; i ++)
		Inv[i] = Mod - (1LL * Inv[Mod % i] * (Mod / i) % Mod);
	for (int i = 0; i < N; i ++)
	{
		for (int j = 0, m = 1; j < N; j ++, m = 1LL * m * i % Mod)
			X[i][j] = m;
		Y[i] = Query(i);
	}
	Gauss();
	for (int i = 0; i < Mod; i ++)
		if (Calc(i) == 0)
		{
			res = i;
			break ;
		}
	printf("! %d\n", res);
	fflush(stdout);
	return 0;
}