#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,id;
int first[MAXN];
int a[MAXN];

set<int> ok[MAXN];

void addE(int u,int v)
{
	ok[u].insert(v);
	ok[v].insert(u);
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now,int fa)
{
	for (int i = first[now];i;i = edge[i].next)
	{
		if (edge[i].to == fa)
		{
			ok[now].erase(ok[now].find(fa));
			continue;
		}
		dfs(edge[i].to,now);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1,0);
	int head = 1,tail = 2;
	while (head <= n)
	{
		int now = a[head],t = ok[now].size();
		head++;
		for (int i = 0;i < t;i++)
		{
			if (tail > n || ok[now].find(a[tail]) == ok[now].end())
			{
				cout << "No" << endl;
				return 0;
			}
			ok[now].erase(a[tail]);
			tail++;
		}
	}
	cout << "Yes" << endl;
	return 0;
}