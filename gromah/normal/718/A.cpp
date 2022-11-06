#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, t, start, dot = -1, Int[N];
bool flag = 0, all_9 = 1;
char s[N];

inline void Output()
{
	if (all_9)
	{
		putchar('1');
		for (int i = 0; i < dot; i ++)
			putchar('0');
		putchar('\n');
		return ;
	}
	Int[dot - 1] ++;
	for (int i = dot - 1; Int[i] >= 10; i --)
		Int[i - 1] ++, Int[i] = 0;
	for (int i = 0; i < dot; i ++)
		putchar('0' + Int[i]);
	putchar('\n');
}

int main()
{
	scanf("%d%d", &n, &t);
	scanf("%s", s);
	for (start = 0; start < n; start ++)
	{
		if (s[start] == '.') dot = start;
		if (!~dot)
		{
			Int[start] = s[start] - '0';
			all_9 &= (s[start] == '9');
		}
		if (~dot && s[start] >= '5') break ;
	}
	for (int i = start; start < n && i > dot && t; i --)
		if (s[i] >= '5')
		{
			if (i == dot + 1) flag = 1;
			else
			{
				s[i - 1] ++;
				s[i] = '\0';
			}
			t --;
		}
	if (flag) Output();
		else printf("%s", s);
	return 0;
}