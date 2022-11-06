#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define Mod 1000000007

int n, k, ans, Fa[N], Size[N];

int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

inline int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1)
			res = 1LL * res * u % Mod;
		u = 1LL * u * u % Mod;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		Fa[i] = i, Size[i] = 1;
	for (int i = 1, u, v, c; i < n; i ++)
	{
		scanf("%d%d%d", &u, &v, &c);
		if (c == 0)
		{
			u = Find(u), v = Find(v);
			Fa[u] = v, Size[v] += Size[u], Size[u] = 0;
		}
	}
	ans = Power(n, k);
	for (int i = 1; i <= n; i ++)
		if (Find(i) == i)
			ans = (ans + Mod - Power(Size[i], k)) % Mod;
	printf("%d\n", ans);
	return 0;
}