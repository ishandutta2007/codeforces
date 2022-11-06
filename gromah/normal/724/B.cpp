#include <cstdio>
#include <algorithm>
using namespace std;
#define N 20 + 5

int n, m, A[N][N];

inline bool Solve(int x, int y)
{
	bool ok = 1;
	for (int i = 1; ok && i <= n; i ++)
	{
		int cnt = 0;
		for (int j = 1; cnt <= 2 && j <= m; j ++)
		{
			if (j == x)
				cnt += (A[i][j] != y);
			else if (j == y)
				cnt += (A[i][j] != x);
			else cnt += (A[i][j] != j);
		}
		ok = (cnt <= 2);
	}
	return ok;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", A[i] + j);
	if (Solve(1, 1)) puts("YES");
	else
	{
		bool ok = 0;
		for (int i = 1; !ok && i < m; i ++)
			for (int j = i + 1; !ok && j <= m; j ++)
				ok = Solve(i, j);
		if (ok) puts("YES");
			else puts("NO");
	}
	return 0;
}