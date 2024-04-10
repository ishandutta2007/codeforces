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

const int MAXN = 500005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXN << 1];

int T,n,k,id;
int first[MAXN];

ll f[MAXN][2];

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	vector<ll> dif;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u);
			f[u][0] += f[edge[i].to][0];
			dif.push_back(f[edge[i].to][1] + edge[i].w - f[edge[i].to][0]);
		}
	sort(dif.begin(),dif.end());
	reverse(dif.begin(),dif.end());
	f[u][1] = f[u][0];
	int K = k;
	for (int i = 0;K && i < dif.size();i++)
	{
		if (dif[i] <= 0)
			break;
		f[u][0] += dif[i];
		K--;
	}
	K = k - 1;
	for (int i = 0;K && i < dif.size();i++)
	{
		if (dif[i] <= 0)
			break;
		f[u][1] += dif[i];
		K--;
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		id = 0;
		for (int i = 1;i <= n;i++)
			first[i] = f[i][0] = f[i][1] = 0;
		for (int u,v,w,i = 1;i < n;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addE(u,v,w);
			addE(v,u,w);
		}
		dfs(1,0);
		printf("%lld\n",f[1][0]);
	}
	return 0;
}