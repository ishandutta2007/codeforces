#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define LIM 100000000000000LL
#define abs(x) (x > 0 ? x : -x)

int n, k;
LL ans, sum;
map <LL, int> Map;

int main()
{
	scanf("%d%d", &n, &k);
	Map[0] = 1;
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		sum += x;
		LL cur = 1;
		do
		{
			if (Map.find(sum - cur) != Map.end())
				ans += Map[sum - cur];
			cur *= k;
		} while (cur != 1 && abs(cur) <= LIM);
		Map[sum] ++;
	}
	printf("%I64d\n", ans);
	return 0;
}