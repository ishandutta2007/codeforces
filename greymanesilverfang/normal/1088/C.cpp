#include <cstdio>
const int N = 2e3+1;
int a[N];

int main()
{
	int n; scanf("%d", &n);
	printf("%d\n", n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i = n; i >= 1; --i)
	{
		int add = n + i - 1 - (a[i] + sum) % n;
		printf("1 %d %d\n", i, add);
		sum += add;
	}
	printf("2 %d %d", n, n);
	return 0;
}