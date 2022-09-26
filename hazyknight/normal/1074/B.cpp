#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

const int MAXN = 1005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int T,n,id,ret;
int k1,k2;
int a[MAXN];
int b[MAXN];
int first[MAXN];
int depth[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now,int fa,int d)
{
	depth[now] = d;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
			dfs(edge[i].to,now,d + 1);
}

int main()
{
	cin >> T;
	while (T--)
	{
		memset(first,0,sizeof(first));
		memset(depth,0,sizeof(depth));
		id = 0;
		cin >> n;
		for (int u,v,i = 1;i < n;i++)
		{
			cin >> u >> v;
			addE(u,v);
			addE(v,u);
		}
		cin >> k1;
		for (int i = 1;i <= k1;i++)
			cin >> a[i];
		cin >> k2;
		for (int i = 1;i <= k2;i++)
			cin >> b[i];
		cout << "B " << b[1] << endl;
		cout.flush();
		cin >> ret;
		dfs(ret,0,0);
		int MIN = 0;
		depth[0] = (1 << 30) - 1;
		for (int i = 1;i <= k1;i++)
			if (depth[a[i]] < depth[MIN])
				MIN = a[i];
		cout << "A " << MIN << endl;
		cout.flush();
		cin >> ret;
		bool ok = 0;
		for (int i = 1;i <= k2;i++)
			if (b[i] == ret)
			{
				ok = true;
				break;
			}
		if (ok)
		{
			cout << "C " << MIN << endl;
			cout.flush();
		}
		else
		{
			cout << "C -1" << endl;
			cout.flush();
		}
	}
	return 0;
}