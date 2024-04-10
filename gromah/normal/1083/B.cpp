#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500000 + 5

int n, k, diff, dep;
char s[N], t[N];
LL ans;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s%s", s, t);
	for (dep = 0; dep < n; dep ++)
	{
		diff = diff * 2 + (t[dep] - s[dep]);
		if (diff + 1 >= k)
			break ;
		ans += diff + 1;
	}
	ans += 1LL * k * (n - dep);
	printf("%lld\n", ans);
	return 0;
}