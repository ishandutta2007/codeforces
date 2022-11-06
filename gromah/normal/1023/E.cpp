#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n;
char s[N], res[9];

bool Ask(int x_1, int y_1, int x_2, int y_2)
{
	printf("? %d %d %d %d\n", x_1, y_1, x_2, y_2);
	fflush(stdout);
	scanf("%s", res);
	return res[0] == 'Y';
}

int main()
{
	scanf("%d", &n);
	for (int x = 1, y = 1, i = 1; x + y < 1 + n; i ++)
	{
		if (Ask(x, y + 1, n, n))
		{
			y ++;
			s[i] = 'R';
		}
		else x ++, s[i] = 'D';
	}
	for (int x = n, y = n, i = 2 * n - 2; x + y > 1 + n; i --)
	{
		if (Ask(1, 1, x - 1, y))
		{
			x --;
			s[i] = 'D';
		}
		else y --, s[i] = 'R';
	}
	printf("! %s\n", s + 1);
	return 0;
}