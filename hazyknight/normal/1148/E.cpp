#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXN = 300005;

int n,tot;
int b[MAXN];
int dif[MAXN];
int ans[MAXN][3];

vector<int> pos;
pair<int,int> a[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	for (int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	sort(a + 1,a + n + 1);
	sort(b + 1,b + n + 1);
	for (int i = 1;i <= n;i++)
		dif[i] = a[i].first - b[i];
	for (int i = n;i >= 1;i--)
		if (dif[i] > 0)
			pos.push_back(i);
	for (int i = 1;i <= n;i++)
	{
		if (dif[i] > 0)
		{
			puts("NO");
			return 0;
		}
		if (dif[i] == 0)
			continue;
		while (dif[i] < 0)
		{
			if (!pos.size())
			{
				puts("NO");
				return 0;
			}
			tot++;
			ans[tot][0] = a[i].second;
			ans[tot][1] = a[pos.back()].second;
			ans[tot][2] = min(dif[pos.back()],-dif[i]);
			dif[i] += ans[tot][2];
			dif[pos.back()] -= ans[tot][2];
			if (!dif[pos.back()])
				pos.pop_back();
		}
	}
	printf("YES\n");
	printf("%d\n",tot);
	for (int i = 1;i <= tot;i++)
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}