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

typedef double db;

const int MAXN = 200005;
const db INF = 2e9;

int n;
int a[MAXN];

db check(db x)
{
	db MIN = 1e18,MAX = -1e18,sum = 0;
	for (int i = 1;i <= n;i++)
	{
		sum = max(0.,sum + a[i] - x);
		MAX = max(MAX,sum);
	}
	sum = 0;
	for (int i = 1;i <= n;i++)
	{
		sum = min(0.,sum + a[i] - x);
		MIN = min(MIN,sum);
	}
	return max(fabs(MIN),fabs(MAX));
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	db low = -INF,high = INF;
	for (int i = 1;i <= 200;i++)
	{
		db mid1 = low + (high - low) / 3,mid2 = high - (high - low) / 3;
		if (check(mid1) > check(mid2))
			low = mid1;
		else
			high = mid2;
	}
	printf("%.7lf\n",check(low));
	return 0;
}