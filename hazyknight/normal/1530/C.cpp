#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int T,n,m;
int a[MAXN];
int b[MAXN];
int suma[MAXN];
int sumb[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		for (int i = n + 1;i <= 4 * n;i++)
			a[i] = 100;
		for (int i = 1;i <= n;i++)
			scanf("%d",&b[i]);
		sort(b + 1,b + n + 1);
		reverse(b + 1,b + n + 1);
		for (int i = n + 1;i <= 4 * n;i++)
			b[i] = 0;
		for (int i = 1;i <= 4 * n;i++)
		{
			suma[i] = suma[i - 1] + a[i];
			sumb[i] = sumb[i - 1] + b[i];
		}
		for (int i = n;i <= 4 * n;i++)
		{
			int T = i - i / 4;
			if (suma[i] - suma[i - T] >= sumb[T])
			{
				printf("%d\n",i - n);
				break;
			}
		}
	}
	return 0;
}