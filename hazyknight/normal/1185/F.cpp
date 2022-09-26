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

const int MAXN = 1024;
const int INF = 2000000001;

int n,m,f,g,c,mask;
int cnt[MAXN];
int sum[MAXN];

pair<int,int> MIN[MAXN][2];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&f);
		mask = 0;
		for (int j = 1;j <= f;j++)
		{
			scanf("%d",&g);
			mask |= (1 << (g - 1));
		}
		cnt[mask]++;
	}
	for (int i = 0;i < (1 << 9);i++)
		for (int j = i;j;j = (j - 1) & i)
			sum[i] += cnt[j];
	for (int i = 0;i < (1 << 9);i++)
		MIN[i][0] = MIN[i][1] = make_pair(INF,0);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&c,&f);
		mask = 0;
		for (int j = 1;j <= f;j++)
		{
			scanf("%d",&g);
			mask |= (1 << (g - 1));
		}
		if (c <= MIN[mask][0].first)
		{
			MIN[mask][1] = MIN[mask][0];
			MIN[mask][0] = make_pair(c,i);
		}
		else if (c < MIN[mask][1].first)
			MIN[mask][1] = make_pair(c,i);
	}
	pair<int,int> ans = make_pair(0,INF),pos;
	for (int i = 0;i < (1 << 9);i++)
		if (MIN[i][1].first != INF)
		{
			c = MIN[i][0].first + MIN[i][1].first;
			if (sum[i] > ans.first || (sum[i] == ans.first && c < ans.second))
			{
				ans = make_pair(sum[i],c);
				pos = make_pair(MIN[i][0].second,MIN[i][1].second);
			}
		}
	for (int i = 0;i < (1 << 9);i++)
		for (int j = i + 1;j < (1 << 9);j++)
			if (MIN[i][0].first != INF && MIN[j][0].first != INF)
			{
				c = MIN[i][0].first + MIN[j][0].first;
				if (sum[i | j] > ans.first || (sum[i | j] == ans.first && c < ans.second))
				{
					ans = make_pair(sum[i | j],c);
					pos = make_pair(MIN[i][0].second,MIN[j][0].second);
				}
			}
	printf("%d %d\n",pos.first,pos.second);
	return 0;
}