#include <bits/stdc++.h>
using namespace std;
int n, ans;
char s[100];
char ask(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char c;
	scanf(" %c", &c);
	return c;
}
int main()
{
	while (1) {
		scanf("%s", s);
		if (s[0] == 'e') break;
		int x = 1, y = 3;
		while (1) {
			if (ask(x, y) == 'x') break;
			x = y;
			y = y + y + 1;
		}
		int l = x, r = y, mid;
		while (l <= r) {
			if (l == r) {
				printf("! %d\n", l);
				break;
			}
			if ((l + r) / 2 == l) {
				if (ask(l - 1, l) == 'x')
				{
					printf("! %d\n", l);
				} else printf("! %d\n", l + 1);
				break;
			}
			if (ask(x, mid = (l + r) / 2) == 'x')
				r = mid;
			else
				l = mid;
		}
		fflush(stdout);
	}
}