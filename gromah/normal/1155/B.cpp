#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, rem, pos, cnt;
char s[N];

int main()
{
	scanf("%d%s", &n, s);
	rem = n - 11 >> 1;
	for (cnt = pos = 0; pos < n; pos ++)
	{
		cnt += (s[pos] == '8');
		if (cnt > rem) break ;
	}
	if (cnt <= rem) puts("NO");
	else puts(pos <= 2 * rem ? "YES" : "NO");
	return 0;
}