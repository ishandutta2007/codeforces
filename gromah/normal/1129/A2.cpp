#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, m, Cnt[N], Min[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		Min[i] = n - 1;
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Cnt[u] ++, Min[u] = min(Min[u], (v + n - u) % n);
	}
	for (int i = 1; i <= n; i ++)
	{
		int res = 0;
		for (int j = 1; j <= n; j ++)
			if (Cnt[j])
				res = max(res, Min[j] + (Cnt[j] - 1) * n + (j + n - i) % n);
		printf("%d%c", res, i == n ? '\n' : ' ');
	}
	return 0;
}