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

const int MAXN = 100005;

int n,m;
int l[MAXN];
int ans[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
		scanf("%d",&l[i]);
	int cur = n;
	for (int i = m;i >= 1;i--)
	{
		cur = min(cur - 1,n - l[i]);
		ans[i] = cur + 1;
		if (!ans[i])
		{
			puts("-1");
			return 0;
		}
	}
	l[0] = 1;
	for (int i = 1;i <= m;i++)
		ans[i] = min(ans[i],ans[i - 1] + l[i - 1]);
	if (ans[m] + l[m] - 1 < n)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1;i <= m;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}