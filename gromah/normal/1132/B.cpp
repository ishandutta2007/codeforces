#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5

int n, m, A[N];
LL sum;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		sum += A[i];
	}
	sort(A + 1, A + n + 1);
	reverse(A + 1, A + n + 1);
	for (scanf("%d", &m); m; m --)
	{
		int x;
		scanf("%d", &x);
		printf("%lld\n", sum - A[x]);
	}
	return 0;
}