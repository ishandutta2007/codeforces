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

typedef long long ll;

const int MAXN = 100005;

struct Vector
{
	ll x,y;
	
	bool operator < (const Vector &p)const
	{
		return x < p.x;
	}
}p[MAXN];

int n;

ll preMIN[MAXN];
ll preMAX[MAXN];
ll sufMIN[MAXN];
ll sufMAX[MAXN];

bool ok(ll len)
{
	for (int i = 1,j = 0;i <= n;i++)
	{
		while (j + 1 <= n && p[j + 1].x <= p[i].x + len)
			j++;
		if (max(preMAX[i - 1],sufMAX[j + 1]) - min(preMIN[i - 1],sufMIN[j + 1]) <= len)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for (int x,y,i = 1;i <= n;i++)
	{
		scanf("%d%d",&x,&y);
		p[i].x = x + y;
		p[i].y = x - y;
	}
	sort(p + 1,p + n + 1);
	preMIN[0] = 4e9;
	preMAX[0] = -4e9;
	sufMIN[n + 1] = 4e9;
	sufMAX[n + 1] = -4e9;
	for (int i = 1;i <= n;i++)
	{
		preMIN[i] = min(preMIN[i - 1],p[i].y);
		preMAX[i] = max(preMAX[i - 1],p[i].y);
	}
	for (int i = n;i >= 1;i--)
	{
		sufMIN[i] = min(sufMIN[i + 1],p[i].y);
		sufMAX[i] = max(sufMAX[i + 1],p[i].y);
	}
	ll low = 0,high = 4e9;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%.10lf\n",(double)low / 2);
	return 0;
}