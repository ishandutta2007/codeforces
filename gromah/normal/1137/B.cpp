#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500000 + 5

int s0, t0, t1, n, m, Next[N];
char s[N], t[N];

void GetNext()
{
	Next[0] = -1;
	int j = 0, k = -1;
	while (j < m)
	{
		if (!~k || t[j] == t[k])
			Next[++ j] = ++ k;
		else k = Next[k];
	}
}

int main()
{
	scanf("%s%s", s, t);
	n = strlen(s), m = strlen(t);
	GetNext();
	for (int i = 0; s[i]; i ++)
		s0 += s[i] == '0';
	for (int i = 0; t[i]; i ++)
		t0 += t[i] == '0';
	for (int i = Next[m]; t[i]; i ++)
		t1 += t[i] == '0';
	int A = t0, B = m - t0, l = m - Next[m], step = 0;
	while (A + t1 <= s0 && B + l - t1 <= n - s0)
		A += t1, B += l - t1, step ++;
	//fprintf(stderr, "step = %d\n", step);
	if (t0 <= s0 && m - t0 <= n - s0)
	{
		printf("%s", t);
		for (int i = 0; i < step; i ++)
			printf("%s", t + Next[m]);
		for (int i = s0 - A; i; i --)
			putchar('0');
		for (int i = n - s0 - B; i; i --)
			putchar('1');
		puts("");
	}
	else printf("%s\n", s);
	return 0;
}