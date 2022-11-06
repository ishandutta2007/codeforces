#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int Case, n, sz, ans, A[N], Min[N], Max[N], Id[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			Id[i] = 0, Min[i] = n + 1, Max[i] = 0;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", A + i);
			Id[A[i]] = 1;
		}
		for (int i = 1; i <= n; i ++)
			Id[i] += Id[i - 1];
		sz = Id[n];
		for (int i = 1; i <= n; i ++)
		{
			A[i] = Id[A[i]];
			Min[A[i]] = min(Min[A[i]], i);
			Max[A[i]] = max(Max[A[i]], i);
		}
		ans = sz;
		for (int l = 1, r = 0, mx; l <= sz; l ++)
		{
			if (r < l)
				r = l, mx = Max[l];
			for (; r < sz && Min[r + 1] > mx; r ++)
				mx = Max[r + 1];
			ans = min(ans, sz - (r - l + 1));
		}
		printf("%d\n", ans);
	}
	return 0;
}