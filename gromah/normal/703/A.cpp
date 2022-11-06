#include <cstdio>

int n, a, b;

int main()
{
	scanf("%d", &n);
	while (n --)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a += u > v;
		b += v > u;
	}
	if (a > b) puts("Mishka");
	else if (b > a) puts("Chris");
	else puts("Friendship is magic!^^");
	return 0;
}