#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, A[N], T[N], C[N];
LL Sum[N], Ans[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", T + i);
		Sum[i] = Sum[i - 1] + T[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		int x = upper_bound(Sum + i, Sum + n + 1, Sum[i - 1] + A[i]) - Sum;
		C[i] ++, C[x] --;
		if (x <= n) Ans[x] += A[i] + Sum[i - 1] - Sum[x - 1];;
	}
	for (int i = 1; i <= n; i ++)
	{
		C[i] += C[i - 1];
		Ans[i] += 1LL * C[i] * T[i];
	}
	for (int i = 1; i <= n; i ++)
		printf("%lld%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}