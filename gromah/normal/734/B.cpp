#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d, sum;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int t = min(a, min(c, d));
	sum = (t << 8);
	a -= t, c -= t, d -= t;
	t = min(a, b);
	sum += (t << 5);
	printf("%d\n", sum);
	return 0;
}