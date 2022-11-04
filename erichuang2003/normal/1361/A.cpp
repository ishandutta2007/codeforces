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

const int MAXN = 500005;

int n,m;
int col[MAXN];

bool vis[MAXN];

pair<int,int> a[MAXN];
vector<int> e[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		int u = a[i].second;
		for (int j = 1;j <= e[u].size() + 1;j++)
			vis[j] = 0;
		for (int j = 0;j < e[u].size();j++)
			vis[col[e[u][j]]] = 1;
		int cur = 0;
		for (int j = 1;j <= e[u].size() + 1;j++)
			if (!vis[j])
			{
				cur = j;
				break;
			}
		col[u] = cur;
		if (cur != a[i].first)
		{
			puts("-1");
			return 0;
		}
	}
	for (int i = 1;i <= n;i++)
		printf("%d ",a[i].second);
	printf("\n");
	return 0;
}