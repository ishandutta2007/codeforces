#include <cstdio>

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d", &n);
		int max = 0, cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			int a; scanf("%d", &a);
			if (a > max)
			{
				max = a;
				cnt = 1;
			}
			else if (a == max)
				++cnt;
		}
		if (cnt == n)
			printf("%d\n", n);
		else 
			printf("1\n");
	}
}