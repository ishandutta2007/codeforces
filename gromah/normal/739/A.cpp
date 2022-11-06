#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, Min;

int main()
{
	scanf("%d%d", &n, &m);
	Min = n;
	for (int i = 1, l, r; i <= m; i ++)
	{
		scanf("%d%d", &l, &r);
		Min = min(Min, r - l + 1);
	}
	printf("%d\n", Min);
	for (int i = 1, s = 0; i <= n; i ++, s = s == Min - 1 ? 0 : s + 1)
		printf("%d%c", s, i == n ? '\n' : ' ');
	return 0;
}