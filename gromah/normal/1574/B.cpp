#include <cstdio>
#include <algorithm>
using namespace std;

int Case, a, b, c, m;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d%d%d", &a, &b, &c, &m);
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		int l = max(0, c - a - b - 1);
		int r = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);
		puts(l <= m && m <= r ? "YES" : "NO");
	}
	return 0;
}