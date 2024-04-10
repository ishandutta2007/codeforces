#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

struct Point
{
	int x,y;
	
	bool operator < (const Point &a)const
	{
		return x < a.x;
	}
}p[MAXN];

int n;
int preMIN[MAXN];
int preMAX[MAXN];
int sufMIN[MAXN];
int sufMAX[MAXN];

bool ok(ll lim)
{
	for (int i = 1,j = 1;i <= n;i++)
	{
		while (j <= i && (-p[j].x > p[i].x || (ll)(p[i].x - p[j].x) * (p[i].x - p[j].x) > lim))
			j++;
		while (j - 1 >= 1 && -p[j - 1].x <= p[i].x && (ll)(p[i].x - p[j - 1].x) * (p[i].x - p[j - 1].x) <= lim)
			j--;
		int MN = min(preMIN[j - 1],sufMIN[i + 1]),MX = max(preMAX[j - 1],sufMAX[i + 1]);
		if (i - j + 1 == n || ((ll)(MX - MN) * (MX - MN) <= lim && (j > i || max((ll)MN * MN,(ll)MX * MX) + (ll)p[i].x * p[i].x <= lim)))
			return 1;
	}
	for (int i = n,j = n;i >= 1;i--)
	{
		while (j >= i && (-p[j].x < p[i].x || (ll)(p[j].x - p[i].x) * (p[j].x - p[i].x) > lim))
			j--;
		while (j + 1 <= n && -p[j + 1].x >= p[i].x && (ll)(p[j + 1].x - p[i].x) * (p[j + 1].x - p[i].x) <= lim)
			j++;
		int MN = min(preMIN[i - 1],sufMIN[j + 1]),MX = max(preMAX[i - 1],sufMAX[j + 1]);
		if (j - i + 1 == n || ((ll)(MX - MN) * (MX - MN) <= lim && (j < i || max((ll)MN * MN,(ll)MX * MX) + (ll)p[i].x * p[i].x <= lim)))
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p + 1,p + n + 1);
	preMIN[0] = sufMIN[n + 1] = 1e9;
	preMAX[0] = sufMAX[n + 1] = -1e9;
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
	ll low = 0,high = 1e18;
	while (low < high)
	{
		ll mid = low + high >> 1;
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%lld\n",low);
	return 0;
}