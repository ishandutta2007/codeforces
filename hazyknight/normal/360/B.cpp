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

const int MAXN = 2005;

int n,m;
int a[MAXN];
int f[MAXN];

bool ok(int v)
{
	for (int i = 1;i <= n;i++)
		f[i] = 1;
	for (int i = 1;i < n;i++)
		for (int j = i + 1;j <= n;j++)
			if ((long long)v * (j - i) >= abs(a[i] - a[j]))
				f[j] = max(f[j],f[i] + 1);
	for (int i = 1;i <= n;i++)
		if (f[i] >= n - m)
			return 1;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	int low = 0,high = 2e9;
	while (low < high)
	{
		int mid = low + ((high - low) >> 1);
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n",low);
	return 0;
}