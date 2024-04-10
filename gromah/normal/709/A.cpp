#include <cstdio>

int n, b, d, x, sum, cnt;

int main()
{
	scanf("%d%d%d", &n, &b, &d);
	while (n --)
	{
		scanf("%d", &x);
		if (x > b) continue ;
		sum += x;
		if (sum > d) sum = 0, cnt ++;
	}
	printf("%d\n", cnt);
	return 0;
}