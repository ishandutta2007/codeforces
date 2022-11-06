#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n;
char s[N];
bool ok = false;

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1, mx = 0; !ok && i <= n; i ++)
	{
		if (mx && s[mx] > s[i])
		{
			puts("YES");
			printf("%d %d\n", mx, i);
			ok = true;
		}
		if (!mx || s[mx] < s[i])
			mx = i;
	}
	if (!ok) puts("NO");
	return 0;
}