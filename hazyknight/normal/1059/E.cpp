#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector> 
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n,L,ans;
int w[MAXN];
int top[MAXN];
int depth[MAXN];
int fa[MAXN][20];

ll S;
ll sum[MAXN][20];

bool isleaf[MAXN];
bool mark[MAXN];

priority_queue<pair<pair<int,int>,int> > Q;

int main()
{
	scanf("%d%d%I64d",&n,&L,&S);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&w[i]);
		isleaf[i] = true;
		if (w[i] > S)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 2;i <= n;i++)
	{
		scanf("%d",&fa[i][0]);
		isleaf[fa[i][0]] = false;
		depth[i] = depth[fa[i][0]] + 1;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 16;j++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for (int i = 1;i <= n;i++)
	{
		sum[i][0] = w[fa[i][0]];
		for (int j = 1;j <= 16;j++)
			sum[i][j] = sum[i][j - 1] + sum[fa[i][j - 1]][j - 1];
	}
	for (int i = 1;i <= n;i++)
	{
		int cur = i;
		ll l = 1,s = w[i];
		for (int j = 16;j >= 0;j--)
			if (fa[cur][j] && l + (1 << j) <= L && s + sum[cur][j] <= S)
			{
				l += (1 << j);
				s += sum[cur][j];
				cur = fa[cur][j];
			}
		top[i] = cur;
	}
	for (int i = 1;i <= n;i++)
		if (isleaf[i])
			Q.push({{depth[i],depth[top[i]]},i});
	while (!Q.empty())
	{
		int now = Q.top().second,tar = top[now];
		Q.pop();
		if (mark[now])
			continue;
		ans++;
		while (!mark[now] && now != tar)
		{
			mark[now] = true;
			now = fa[now][0];
		}
		mark[tar] = true;
		if (fa[tar][0])
			Q.push({{depth[fa[tar][0]],depth[top[fa[tar][0]]]},fa[tar][0]});
	}
	printf("%d\n",ans);
	return 0;
}