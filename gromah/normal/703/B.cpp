#include <cstdio>
typedef long long LL;
#define N 100000 + 5

int n, m, W[N];
bool Flag[N];
LL sum_1, sum_2, ans;

inline int Pre(int x) {return x == 1 ? n : x - 1;}
inline int Next(int x) {return x == n ? 1 : x + 1;}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", W + i);
		sum_1 += W[i];
	}
	for (int i = 1, u; i <= m; i ++)
	{
		scanf("%d", &u);
		Flag[u] = 1;
		sum_2 += W[u];
	}
	for (int i = 1; i <= n; i ++)
	{
		if (Flag[i]) ans += W[i] * (sum_1 - W[i]);
		else
		{
			ans += W[i] * sum_2;
			if (!Flag[Pre(i)]) ans += W[i] * W[Pre(i)];
			if (!Flag[Next(i)]) ans += W[i] * W[Next(i)];
		}
	}
	ans /= 2;
	printf("%I64d\n", ans);
	return 0;
}