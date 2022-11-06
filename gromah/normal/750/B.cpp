#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int n, pos = MAX;
char s[9];
bool ok = 1;

inline int Trans(char *p)
{
	if (p[0] == 'S') return -1;
	if (p[0] == 'N') return 1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, x; ok && i <= n; i ++)
	{
		scanf("%d%s", &x, s);
		int t = Trans(s);
		if ((pos == MAX || pos == -MAX) && t == 0) ok = 0;
		else
		{
			pos += t * x;
			if (pos > MAX || pos < -MAX) ok = 0;
		}
	}
	if (ok && pos == MAX) puts("YES");
		else puts("NO");
	return 0;
}