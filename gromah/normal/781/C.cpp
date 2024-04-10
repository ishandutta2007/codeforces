#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, m, k, depth, Fa[N], T[N << 1], A[N << 1];
vector <int> Vec[N];

inline int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

void dfs(int z, int fa)
{
	T[++ depth] = z;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == fa) continue ;
		dfs(d, z);
		T[++ depth] = z;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
		Fa[i] = i;
	for (int i = 1, x, y; i <= m; i ++)
	{
		scanf("%d%d", &x, &y);
		int u = Find(x), v = Find(y);
		if (u == v) continue ;
		Fa[u] = v;
		Vec[x].push_back(y);
		Vec[y].push_back(x);
	}
	dfs(1, 0);
	int lim = (2 * n + k - 1) / k;
	for (int i = 1, t = 1; i <= k; i ++)
	{
		A[0] = 0;
		for (int j = 1; j <= lim && t <= depth; j ++, t ++)
			A[++ A[0]] = T[t];
		if (!A[0]) A[++ A[0]] = 1;
		for (int j = 0; j <= A[0]; j ++)
			printf("%d%c", A[j], j == A[0] ? '\n' : ' ');
	}
	return 0;
}