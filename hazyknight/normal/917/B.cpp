#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <stack>
#include <set>

using namespace std;

const int MAXN = 105;
const int MAXM = 5005;

struct Edge
{
	int to;
	int c;
	int next;
}edge[MAXM];

int n,m,id;
int first[MAXN];
int f[MAXN][MAXN][26];

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
}

int dfs(int i,int j,int lim)
{
	if (f[i][j][lim] != -1)
		return f[i][j][lim];
	for (int k = first[i];k;k = edge[k].next)
		if (edge[k].c >= lim && dfs(j,edge[k].to,edge[k].c) == 1)
			return f[i][j][lim] = 0;
	return f[i][j][lim] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		char c;
		int u,v;
		cin >> u >> v >> c;
		addE(u,v,c - 'a');
	}
	memset(f,-1,sizeof(f));
	for (int i = 1;i <= n;i++,cout << endl)
		for (int j = 1;j <= n;j++)
		{
			if (f[i][j][0] == -1)
				dfs(i,j,0);
			cout << (f[i][j][0] ? 'B' : 'A');
		}
	return 0;
}