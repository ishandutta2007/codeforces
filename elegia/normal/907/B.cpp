#include <cstdio>

using namespace std;

char s[10][11];

int main() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			s[i][j] = getchar();
			if (j % 3 == 0)
				getchar();
		}
		if (i % 3 == 0 && i != 9)
			getchar();
	}
	int x, y, xl, yl;
	bool flag = false;
	scanf("%d%d", &x, &y);
	xl = (x - 1) % 3 + 1;
	yl = (y - 1) % 3 + 1;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			if (s[(xl - 1) * 3 + i][(yl - 1) * 3 + j] == '.') {
				s[(xl - 1) * 3 + i][(yl - 1) * 3 + j] = '!';
				flag = true;
			}
	if (!flag) {
		for (int i = 1; i <= 9; ++i)
			for (int j = 1; j <= 9; ++j)
				if (s[i][j] == '.')
					s[i][j] = '!';
	}
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			putchar(s[i][j]);
			if (j % 3 == 0 && j != 9)
				putchar(' ');
		}
		putchar('\n');
		if (i % 3 == 0)
			putchar('\n');
	}
	return 0;
}