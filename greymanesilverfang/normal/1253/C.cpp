#include <cstdio>
#include <algorithm>
const int N = 200000;
int a[N]; long long pen[N];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	std::sort(a, a + n);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		printf("%lld ", sum += pen[i % m] += a[i]);
}