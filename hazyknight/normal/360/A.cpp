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

const int MAXN = 5005;
const int INF = 5e8;

int n,m;
int tp[MAXN];
int l[MAXN];
int r[MAXN];
int d[MAXN];
int MAX[MAXN];
int a[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		MAX[i] = INF;
	for (int i = 1;i <= m;i++)
		scanf("%d%d%d%d",&tp[i],&l[i],&r[i],&d[i]);
	for (int i = m;i >= 1;i--)
	{
		if (tp[i] == 1)
		{
			for (int j = l[i];j <= r[i];j++)
				MAX[j] -= d[i];
		}
		else
		{
			for (int j = l[i];j <= r[i];j++)
				MAX[j] = min(MAX[j],d[i]);
		}
	}
	for (int i = 1;i <= n;i++)
		a[i] = MAX[i];
	for (int i = 1;i <= m;i++)
	{
		if (tp[i] == 1)
		{
			for (int j = l[i];j <= r[i];j++)
				a[j] += d[i];
		}
		else
		{
			int res = -INF;
			for (int j = l[i];j <= r[i];j++)
				res = max(res,a[j]);
			if (res != d[i])
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for (int i = 1;i <= n;i++)
		printf("%d ",MAX[i]);
	printf("\n");
	return 0;
}