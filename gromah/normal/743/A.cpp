#include <cstdio>
#define N 100000 + 5

int n, a, b;
char s[N];

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s + 1);
	putchar('0' + (s[a] != s[b]));
	return 0;
}