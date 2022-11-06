#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500000 + 5

int n, k, l, r, L_lim, R_lim, A[N];
LL Sum[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	sort(A + 1, A + n + 1);
	for (int i = 1; i <= n; i ++)
		Sum[i] = Sum[i - 1] + A[i];
	for (l = 2; l <= n; l ++)
	{
		LL tmp = 1LL * l * A[l] - Sum[l];
		if (tmp > k)
		{
			L_lim = (k + Sum[l - 1]) / (l - 1);
			break ;
		}
	}
	if (l > n)
	{
		if (Sum[n] % n == 0) puts("0");
		else puts("1");
		return 0;
	}
	for (r = n - 1; r; r --)
	{
		LL tmp = (Sum[n] - Sum[r]) - 1LL * (n - r) * A[r];
		if (tmp > k)
		{
			R_lim = (Sum[n] - Sum[r] - k + n - r - 1) / (n - r);
			break ;
		}
	}
	if (R_lim < L_lim) R_lim = L_lim;
	int ans = R_lim - L_lim;
	if (ans == 0 && Sum[n] % n) ans = 1;
	printf("%d\n", ans);
	return 0;
}