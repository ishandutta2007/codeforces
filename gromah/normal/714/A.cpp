#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

LL l_1, r_1, l_2, r_2, k, ans;

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d", &l_1, &r_1, &l_2, &r_2, &k);
	l_1 = max(l_1, l_2), r_1 = min(r_1, r_2);
	ans = max(r_1 - l_1 + 1, 0LL);
	if (l_1 <= k && k <= r_1) ans --;
	printf("%I64d\n", ans);
	return 0;
}