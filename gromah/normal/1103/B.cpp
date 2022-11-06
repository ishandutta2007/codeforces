#include <cstdio>
#include <algorithm>
using namespace std;

char s[9];

bool Ask(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", s);
	return s[0] == 'x' ? 0 : 1;
}

int main()
{
	for (scanf("%s", s); s[0] == 's'; scanf("%s", s))
	{
		int d = 0;
		for (; Ask(d ? (1 << d - 1) : 0, 1 << d); d ++) ;
		int l = (d ? (1 << d - 1) : 0) + 1, r = 1 << d;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (Ask(d ? (1 << d - 1) : 0, mid))
				l = mid + 1;
			else r = mid;
		}
		printf("! %d\n", l);
		fflush(stdout);
	}
	return 0;
}