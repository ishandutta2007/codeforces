#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int n;
	int i, j, k;
	int a[1003];
	int ans[2003];
	int cnt[1003];
	int l, r;
	for (; t > 0; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		k = 0;
		for (i = 0; i <= n; i++)
			cnt[i] = 0;
		for (i = 0; i < n; i++)
			cnt[a[i]]++;
		l = 0;
		r = n - 1;
		while (a[l] == l)
			l++;
		while (a[r] == r + 1)
			r--;
		while (l <= r)
		{
			j = 0;
			while (cnt[j] > 0)
				j++;
			if (j == l)
			{
				ans[k] = j + 1;
				k++;
				cnt[a[j]]--;
				a[j] = j;
				cnt[j]++;
			}
			else
			{
				ans[k] = j;
				k++;
				cnt[a[j - 1]]--;
				a[j - 1] = j;
				cnt[j]++;
			}
			while (a[l] == l)
				l++;
			while (a[r] == r + 1)
				r--;
		}
		printf("%d\n", k);
		if (k > 0)
		{
			for (i = 0; i < k - 1; i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[k - 1]);
		}
	}
	return 0;
}