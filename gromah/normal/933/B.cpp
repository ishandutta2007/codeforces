#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 2000 + 5

int k, d;
LL p, B[N], A[N];

LL Divide(LL x, int d)
{
	if (x > 0) return x / d;
	else return (x - d + 1) / d;
}

int main()
{
	scanf("%I64d%d", &p, &k);
	for (int i = 0; ; i ++)
	{
		B[i] = -Divide(i ? B[i - 1] : p, k);
		if (B[i] == 0)
		{
			A[0] += p;
			for (int j = 0; j <= i; j ++)
			{
				A[j] += k * B[j];
				A[j + 1] += B[j];
			}
			d = i;
			break ;
		}
	}
	printf("%d\n", d + 1);
	for (int i = 0; i <= d; i ++)
		printf("%lld%c", A[i], i == d ? '\n' : ' ');
	return 0;
}