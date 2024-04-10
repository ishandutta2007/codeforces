#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100 + 5

int Case, n, k;
LL P[N];

bool Check(LL x)
{
	LL cur = x + P[0];
	for (int i = 1; i < n; i ++)
	{
		if (P[i] * 100 > k * cur)
			return false;
		cur += P[i];
	}
	return true;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i ++)
			scanf("%lld", P + i);
		LL l = 0, r = 100000000000;
		while (l < r)
		{
			LL mid = l + r >> 1;
			if (Check(mid))
				r = mid;
			else l = mid + 1;
		}
		printf("%lld\n", l);
	}
	return 0;
}