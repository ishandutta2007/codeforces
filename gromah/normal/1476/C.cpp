#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int Case, n, C[N], A[N], B[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", C + i);
		for (int i = 1; i <= n; i ++)
			scanf("%d", A + i);
		for (int i = 1; i <= n; i ++)
			scanf("%d", B + i);
		LL res = 0, pre = 0;
		for (int i = 2; i <= n; i ++)
		{
			if (A[i] == B[i])
				pre = 2;
			else pre = max(LL(abs(A[i] - B[i])), (i == 2 ? 0LL : pre + C[i - 1] - 1 - abs(A[i] - B[i]))) + 2;
			res = max(res, pre + C[i] - 1);
			//printf("Ring[%d] = %lld\n", i, pre + C[i] - 1);
		}
		printf("%lld\n", res);
	}
	return 0;
}