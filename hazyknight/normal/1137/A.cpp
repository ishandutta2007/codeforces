#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 1005;

int n,m;
int lr[MAXN];
int lc[MAXN];
int a[MAXN][MAXN];
int r[MAXN][MAXN];
int c[MAXN][MAXN];

int cs(int *arr,int len,int val)
{
	if (arr[1] >= val)
		return 0;
	int low = 1,high = len;
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (arr[mid] < val)
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

int cb(int *arr,int len,int val)
{
	if (arr[len] <= val)
		return 0;
	int low = 1,high = len;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (arr[mid] > val)
			high = mid;
		else
			low = mid + 1;
	}
	return len - low + 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			scanf("%d",&a[i][j]);
			r[i][j] = a[i][j];
			c[j][i] = a[i][j];
		}
	for (int i = 1;i <= n;i++)
	{
		sort(r[i] + 1,r[i] + m + 1);
		lr[i] = unique(r[i] + 1,r[i] + m + 1) - r[i] - 1;
	}
	for (int i = 1;i <= m;i++)
	{
		sort(c[i] + 1,c[i] + n + 1);
		lc[i] = unique(c[i] + 1,c[i] + n + 1) - c[i] - 1;
	}
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= m;j++)
			printf("%d ",max(cs(r[i],lr[i],a[i][j]),cs(c[j],lc[j],a[i][j])) + max(cb(c[j],lc[j],a[i][j]),cb(r[i],lr[i],a[i][j])) + 1);
	return 0;
}