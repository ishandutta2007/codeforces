#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100 + 5

int n, m, x, y;
LL k, Min, Max, tmp;

int main()
{
	scanf("%d%d%I64d%d%d", &n, &m, &k, &x, &y);
	if (n == 1)
		printf("%I64d %I64d %I64d\n", (k + m - 1) / m, k / m, k / m + (y <= (k % m)));
	else if (n == 2)
		printf("%I64d %I64d %I64d\n", (k + n * m - 1) / (n * m), k / (n * m), k / (n * m) + ((x - 1) * m + y <= k % (n * m)));
	else if (k < n * m)
		printf("1 0 %d\n", (x - 1) * m + y <= k);
	else if (k == n * m)
		puts("1 1 1");
	else if (k < (n - 1) * m * 2)
		printf("2 1 %d\n", 1 + (x != 1 && x != n && (n - 1 - x) * m + n * m + y <= k));
	else
	{
		int t = (n - 1) * m << 1;
		LL u = k / t, v = k % t;
		Min = u + (v >= n * m), Max = u * 2 + (v > m) + (v > n * m);
		if (x == 1 || x == n)
			tmp = u + ((x - 1) * m + y <= v);
		else tmp = u * 2 + ((x - 1) * m + y <= v) + (n * m + (n - 1 - x) * m + y <= v);
		printf("%I64d %I64d %I64d\n", Max, Min, tmp);
	}
	return 0;
}