#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n;
int a[MAXN];

set<int> S;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i] == a[i - 1] || a[i] < a[i - 1])
				a[i]++;
		}
		sort(a + 1,a + n + 1);
		n = unique(a + 1,a + n + 1) - a - 1;
		printf("%d\n",n);
	}
	return 0;
}