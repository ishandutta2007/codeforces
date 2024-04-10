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
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int to;
	int cst;
	int nxt;
}edge[MAXN << 1];

int n,m,id;
int first[MAXN];
int od[MAXN];
int deg[MAXN];

bool mark[MAXN];
bool vis[MAXN];

queue<int> Q;
vector<int> ans;

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
}

bool dfs(int u,int l)
{
	vis[u] = mark[u] = true;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (edge[i].cst <= l)
			continue;
		if (!vis[edge[i].to])
		{
			if (dfs(edge[i].to,l))
				return true;
		}
		else if (mark[edge[i].to])
			return true;
	}
	mark[u] = false;
	return false;
}

void topo(int l)
{
	for (int i = 1;i <= n;i++)
		for (int j = first[i];j;j = edge[j].nxt)
			if (edge[j].cst > l)
				deg[edge[j].to]++;
	for (int i = 1;i <= n;i++)
		if (!deg[i])
			Q.push(i);
	id = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		od[u] = ++id;
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cst > l)
			{
				deg[edge[i].to]--;
				if (!deg[edge[i].to])
					Q.push(edge[i].to);
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u,v,c,i = 1;i <= m;i++)
	{
		cin >> u >> v >> c;
		addE(u,v,c);
	}
	int low = 0,high = 1000000000;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		memset(vis,0,sizeof(vis));
		bool ok = true;
		for (int i = 1;i <= n;i++)
			if (!vis[i] && dfs(i,mid))
			{
				ok = false;
				break;
			}
		if (ok)
			high = mid;
		else
			low = mid + 1;
	}
	topo(low);
	for (int i = 1;i <= n;i++)
		for (int j = first[i];j;j = edge[j].nxt)
			if (od[i] > od[edge[j].to])
				ans.push_back(j);
	cout << low << ' ' << ans.size() << endl;
	sort(ans.begin(),ans.end());
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}