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

const int MAXN = 1005;

int n,m;

bool vis[MAXN][MAXN];

char s[MAXN][MAXN];

void dfs(int x,int y)
{
	if (x < 1 || y < 1 || x > n || y > m || vis[x][y] || s[x][y] == '.')
		return;
	vis[x][y] = 1;
	dfs(x - 1,y);
	dfs(x,y - 1);
	dfs(x + 1,y);
	dfs(x,y + 1);
}

int main()
{
	scanf("%d%d",&n,&m);
	bool emptyrow = 0,emptycol = 0;
	for (int i = 1;i <= n;i++)
		scanf("%s",s[i] + 1);
	for (int i = 1;i <= n;i++)
	{
		bool ok = 0;
		for (int j = 1;j <= m;j++)
			if (s[i][j] == '#')
				ok = 1;
		if (!ok)
			emptyrow = 1;
	}
	for (int i = 1;i <= m;i++)
	{
		bool ok = 0;
		for (int j = 1;j <= n;j++)
			if (s[j][i] == '#')
				ok = 1;
		if (!ok)
			emptycol = 1;
	}
	if (emptyrow ^ emptycol)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		int L = 0,R = 0;
		for (int j = 1;j <= m;j++)
			if (s[i][j] == '#')
			{
				L = j;
				break;
			}
		for (int j = m;j >= 1;j--)
			if (s[i][j] == '#')
			{
				R = j;
				break;
			}
		if (!L)
			continue;
		for (int j = L;j <= R;j++)
			if (s[i][j] != '#')
			{
				puts("-1");
				return 0;
			}
	}
	for (int i = 1;i <= m;i++)
	{
		int L = 0,R = 0;
		for (int j = 1;j <= n;j++)
			if (s[j][i] == '#')
			{
				L = j;
				break;
			}
		for (int j = n;j >= 1;j--)
			if (s[j][i] == '#')
			{
				R = j;
				break;
			}
		if (!L)
			continue;
		for (int j = L;j <= R;j++)
			if (s[j][i] != '#')
			{
				puts("-1");
				return 0;
			}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (!vis[i][j] && s[i][j] == '#')
			{
				ans++;
				dfs(i,j);
			}
	printf("%d\n",ans);
    return 0;
}