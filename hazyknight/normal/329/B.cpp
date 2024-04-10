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

const int MAXN = 1005;
const int INF = (1 << 30) - 1;

int n,m,ans;
int dis[MAXN][MAXN];

char s[MAXN][MAXN];

queue<pair<int,int> > Q;

void go(int x,int y,int d)
{
	if (x < 1 || x > n || y < 1 || y > m || dis[x][y] <= d || s[x][y] == 'T')
		return;
	dis[x][y] = d;
	Q.push(make_pair(x,y));
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			dis[i][j] = INF;
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s[i] + 1);
		for (int j = 1;j <= m;j++)
			if (s[i][j] == 'E')
			{
				Q.push(make_pair(i,j));
				dis[i][j] = 0;
			}
	}
	while (!Q.empty())
	{
		int x = Q.front().first,y = Q.front().second;
		Q.pop();
		go(x - 1,y,dis[x][y] + 1);
		go(x,y - 1,dis[x][y] + 1);
		go(x + 1,y,dis[x][y] + 1);
		go(x,y + 1,dis[x][y] + 1);
	}
	int yourdist = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == 'S')
				yourdist = dis[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] >= '0' && s[i][j] <= '9' && dis[i][j] <= yourdist)
				ans += s[i][j] - '0';
	printf("%d\n",ans);
	return 0;
}