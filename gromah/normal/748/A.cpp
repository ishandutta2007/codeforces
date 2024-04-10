#include <cstdio>

int m, n, pos;

int main()
{
	scanf("%d%d%d", &m, &n, &pos);
	int r = (pos - 1 >> 1) / n + 1;
	int c = (pos - 1 >> 1) % n + 1;
	printf("%d %d %c\n", r, c, pos & 1 ? 'L' : 'R');
	return 0;
}