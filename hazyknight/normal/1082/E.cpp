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
#include <iomanip>

using namespace std;

const int MAXN = 500005;

int n,c,ans;
int sum[MAXN];

vector<int> pos[MAXN];

int main()
{
	scanf("%d%d",&n,&c);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		pos[a].push_back(i);
		sum[i] = sum[i - 1] + (a == c);
	}
	ans = sum[n];
	for (int i = 1;i <= 500000;i++)
	{
		if (i == c || !pos[i].size())
			continue;
		int k = 0,MAX = sum[pos[i][0] - 1] + 1;
		ans = max(ans,sum[n] + 1);
		for (int j = 1;j < pos[i].size();j++)
		{
			MAX++;
			MAX = max(MAX,sum[pos[i][j] - 1] + 1);
			ans = max(ans,MAX + sum[n] - sum[pos[i][j]]);
		}
	}
	printf("%d\n",ans);
	return 0;
}