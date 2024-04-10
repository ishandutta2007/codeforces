#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, m, k, ret, Max, tot, A[N], Col[N], Size[N];
vector <int> Vec[N];

inline void dfs(int z, int col)
{
	if (Col[z] == col) return ;
	Col[z] = col, Size[col] ++, ret --;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		dfs(d, col);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i ++)
		scanf("%d", A + i);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	ret = n;
	for (int i = 1; i <= k; i ++)
	{
		dfs(A[i], i);
		if (!Max || Size[Max] < Size[i]) Max = i;
	}
	Size[Max] += ret;
	for (int i = 1; i <= k; i ++)
		tot += Size[i] * (Size[i] - 1) / 2;
	printf("%d\n", tot - m);
	return 0;
}