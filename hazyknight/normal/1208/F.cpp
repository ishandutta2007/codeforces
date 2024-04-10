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

int n,ans;
int a[MAXN];
int MAX1[MAXN];
int MAX2[MAXN];

void update(int p,int v)
{
	if (v == MAX1[p] || v == MAX2[p])
		return;
	if (v > MAX1[p])
	{
		MAX2[p] = MAX1[p];
		MAX1[p] = v;
	}
	else if (v > MAX2[p])
		MAX2[p] = v;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		update(a[i],i);
	}
	for (int i = 2000000;i >= 1;i--)
		for (int j = 0;j <= 20;j++)
			if (i >> j & 1)
			{
				update(i ^ (1 << j),MAX1[i]);
				update(i ^ (1 << j),MAX2[i]);
			}
	for (int i = 1;i <= n - 2;i++)
	{
		int cur = 0,tmp = 0;
		for (int j = 20;j >= 0;j--)
		{
			tmp += (a[i] >> j & 1) << j;
			cur += 1 << j;
			if (MAX2[cur ^ tmp] <= i)
				cur -= 1 << j;
		}
		ans = max(ans,cur);
	}
	printf("%d\n",ans);
	return 0;
}