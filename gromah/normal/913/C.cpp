#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 30 + 5
#define LIM (1 << 30)

int n, m;
LL ans, A[N];

LL Calc(LL x)
{
	LL res = 0;
	for (int i = 0; i <= 30; i ++)
		if (x >> i & 1)
			res += A[i];
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
	{
		scanf("%lld", A + i);
		if (i) A[i] = min(A[i], A[i - 1] << 1);
	}
	for (int i = n; i <= 30; i ++)
		A[i] = A[i - 1] << 1;
	ans = Calc(LIM);
	do
	{
		ans = min(ans, Calc(m));
		m += (m & -m);
	} while (m < LIM);
	printf("%lld\n", ans);
	return 0;
}