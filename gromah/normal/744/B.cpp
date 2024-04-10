#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, Min[N], Q[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		Min[i] = 1234567890;
	for (int d = 0; (1 << d) < n; d ++)
		for (int op = 0; op < 2; op ++)
		{
			int cnt = 0;
			for (int i = 1; i <= n; i ++)
				if (((i - 1 >> d) & 1) == op) Q[++ cnt] = i;
			printf("%d\n", cnt);
			for (int i = 1; i <= cnt; i ++)
				printf("%d%c", Q[i], i == cnt ? '\n' : ' ');
			fflush(stdout);
			for (int i = 1, x; i <= n; i ++)
			{
				scanf("%d", &x);
				if (((i - 1 >> d) & 1) == op ^ 1)
					Min[i] = min(Min[i], x);
			}
		}
	puts("-1");
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Min[i], i == n ? '\n' : ' ');
	return 0;
}