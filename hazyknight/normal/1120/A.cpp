#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 500005;

int m,k,n,s,CNT;
int a[MAXN];
int cnt[MAXN];

int main()
{
	scanf("%d%d%d%d",&m,&k,&n,&s);
	for (int i = 1;i <= m;i++)
		scanf("%d",&a[i]);
	for (int b,i = 1;i <= s;i++)
	{
		scanf("%d",&b);
		if (!cnt[b])
			CNT++;
		cnt[b]++;
	}
	for (int i = 1,j = 0;i <= m;CNT += !cnt[a[i++]]++)
	{
		while (j + 1 <= m && CNT)
			CNT -= !--cnt[a[++j]];
		int tmp = j;
		if (j - i + 1 < k)
			j = i + k - 1;
		int w = j - ((i - 1) / k + 1) * k;
		if (!CNT && w <= m - k * n)
		{
			printf("%d\n",w);
			for (int l = i;w && l <= min(j,m);l++)
				if (cnt[a[l]] < 0)
				{
					printf("%d ",l);
					cnt[a[l]]++;
					w--;
				}
			printf("\n");
			return 0;
		}
		j = tmp;
	}
	printf("-1\n");
	return 0;
}