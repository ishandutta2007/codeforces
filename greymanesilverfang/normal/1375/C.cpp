#include <cstdio>
const int N = 4e5;
int a[N];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		if (a[1] < a[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
}