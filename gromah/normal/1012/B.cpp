#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define INF 593119681
#define mp make_pair

int n, m, q, ans, Fa[N << 1];

int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	ans = n + m - 1;
	for (int i = 1; i <= n + m; i ++)
		Fa[i] = i;
	for (int i = 1, r, c; i <= q; i ++)
	{
		scanf("%d%d", &r, &c);
		int u = Find(r), v = Find(n + c);
		if (u != v)
			Fa[u] = v, ans --;
	}
	printf("%d\n", ans);
	return 0;
}