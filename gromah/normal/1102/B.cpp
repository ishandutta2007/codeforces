#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, k, A[N], Col[N], Cur[N];
bool Flag[N][N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= k; i ++)
	{
		Col[i] = i - 1;
		Flag[A[i]][i - 1] = 1;
	}
	for (int i = k + 1; i <= n; i ++)
	{
		int &col = Cur[A[i]];
		for (; col < k && Flag[A[i]][col]; col ++) ;
		if (col == k)
		{
			puts("NO");
			return 0;
		}
		Col[i] = col;
		Flag[A[i]][col] = 1;
	}
	puts("YES");
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Col[i] + 1, i == n ? '\n' : ' ');
	return 0;
}