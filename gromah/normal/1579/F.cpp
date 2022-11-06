#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int Case, n, k, ans, A[N], T[N << 1];
bool Flag[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i ++)
		{
			scanf("%d", A + i);
			Flag[i] = false;
		}
		ans = 0;
		for (int i = 0; ans >= 0 && i < n; i ++)
			if (!Flag[i])
			{
				int sz = 1;
				T[sz] = A[i], Flag[i] = true;
				for (int j = (i + k) % n; j != i; j = (j + k) % n)
					T[++ sz] = A[j], Flag[j] = true;
				int all_one = true;
				for (int j = 1; j <= sz; j ++)
				{
					T[sz + j] = T[j];
					if (T[j] != 1)
						all_one = false;
				}
				if (all_one)
					ans = -1;
				else
				{
					int mx = 0;
					for (int i = 1, cur = 0; i <= 2 * sz; i ++)
					{
						cur = T[i] == 0 ? 0 : cur + 1;
						mx = max(mx, cur);
					}
					ans = max(ans, mx);
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}