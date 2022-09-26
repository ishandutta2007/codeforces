#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 300005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,ans,id;
int first[MAXN];
int a[MAXN];
int cnt[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(v,u);
	}
	for (int i = n;i >= 1;i--)
	{
		if (cnt[a[i]] == n - i - ans && i != n)
			ans++;
		else
		{
			for (int j = first[a[i]];j;j = edge[j].nxt)
				cnt[edge[j].to]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}