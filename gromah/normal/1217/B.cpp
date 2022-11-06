#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int Case, n, x, D[N], H[N], delmx, absmx;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &x);
		delmx = absmx = 0;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d%d", D + i, H + i);
			if (!delmx || D[i] - H[i] > D[delmx] - H[delmx])
				delmx = i;
			if (!absmx || D[i] > D[absmx])
				absmx = i;
		}
		if (D[absmx] >= x)
			puts("1");
		else if (D[delmx] - H[delmx] <= 0 && D[absmx] < x)
			puts("-1");
		else
		{
			int ti = (x - D[absmx] - 1) / (D[delmx] - H[delmx]) + 1;
			printf("%d\n", ti + 1);
		}
	}
	return 0;
}