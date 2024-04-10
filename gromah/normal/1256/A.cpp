#include <cstdio>
#include <algorithm>
using namespace std;

int Case, a, b, n, s;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d%d%d", &a, &b, &n, &s);
		int t = min(s / n, a);
		s -= t * n;
		puts(s <= b ? "YES" : "NO");
	}
	return 0;
}