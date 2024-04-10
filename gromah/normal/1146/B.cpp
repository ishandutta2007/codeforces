#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, cnt;
char s[N];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i ++)
		cnt += s[i] != 'a';
	if (cnt & 1) puts(":(");
	else
	{
		int pos = 0;
		for (int cur = 0; pos < n; pos ++)
		{
			cur += s[pos] != 'a';
			if (cur * 2 > cnt) break ;
		}
		bool ok = (n - pos) * 2 == cnt;
		for (int i = 0, j = pos; ok && i < pos && j < n; i ++)
		{
			if (s[i] == 'a') continue ;
			if (s[i] != s[j ++])
				ok = false;
		}
		if (!ok) puts(":(");
		else
		{
			for (int i = 0; i < pos; i ++)
				putchar(s[i]);
			puts("");
		}
	}
	return 0;
}