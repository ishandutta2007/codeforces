#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define LIM 1000000000

int n, a, b, Sum[N], Lim[N];
bool ok = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d%d", &x, Lim + i);
		Sum[i] = Sum[i - 1] + x;
		if (i == 1)
		{
			if (Lim[i] == 1)
				a = 1900, b = LIM;
			else a = -LIM, b = 1899, ok = 0;
		}
		else
		{
			if (Lim[i] == 1)
				a = max(a, 1900 - Sum[i - 1]);
			else b = min(b, 1899 - Sum[i - 1]), ok = 0;
		}
	}
	if (ok) puts("Infinity");
	else if (a > b) puts("Impossible");
	else printf("%d\n", b + Sum[n]);
	return 0;
}