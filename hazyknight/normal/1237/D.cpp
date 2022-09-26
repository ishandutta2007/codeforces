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

const int MAXN = 300005;

int n;
int a[MAXN];
int LOG2[MAXN];
int bd[MAXN];
int ans[MAXN];
int MX[MAXN][20];

int getmax(int l,int r)
{
	int len = r - l + 1;
	return max(MX[l][LOG2[len]],MX[r - (1 << LOG2[len]) + 1][LOG2[len]]);
}

int main()
{
	scanf("%d",&n);
	int MIN = 1e9,MAX = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		MIN = min(MIN,a[i]);
		MAX = max(MAX,a[i]);
	}
	if (MIN * 2 >= MAX)
	{
		for (int i = 1;i <= n;i++)
			printf("-1 ");
		printf("\n");
		return 0;
	}
	for (int i = n + 1;i <= 3 * n;i++)
		a[i] = a[i - n];
	for (int i = 1;i <= 3 * n;i++)
	{
		if (i == 1)
			LOG2[i] = 0;
		else
			LOG2[i] = LOG2[i >> 1] + 1;
		MX[i][0] = a[i];
		bd[i] = 3 * n + 1;
	}
	for (int i = 1;(1 << i) <= 3 * n;i++)
		for (int j = 1;j + (1 << i) - 1 <= 3 * n;j++)
			MX[j][i] = max(MX[j][i - 1],MX[j + (1 << (i - 1))][i - 1]);
	for (int i = 1;i <= 3 * n;i++)
	{
		int low = 1,high = i - 1;
		while (low < high)
		{
			int mid = low + high + 1 >> 1;
			if (getmax(mid,i - 1) > a[i] * 2)
				low = mid;
			else
				high = mid - 1;
		}
		if (getmax(low,i - 1) <= a[i] * 2)
			continue;
		bd[low] = min(bd[low],i);
	}
	MIN = 3 * n + 1;
	for (int i = 3 * n;i >= 1;i--)
	{
		MIN = min(MIN,bd[i]);
		ans[i] = MIN;
	}
	for (int i = 1;i <= n;i++)
		printf("%d ",ans[i] - i);
	printf("\n");
	printf("\n");
	return 0;
}