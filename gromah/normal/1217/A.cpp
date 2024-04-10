#include <cstdio>
#include <algorithm>
using namespace std;

int Case, a, b, c;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d%d", &a, &b, &c);
		int ans = a + c - (a + b + c) / 2;
		if (ans < 0) ans = 0;
		if (ans > c + 1) ans = c + 1;
		printf("%d\n", ans);
	}
	return 0;
}