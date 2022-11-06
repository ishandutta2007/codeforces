#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000 + 5
#define M 10000 + 5
#define mp make_pair

int n, tot, X[N][N], T[N], Pow[N];
short Fa[N][M][2], Ad[N][M], Cnt[N][M];
LL k, A[N], B[N], q[N], Dp[N][M];

inline LL gcd(LL x, LL y)
{
	return !y ? x : gcd(y, x % y);
}

inline void Init()
{
	LL _k = k;
	for (LL i = 2; _k > 1 && i * i <= k; i ++)
		if (_k % i == 0)
		{
			q[++ tot] = i;
			for (; _k % i == 0; _k /= i) T[tot] ++;
		}
	if (_k > 1)
	{
		q[++ tot] = _k;
		T[tot] = 1;
	}
	Pow[0] = 1;
	for (int i = 1; i <= tot; i ++)
		Pow[i] = Pow[i - 1] * (T[i] + 1);
}

inline void Handle(int id)
{
	LL x = B[id];
	for (int i = 1; i <= tot; i ++)
		for (; x % q[i] == 0; x /= q[i]) X[id][i] ++;
}

inline int Get(int s, int id)
{
	int res = 0;
	for (int i = 1; i <= tot; i ++)
	{
		int t = s % (T[i] + 1) + X[id][i];
		t = min(t, T[i]);
		s /= (T[i] + 1);
		res += t * Pow[i - 1];
	}
	return res;
}

int main()
{
	scanf("%d%I64d", &n, &k);
	Init();
	for (int i = 1; i <= n; i ++)
	{
		scanf("%I64d", A + i);
		B[i] = gcd(A[i], k);
		Handle(i);
	}
	if (k == 1)
	{
		puts("1");
		int id = 1;
		for (int i = 2; i <= n; i ++)
			if (A[id] > A[i]) id = i;
		printf("%d\n", id);
		return 0;
	}
	for (int j = 0; j < Pow[tot]; j ++)
		Cnt[0][j] = n + 1;
	Cnt[0][0] = 0;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < Pow[tot]; j ++)
		{
			Cnt[i + 1][j] = Cnt[i][j], Dp[i + 1][j] = Dp[i][j];
			Ad[i + 1][j] = Ad[i][j];
		}
		for (int j = 0; j < Pow[tot]; j ++)
		{
			int k = Get(j, i + 1);
			if (mp(1LL * Cnt[i + 1][k], Dp[i + 1][k]) > mp(1LL * Cnt[i][j] + 1, Dp[i][j] + A[i + 1]))
			{
				Cnt[i + 1][k] = Cnt[i][j] + 1, Dp[i + 1][k] = Dp[i][j] + A[i + 1];
				Fa[i + 1][k][0] = Ad[i][j], Fa[i + 1][k][1] = j;
				Ad[i + 1][k] = i + 1;
			}
		}
	}
	int id = 0, sum = Pow[tot] - 1;
	for (int i = 1; i <= n; i ++)
		if (mp(1LL * Cnt[id][sum], Dp[id][sum]) > mp(1LL * Cnt[i][sum], Dp[i][sum])) id = i;
	if (!id) puts("-1");
	else
	{
		printf("%d\n", Cnt[id][sum]);
		int u = id, v = sum;
		while (u && v)
		{
			printf("%d ", u);
			int _u = Fa[u][v][0], _v = Fa[u][v][1];
			u = _u, v = _v;
		}
		puts("");
	}
	return 0;
}