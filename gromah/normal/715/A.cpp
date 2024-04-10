#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
LL cur = 2;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		LL tmp = 1LL * (i + 1) * (i + 1) * i - cur;
		printf("%I64d\n", tmp);
		cur = i;
	}
	return 0;
}