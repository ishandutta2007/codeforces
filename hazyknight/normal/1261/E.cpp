#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1005;

int n,tot;
int b[MAXN];
int ans[MAXN][MAXN];
int ANS[MAXN][MAXN];

pair<int,int> a[MAXN];

int main()
{
	srand(time(0));
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	int cur = 1;
	while (cur <= n)
	{
		bool notn = 0;
		for (int i = cur;i <= n;i++)
			if (a[i].first != n - cur + 1)
				notn = 1;
		if (a[cur].first == 1)
		{
			tot++;
			ans[tot][cur] = 1;
			for (int i = cur + 1;i <= n;i++)
				if (a[i].first > n - cur)
				{
					a[i].first--;
					ans[tot][i] = 1;
				}
			cur++;
			continue;
		}
		if (!notn)
		{
			for (int i = 1;i <= n - cur + 2;i++)
				for (int j = cur;j <= n;j++)
					ans[tot + i][j] = 1;
			for (int i = 1;i <= n - cur + 1;i++)
				ans[tot + i][cur + i - 1] = 0;
			tot += n - cur + 2;
			break;
		}
		bool ok = 0;
		for (int i = cur + 1;i <= n;i++)
			if (a[i].first == i - cur)
			{
				for (int j = cur;j <= i;j++)
					for (int k = 1;k <= a[j].first + 1;k++)
						ans[tot + k][j] = 1;
				for (int k = 1;k <= a[i].first + 1;k++)
				{
					ans[tot + k][k + cur - 1] = 0;
					for (int l = i + 1;l <= n;l++)
						if (a[l].first >= n - i + 1)
						{
							ans[tot + k][l] = 1;
							a[l].first--;
						}
				}
				tot += a[i].first + 1;
				cur = i + 1;
				ok = 1;
				break;
			}
		if (ok)
			continue;
		if (a[n].first == n - cur + 1)
		{
			for (int j = cur;j <= n;j++)
				for (int k = 1;k <= a[j].first + 1;k++)
					ans[tot + k][j] = 1;
			for (int k = 1;k <= a[n].first + 1;k++)
				ans[tot + k + 1][k + cur - 1] = 0;
			tot += a[n].first + 1;
			break;
		}
	}
	for (int i = 1;i <= tot;i++)
		for (int j = 1;j <= n;j++)
			ANS[i][a[j].second] = ans[i][j];
	printf("%d\n",tot);
	for (int i = 1;i <= tot;i++,putchar('\n'))
		for (int j = 1;j <= n;j++)
			putchar(ANS[i][j] + '0');
	return 0;
}