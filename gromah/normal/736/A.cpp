#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int ans = 0;
LL n;

int main()
{
	scanf("%I64d", &n);
	for (LL x = 1, y = 2; y <= n; y += x, x = y - x) ans ++;
	printf("%d\n", ans);
	return 0;
}