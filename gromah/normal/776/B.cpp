#include <cstdio>
#define N 100000 + 5

int n;
bool Flag[N];

int main()
{
	scanf("%d", &n);
	if (n <= 2)
	{
		puts("1");
		for (int i = 1; i <= n; i ++)
			printf("1%c", i == n ? '\n' : ' ');
	}
	else
	{
		puts("2");
		n ++;
		for (int i = 2; i <= n; i ++)
		{
			if (Flag[i]) continue ;
			for (int j = i * 2; j <= n; j += i)
				Flag[j] = 1;
		}
		for (int i = 2; i <= n; i ++)
			printf("%d%c", 1 + Flag[i], i == n ? '\n' : ' ');
	}
	return 0;
}