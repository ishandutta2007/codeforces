#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define M 1000000

int k, n = 1999, sum, a, A[2000];

bool Check()
{
	LL sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += A[i];
	return (sum * n - (sum + a) * (n - 2)) == k;
}

int main()
{
	scanf("%d", &k);
	a = 2 - (k & 1);
	sum = (k + a * n) / 2;
	// fprintf(stderr, "sum = %d, a = %d\n", sum, a);
	for (int i = 3; i <= n; i ++)
	{
		int t = min(M, sum);
		A[i] = t, sum -= t;
	}
	A[1] = 1, A[2] = -1 - a;
	printf("%d\n", n);
	for (int i = 1; i <= n; i ++)
		printf("%d%c", A[i], i == n ? '\n' : ' ');
	if (!Check()) fputs("QAQ\n", stderr);
	return 0;
}