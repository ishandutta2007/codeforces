#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <vector>

using namespace std;

struct Edge
{
	int to;
	int next;
}edge[1200005];

int n,m,q,id,ans;
int first[600005];

vector<int> x[200005];
vector<int> y[200005];

bool mark[600005];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now)
{
	if (mark[now])
		return;
	mark[now] = true;
	for (int i = first[now];i;i = edge[i].next)
		dfs(edge[i].to);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int xx,yy,i = 1;i <= q;i++)
		cin >> xx >> yy,x[xx].push_back(i + n + m),y[yy].push_back(i + n + m);
	for (int i = 1;i <= n;i++)
	{
		int pre = i;
		for (int j = 0;j < x[i].size();j++)
			addE(pre,x[i][j]),addE(x[i][j],pre),pre = x[i][j];
	}
	for (int i = 1;i <= m;i++)
	{
		int pre = n + i;
		for (int j = 0;j < y[i].size();j++)
			addE(pre,y[i][j]),addE(y[i][j],pre),pre = y[i][j];
	}
	for (int i = 1;i <= n + m + q;i++)
		if (!mark[i])
			ans++,dfs(i);
	cout << ans - 1 << endl;
	return 0;
}