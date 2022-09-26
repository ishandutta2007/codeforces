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

const int MAXN = 1005;

int n;
int x[MAXN];
int y[MAXN];
int col[MAXN];

ll dis[MAXN][MAXN];

vector<int> ans;
vector<int> e[MAXN];

void dfs(int u,int c)
{
	if (~col[u])
		return;
	col[u] = c;
	if (!col[u])
		ans.push_back(u);
	for (int i = 0;i < e[u].size();i++)
		dfs(e[u][i],c ^ 1);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&x[i],&y[i]);
	ll MIN = (1ll << 60);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
		{
			dis[i][j] = (ll)(x[i] - x[j]) * (x[i] - x[j]) + (ll)(y[i] - y[j]) * (y[i] - y[j]);
			if (dis[i][j])
				MIN = min(MIN,dis[i][j] & -dis[i][j]);
		}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			dis[i][j] /= MIN;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (dis[i][j] & 1)
			{
				e[i].push_back(j);
				e[j].push_back(i);
			}
	memset(col,-1,sizeof(col));
	for (int i = 1;i <= n;i++)
		if (col[i] == -1)
			dfs(i,0);
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}