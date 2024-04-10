#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int from;
	int to;
	int next;
}edge[MAXN << 1];

int n,m,h,id,c,d,cct;
int first[MAXN];
int v[MAXN];
int dfn[MAXN];
int low[MAXN];
int belong[MAXN];
int degree[MAXN];

stack<int> S;
vector<int> cc[MAXN];

bool vis[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){u,v,first[u]};
	first[u] = id;
}

void dfs(int now)
{
	dfn[now] = low[now] = ++id;
	S.push(now);
	vis[now] = true;
	for (int i = first[now];i;i = edge[i].next)
	{
		if (!dfn[edge[i].to])
		{
			dfs(edge[i].to);
			low[now] = min(low[now],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[now] = min(low[now],dfn[edge[i].to]);
	}
	if (low[now] == dfn[now])
	{
		cct++;
		while (S.top() != now)
		{
			vis[S.top()] = false;
			belong[S.top()] = cct;
			cc[cct].push_back(S.top());
			S.pop();
		}
		vis[now] = false;
		belong[now] = cct;
		cc[cct].push_back(now);
		S.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> h;
	for (int i = 1;i <= n;i++)
		cin >> v[i];
	for (int j = 1;j <= m;j++)
	{
		cin >> c >> d;
		if ((v[c] + 1) % h == v[d])
			addE(c,d);
		if (v[c] == (v[d] + 1) % h)
			addE(d,c);
	}
	id = 0;
	for (int i = 1;i <= n;i++)
		if (!dfn[i])
			dfs(i);
	for (int i = 1;i <= m;i++)
		if (belong[edge[i].from] != belong[edge[i].to])
			degree[belong[edge[i].from]]++;
	int MIN = n + 1,id = 0;
	for (int i = 1;i <= cct;i++)
		if (!degree[i])
		{
			if (MIN > cc[i].size())
				MIN = cc[i].size(),id = i;
		}
	cout << MIN << endl;
	for (int i = 0;i < cc[id].size();i++)
		cout << cc[id][i] << ' ';
	cout << endl;
	return 0;
}