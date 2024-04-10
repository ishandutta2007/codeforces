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

const int MAXN = 505;

int n,m;
int fa[MAXN];
int val[MAXN];

char ans[MAXN];

bool G[MAXN][MAXN];
bool exist[MAXN];
bool vis[MAXN];

queue<int> Q;
vector<int> nodes,full;

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void solve(char &st)
{
	full.clear();
	full.push_back(nodes[0]);
	vis[nodes[0]] = 1;
	for (int i = 1;i < nodes.size();i++)
	{
		int u = nodes[i];
		bool ok = 1;
		for (int j = 0;j < full.size();j++)
			if (!G[u][full[j]])
			{
				ok = 0;
				break;
			}
		if (ok)
		{
			full.push_back(u);
			vis[u] = 1;
		}
	}
	for (int i = 0;i < nodes.size();i++)
		fa[nodes[i]] = nodes[i];
	for (int i = 0;i < nodes.size();i++)
	{
		int u = nodes[i];
		if (!vis[u])
			for (int j = 0;j < nodes.size();j++)
			{
				int v = nodes[j];
				if (!vis[v] && G[u][v])
					fa[getroot(u)] = getroot(v);
			}
	}
	int flag = 0;
	for (int i = 0;i < nodes.size();i++)
	{
		int u = nodes[i];
		if (vis[u])
		{
			for (int j = 0;j < nodes.size();j++)
			{
				int v = nodes[j];
				if (!vis[v] && G[u][v])
				{
					if (!flag)
						flag = getroot(v);
					if (flag == getroot(v))
						val[u] = 26;
					break;
				}
			}
			if (!val[u])
				val[u] = 25;
			Q.push(u);
		}
	}
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0;i < nodes.size();i++)
		{
			int v = nodes[i];
			if (!vis[v] && G[u][v])
			{
				val[v] = val[u] + (getroot(v) == flag ? 1 : -1);
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
	for (int i = 0;i < nodes.size();i++)
		for (int j = 0;j < nodes.size();j++)
			if (i != j)
			{
				int u = nodes[i],v = nodes[j];
				if (!G[u][v] && abs(val[u] - val[v]) <= 1)
				{
					puts("No");
					exit(0);
				}
			}
	int MN = 1e9,MX = 0;
	for (int i = 0;i < nodes.size();i++)
	{
		int u = nodes[i];
		MN = min(MN,val[u]);
		MX = max(MX,val[u]);
	}
	for (int i = 0;i < nodes.size();i++)
	{
		int u = nodes[i];
		char t = st + val[u] - MN;
		if (t > 'c')
		{
			puts("No");
			exit(0);
		}
		ans[u] = t;
	}
	st = st + MX - MN + 2;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u][v] = G[v][u] = 1;
		fa[getroot(u)] = getroot(v);
	}
	char st = 'a';
	for (int i = 1;i <= n;i++)
		if (!vis[i])
		{
			nodes.clear();
			for (int j = 1;j <= n;j++)
				if (getroot(j) == getroot(i))
					nodes.push_back(j);
			solve(st);
		}
	puts("Yes");
	for (int i = 1;i <= n;i++)
		putchar(ans[i]);
	putchar('\n');	
	return 0;
}