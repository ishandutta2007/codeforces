#include <cstdio>
const int N = 2e5;
int a[N];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)
		{
			int x; scanf("%d", &x);
			a[i] = x - a[i];
		}
		int flag = 0, val = 0;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] < 0)
				flag = 2;
			if (a[i] > 0)
			{
				if (!val)
					val = a[i];
				else if (val != a[i])
					flag = 2;
				if (!i || !a[i - 1])
					++flag;
			}
			if (flag == 2)
				break;
		}
		printf("%s\n", flag < 2 ? "YES" : "NO");
	}
}