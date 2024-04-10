#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define Mod 998244353

int n, ans, F[N][N], G[N][N];
char s[N];

inline int Inc(int u, int v)
{
	return u >= Mod - v ? u - (Mod - v) : u + v;
}

void Prepare()
{
	F[0][0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		if (s[i] == '(' || s[i] == '?')
			for (int j = 1; j <= n; j ++)
				F[i][j] = Inc(F[i][j], F[i - 1][j - 1]);
		if (s[i] == ')' || s[i] == '?')
			for (int j = 0; j < n; j ++)
				F[i][j] = Inc(F[i][j], F[i - 1][j]);
	}
	G[n + 1][0] = 1;
	for (int i = n; i; i --)
	{
		if (s[i] == ')' || s[i] == '?')
			for (int j = 1; j <= n; j ++)
				G[i][j] = Inc(G[i][j], G[i + 1][j - 1]);
		if (s[i] == '(' || s[i] == '?')
			for (int j = 0; j < n; j ++)
				G[i][j] = Inc(G[i][j], G[i + 1][j]);
	}
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	Prepare();
	for (int c = 1; c * 2 <= n; c ++)
		for (int i = c; i + c <= n; i ++)
			ans = (1LL * F[i][c] * G[i + 1][c] % Mod * c + ans) % Mod;
	printf("%d\n", ans);
	return 0;
}