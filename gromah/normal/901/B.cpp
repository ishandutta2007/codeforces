#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 150 + 5

int n, Map[N][N], T[N];

int main()
{
	Map[0][0] = 1, Map[1][1] = 1;
	for (int i = 2; i < N; i ++)
	{
		T[0] = 0;
		for (int j = 1; j <= i; j ++)
			T[j] = Map[i - 1][j - 1];
		bool ok = 1;
		for (int j = 0; j < i - 1; j ++)
			T[j] += Map[i - 2][j];
		for (int j = 0; j <= i; j ++)
			ok &= (abs(T[j]) <= 1);
		if (!ok) for (int j = 0; j < i - 1; j ++)
			T[j] -= 2 * Map[i - 2][j];
		for (int j = 0; j <= i; j ++)
			Map[i][j] = T[j];
	}
	scanf("%d", &n);
	printf("%d\n", n);
	for (int j = 0; j <= n; j ++)
		printf("%d%c", Map[n][j], j == n ? '\n' : ' ');
	n --;
	printf("%d\n", n);
	for (int j = 0; j <= n; j ++)
		printf("%d%c", Map[n][j], j == n ? '\n' : ' ');
	return 0;
}