#include <cstdio>
#define N 100000 + 5

int len = 0;
bool ok = 1, flag = 0;
char ch, s[N];

int main()
{
	for (ch = '\n'; ch > 'z' || ch < 'a'; ch = getchar()) ;
	if (ch != 'a') s[len ++] = ch - 1, flag = 1;
		else s[len ++] = 'a';
	for (ch = getchar(); ch >= 'a' && ch <= 'z'; ch = getchar())
	{
		if (ch == 'a')
		{
			s[len ++] = 'a';
			if (flag) ok = 0;
		}
		else if (ok)
		{
			s[len ++] = ch - 1;
			flag = 1;
		}
		else s[len ++] = ch;
	}
	if (!flag) s[len - 1] = 'z';
	printf("%s", s);
	return 0;
}