#include <cstdio>
#include <algorithm>
using namespace std;
#define N 30 + 5

int m, n;
bool Flag[N];

void Solve(int dep, int l, int r)
{
	int mid = l + r >> 1, res;
	printf("%d\n", mid);
	fflush(stdout);
	scanf("%d", &res);
	if (res == 0) exit(0);
	if ((res == -1 && Flag[dep]) || (res == 1 && !Flag[dep]))
		Solve(dep + 1, l, mid - 1);
	else Solve(dep + 1, mid + 1, r);
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1, res; i <= n; i ++)
	{
		puts("1");
		fflush(stdout);
		scanf("%d", &res);
		if (res == 0) return 0;
		Flag[i] = (res == 1);
	}
	for (int i = n + 1; i < N; i ++)
		Flag[i] = Flag[i - n];
	Solve(1, 1, m);
	return 0;
}