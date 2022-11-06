#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 65000 + 5

int n;
char s[N];
LL ans;

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++)
		if (s[i] + 1 & 1)
			ans += i;
	printf("%lld\n", ans);
	return 0;
}