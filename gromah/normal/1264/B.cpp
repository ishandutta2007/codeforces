#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 400000 + 5

int n, sum, C[4], A[N];
bool ok;

void dfs(int z)
{
	if (!C[z]) return ;
	A[++ n] = z, C[z] --;
	if (z == 0)
		dfs(1);
	else if (z == 1)
		dfs(C[0] ? 0 : 2);
	else if (z == 2)
		dfs(C[3] ? 3 : 1);
	else dfs(2);
}

int main()
{
	for (int i = 0; i < 4; i ++)
		scanf("%d", C + i);
	sum = C[0] + C[1] + C[2] + C[3];
	if (abs((C[0] + C[2]) - (C[1] + C[3])) > 1)
	{
		puts("NO");
		return 0;
	}
	if (C[0] + C[2] > C[1] + C[3])
		dfs(C[0] == 0 ? 2 : 0);
	else dfs(C[3] == 0 ? 1 : 3);
	if (n != sum)
		puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i ++)
			printf("%d%c", A[i], i == n ? '\n' : ' ');
	}
	return 0;
}