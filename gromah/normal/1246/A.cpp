#include <cstdio>
#include <algorithm>
using namespace std;

int n, p;

int main()
{
	scanf("%d%d", &n, &p);
	for (int cnt = 1; ; cnt ++)
	{
		n -= p;
		if (n < cnt)
		{
			puts("-1");
			break ;
		}
		if (__builtin_popcount(n) <= cnt)
		{
			printf("%d\n", cnt);
			break ;
		}
	}
	return 0;
}