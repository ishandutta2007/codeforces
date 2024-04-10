#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define Abs(x) ((x) > 0 ? (x) : -(x))

int n, sum, Max, Min, ans, Del[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1, l, r; i <= n; i ++)
	{
		scanf("%d%d", &l, &r);
		Del[i] = r - l << 1;
		sum += l - r;
		Max = (!Max || Del[Max] < Del[i]) ? i : Max;
		Min = (!Min || Del[Min] > Del[i]) ? i : Min;
	}
	if (Abs(Del[Max] + sum) > Abs(sum))
	{
		ans = Max;
		if (Abs(Del[Min] + sum) > Abs(Del[Max] + sum))
			ans = Min;
	}
	else if (Abs(Del[Min] + sum) > Abs(sum))
		ans = Min;
	printf("%d\n", ans);
	return 0;
}