#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5

int n, m, j;
LL d, st, A[N], P[N];
bool ok = false;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", A + i);
	for (int i = 1; i < n; i ++)
		d = __gcd(d, A[i + 1] - A[i]);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%lld", P + i);
		if (d % P[i] == 0)
		{
			ok = true;
			st = A[1], j = i;
		}
	}
	if (ok)
	{
		puts("YES");
		printf("%lld %d\n", st, j);
	}
	else puts("NO");
	return 0;
}