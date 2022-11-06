#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 4000 + 5
#define M 20000 + 5
#define INF 0x7fffffff

int n, p, q, Max, _Max, C[N], W[N], A[N], Dp[21][N], Max_Dp[21][N], T[M], B[M], Ans[M], Done[N];
vector <int> Map[M];

inline void Solve(int depth, int l, int r)
{
	for (int i = 1; i <= n; i ++)
		if (!Done[i] && A[i] <= l && A[i] + p > r)
		{
			Done[i] = depth;
			for (int j = _Max; j >= C[i]; j --)
				Dp[depth][j] = max(Dp[depth][j], Dp[depth][j - C[i]] + W[i]);
		}
	for (int i = 0; i <= _Max; i ++)
		Max_Dp[depth][i] = i == 0 ? Dp[depth][i] : max(Dp[depth][i], Max_Dp[depth][i - 1]);
	if (l == r)
	{
		for (int i = 0; i < Map[l].size(); i ++)
			Ans[Map[l][i]] = Max_Dp[depth][B[Map[l][i]]];
		for (int i = 1; i <= n; i ++)
			if (Done[i] == depth) Done[i] = 0;
		return ;
	}
	int mid = l + r >> 1;
	for (int i = 0; i <= _Max; i ++)
		Dp[depth + 1][i] = Dp[depth][i];
	Solve(depth + 1, l, mid);
	for (int i = 0; i <= _Max; i ++)
		Dp[depth + 1][i] = Dp[depth][i];
	Solve(depth + 1, mid + 1, r);
	for (int i = 1; i <= n; i ++)
		if (Done[i] == depth) Done[i] = 0;
}

int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d%d", C + i, W + i, A + i);
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++)
	{
		scanf("%d%d", T + i, B + i);
		Max = max(Max, T[i]);
		_Max = max(_Max, B[i]);
		Map[T[i]].push_back(i);
	}
	for (int i = 1; i < _Max; i ++)
		Dp[0][i] = -INF;
	Solve(0, 1, Max);
	for (int i = 1; i <= q; i ++)
		printf("%d\n", Ans[i]);
	
	return 0;
}