#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5

int n, A[N];
LL ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, j = 1; i <= n; i ++)
	{
		while (!A[j] && j < i) j ++;
		while (j < i && A[i] >= 2)
		{
			A[i] -= 2, A[j] --;
			ans ++;
			while (!A[j] && j < i) j ++;
		}
		ans += A[i] / 3, A[i] %= 3;
	}
	printf("%lld\n", ans);
	return 0;
}