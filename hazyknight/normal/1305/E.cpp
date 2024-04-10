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

int n,m;
int ans[MAXN];
int sum[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	int cnt = 0,ed = 0;
	for (int i = 1;i <= n;i++)
	{
		if (cnt + (i - 1) / 2 > m)
		{
			int l = m - cnt;
			ans[i] = 2 * i - 2 * l - 1;
			cnt = m;
			break;
		}
		ans[i] = i;
		cnt += (i - 1) / 2;
	}
	if (cnt < m)
	{
		puts("-1");
		return 0;
	}
	int tot = n,MAX = 0;
	for (int i = 1;i <= n;i++)
		if (ans[i])
		{
			printf("%d ",ans[i]);
			MAX = ans[i];
			tot--;
		}
	while (tot--)
		printf("%d ",1000000000 - tot * (MAX + 1));
	printf("\n");
	return 0;
}