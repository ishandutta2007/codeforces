#include <cmath>
#include <cstdio>
using namespace std;
#define N 1000000 + 5

int a, b, c, d, x, y, len = 0;
char s[N];

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (b == 0 && c == 0)
	{
		if (a > 0 && d > 0) puts("Impossible");
		else
		{
			x = (int) sqrt(2.0 * a);
			y = (int) sqrt(2.0 * d);
			if (x > 0 && x * (x + 1) == a * 2)
			{
				for (int i = 0; i <= x; i ++)
					putchar('0');
				puts("");
			}
			else if (y > 0 && y * (y + 1) == d * 2)
			{
				for (int i = 0; i <= y; i ++)
					putchar('1');
				puts("");
			}
			else if (x == 0 && y == 0) puts("0");
			else puts("Impossible");
		}
	}
	else
	{
		x = (int) sqrt(2.0 * a) + 1;
		y = (int) sqrt(2.0 * d) + 1;
		if (x * y != b + c || x * (x - 1) != a * 2 || y * (y - 1) != d * 2)
			puts("Impossible");
		else
		{
			for (int i = 1; i <= b / y; i ++)
				s[len ++] = '0';
			for (int i = 1; i <= y - b % y; i ++)
				s[len ++] = '1';
			if (b % y) s[len ++] = '0';
			for (int i = 1; i <= b % y; i ++)
				s[len ++] = '1';
			for (int i = (b + y - 1) / y; i < x; i ++)
				s[len ++] = '0';
			printf("%s\n", s);
		}
	}
	return 0;
}