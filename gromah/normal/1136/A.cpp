#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, k, L[N], R[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", L + i, R + i);
	scanf("%d", &k);
	for (int i = 1; i <= n; i ++)
		if (R[i] >= k)
		{
			printf("%d\n", n - i + 1);
			return 0;
		}
	puts("0");
	return 0;
}