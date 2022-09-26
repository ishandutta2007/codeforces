#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

const int MAXN = 100005;
const int MAXK = 105;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,m,k,s,id;
int c[MAXN];
int first[MAXN];
int ans[MAXN][MAXK];

bool mark[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void bfs(int p)
{
	memset(mark,0,sizeof(mark));
	queue<int> Q;
	for (int i = 1;i <= n;i++)
	{
		if (c[i] == p)
		{
			ans[i][p] = 0;
			Q.push(i);
		}
		else
			ans[i][p] = (1 << 30) - 1;
	}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		if (mark[now])
			continue;
		mark[now] = true;
		for (int i = first[now];i;i = edge[i].next)
			if (ans[now][p] + 1 < ans[edge[i].to][p])
			{
				ans[edge[i].to][p] = ans[now][p] + 1;
				Q.push(edge[i].to);
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> s;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= k;i++)
		bfs(i);
	for (int i = 1;i <= n;i++)
	{
		sort(ans[i] + 1,ans[i] + k + 1);
		int Ans = 0;
		for (int j = 1;j <= s;j++)
			Ans += ans[i][j];
		cout << Ans << ' ';
	}
	cout << endl;
	return 0;
}