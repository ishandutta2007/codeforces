#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, m, A[N], B[N];
bool ok = 1;
double ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		ok &= (A[i] > 1);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", B + i);
		ok &= (B[i] > 1);
	}
	if (ok)
	{
		ans = m;
		for (int i = n; i; i --)
		{
			ans += 1.0 * ans / (B[i] - 1);
			ans += 1.0 * ans / (A[i] - 1);
		}
		printf("%.9f\n", ans - m);
	}
	else puts("-1");
	return 0;
}