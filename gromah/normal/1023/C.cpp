#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, k;
char s[N];
bool Flag[N];

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0, no = 0; i < n; i ++)
	{
		if (s[i] == '(')
		{
			if (k) k -= 2, Flag[i] = 1;
			else no ++;
		}
		else
		{
			if (!no) Flag[i] = 1;
			else no --;
		}
	}
	for (int i = 0; i < n; i ++)
		if (Flag[i])
			putchar(s[i]);
	puts("");
	return 0;
}