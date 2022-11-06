#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int Case, n, a, b, A[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", A + i);
		sort(A + 1, A + n + 1);
		a = b = 0;
		for (int i = 1, last = 0, j; i <= n; i = j)
		{
			for (j = i; j <= n && A[i] == A[j]; j ++) ;
			if (j == i + 1) continue ;
			if (j - i >= 4)
			{
				a = b = A[i];
				break ;
			}
			if (!last) last = i;
			else
			{
				int u = A[last];
				int v = A[i];
				if (!a) a = u, b = v;
				else
				{
					LL fz = u * u + v * v, fm = u * v;
					LL _fz = a * a + b * b, _fm = a * b;
					if (1LL * fz * _fm < 1LL * _fz * fm)
						a = u, b = v;
				}
				last = i;
			}
		}
		printf("%d %d %d %d\n", a, a, b, b);
	}
	return 0;
}