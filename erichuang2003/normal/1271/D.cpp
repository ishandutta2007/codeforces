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

int n,m,k;
int f[MAXN][MAXN];
int MAX[MAXN];
int a[MAXN];
int b[MAXN];
int c[MAXN];

vector<int> dt[MAXN];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for (int i = 1;i <= n;i++)
		MAX[i] = i;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		MAX[v] = max(MAX[v],u);
	}
	for (int i = 1;i <= n;i++)
		dt[MAX[i]].push_back(i);
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= 5001;j++)
			f[i][j] = -1e9;
	f[0][k] = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = a[i] + b[i];j <= 5000;j++)
			f[i][j] = f[i - 1][j - b[i]];
		for (int j = 0;j < dt[i].size();j++)
		{
			int to = dt[i][j];
			for (int k = 0;k <= 5000;k++)
				f[i][k] = max(f[i][k],f[i][k + 1] + c[to]);
		}
	}
	int ans = -1e9;
	for (int i = 0;i <= 5000;i++)
		ans = max(ans,f[n][i]);
	if (ans < 0)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}