#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 2000005;

int T,n,tot,ans,ANS;
int cnt[MAXN];
int c[MAXN];
int mark[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			cnt[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&c[i]);
			cnt[c[i]]++;
		}
		for (int i = 1;i <= n + 1;i++)
			mark[i] = 0;
		tot = 0;
		for (int i = 1;i <= n;i++)
		{
			if (!cnt[i])
				continue;
			int MAX = 0;
			for (int j = 1,k = 1;j <= cnt[i];j = k + 1)
			{
				int v = cnt[i] / j;
				k = cnt[i] / v;
				if (cnt[i] % v == 0)
				{
					if (MAX < cnt[i] / v)
						mark[MAX = cnt[i] / v]++;
					if (MAX < cnt[i] / v + 1)
						mark[MAX = cnt[i] / v + 1]++;
				}
				else if (MAX < (cnt[i] - 1) / v + 1)
					mark[MAX = (cnt[i] - 1) / v + 1]++;
			}
			tot++;
		}
		int ans = 1;
		for (int i = n + 1;i >= 1;i--)
			if (mark[i] == tot)
			{
				ans = i;
				break;
			}
		ANS = 0;
		for (int i = 1;i <= n;i++)
			if (cnt[i])
				ANS += (cnt[i] - 1) / ans + 1;
		printf("%d\n",ANS);
	}
	return 0;
}