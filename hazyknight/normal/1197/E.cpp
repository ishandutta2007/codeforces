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

const int MAXN = 400005;
const int MOD = 1000000007;

int n,sum,MIN;
int f[MAXN];
int MN[MAXN];
int dis[MAXN];

pair<int,int> a[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&a[i].second,&a[i].first);
	sort(a + 1,a + n + 1);
	for (int i = 1,j = 0;i <= n;i++)
	{
		while (j + 1 < i && a[j + 1].second <= a[i].first)
		{
			j++;
			if (dis[j] < MIN)
			{
				MIN = dis[j];
				sum = f[j];
			}
			else if (dis[j] == MIN)
				(sum += f[j]) %= MOD;
		}
		dis[i] = MIN + a[i].first - a[i].second;
		f[i] = sum + !MIN;
	}
	sum = 0;
	MIN = 1e9;
	for (int i = 1;i <= n;i++)
		if (a[i].second > a[n].first)
			MIN = min(MIN,dis[i] + a[i].second);
	for (int i = 1;i <= n;i++)
		if (a[i].second > a[n].first && dis[i] + a[i].second == MIN)
			(sum += f[i]) %= MOD;
	printf("%d\n",sum);
	return 0;
}