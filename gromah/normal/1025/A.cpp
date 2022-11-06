#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n;
char s[N];
bool ok, Flag[26];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	if (n == 1) puts("YES");
	else
	{
		for (int i = 0; !ok && i < n; i ++)
		{
			if (Flag[s[i] - 'a'])
				ok = 1;
			else Flag[s[i] - 'a'] = 1;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}