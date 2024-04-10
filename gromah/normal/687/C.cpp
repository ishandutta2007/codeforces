#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500 + 5

int n, k, cnt, A[N], _A[N], Flag[N][N], W[N], X[N];
bool Ok[N];

inline bool cmp(int u, int v)
{
	return W[u] < W[v];
}

inline void dfs(int id, int val)
{
	if (Flag[id][val] || id == n) return ;
	Flag[id][val] = -1;
	dfs(id + 1, val);
	if (Flag[id + 1][val] == 1) Flag[id][val] = 1;
	if (val + A[id + 1] <= k)
	{
		dfs(id + 1, val + A[id + 1]);
		if (Flag[id + 1][val + A[id + 1]] == 1) Flag[id][val] = 1, Ok[A[id + 1]] = 1;
	}
	if (Flag[id][val] == 1) Ok[val] = 1;
}

int main()
{
	srand(593119681);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		X[i] = i, _A[i] = A[i];
	}
	for (int T = 1; T <= 800; T ++)
	{
		for (int i = 1; i <= n; i ++)
			W[i] = rand();
		sort(X + 1, X + n + 1, cmp);
		for (int i = 1; i <= n; i ++)
			A[i] = _A[X[i]];
		for (int i = 0; i < n; i ++)
			for (int j = 0; j <= k; j ++)
				Flag[i][j] = 0; 
		for (int i = 0; i < k; i ++)
			Flag[n][i] = -1; 
		Flag[n][k] = 1;
		dfs(0, 0);
	}
	for (int i = 0; i <= k; i ++)
		cnt += Ok[i];
	printf("%d\n", cnt); 
	for (int i = 0; i <= k; i ++)
		if  (Ok[i]) printf("%d ", i);
	puts("");
	return 0;
}