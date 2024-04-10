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

const int MAXL = 55;
const int MAXN = 1005;
const int INF = 1e9;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN * MAXN];

int T,n,m,ide,tot,N;
int fa[MAXN];
int u[MAXN];
int v[MAXN];
int pre[MAXN];
int dis[MAXN];
int first[MAXN];
int deg[MAXL][MAXL];

char s[MAXL][MAXL];
char ans[MAXL][MAXL];

bool vis[MAXN];
bool inqueue[MAXN];
bool spe[MAXN];

queue<int> Q;

void addE(int u,int v)
{
	if (spe[u] || spe[v])
		return;
	edge[++ide] = (Edge){v,first[u]};
	first[u] = ide;
}

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

bool in(int x,int y)
{
	return x >= 1 && x < n && y >= 1 && y < m;
}

bool In(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m && (~(x + y) & 1) && (x != 1 || y != 1) && s[x][y] != 'X';
}

bool ok(int x,int y)
{
	return s[x][y] == 'O';
}

int id(int x,int y)
{
	return x * (m + 1) + y + 1;
}

pair<int,int> get(int ID)
{
	return make_pair((ID - 1) / (m + 1),(ID - 1) % (m + 1));
}

void getbl(int u,int v,pair<int,int> &c1,pair<int,int> &c2)
{
	pair<int,int> r1 = get(u),r2 = get(v);
	if (r1.first == r2.first)
	{
		c1 = make_pair(r1.first,r1.second + 1);
		c2 = make_pair(r1.first + 1,r1.second + 1);
	}
	else
	{
		c1 = make_pair(r1.first + 1,r1.second);
		c2 = make_pair(r1.first + 1,r1.second + 1);
	}
}

void add0(int u,int v)
{
	fa[getroot(u)] = getroot(v);
}

void add1(int u,int v)
{
	pair<int,int> c1,c2;
	getbl(u,v,c1,c2);
	if (In(c1.first,c1.second))
		deg[c1.first][c1.second]--;
	if (In(c2.first,c2.second))
		deg[c2.first][c2.second]--;
}

bool ok0(int u,int v)
{
	return getroot(u) != getroot(v);
}

bool ok1(int u,int v)
{
	pair<int,int> c1,c2;
	getbl(u,v,c1,c2);
	if (In(c1.first,c1.second) && deg[c1.first][c1.second] <= 2)
		return 0;
	if (In(c2.first,c2.second) && deg[c2.first][c2.second] <= 2)
		return 0;
	return 1;
}

void print()
{
	for (int i = 1;i <= 2 * n - 1;i++)
		for (int j = 1;j <= 2 * m - 1;j++)
			if ((i & 1) || (j & 1))
				ans[i][j] = 'O';
			else
				ans[i][j] = ' ';
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == 'X')
			{
				ans[2 * i - 1][2 * j - 1] = 'X';
				ans[2 * i - 2][2 * j - 1] = ' ';
				ans[2 * i - 1][2 * j - 2] = ' ';
				ans[2 * i][2 * j - 1] = ' ';
				ans[2 * i - 1][2 * j] = ' ';
			}
	for (int i = 1;i <= tot;i++)
		if (vis[i])
		{
			pair<int,int> c1 = get(u[i]),c2 = get(v[i]);
			if (!in(c1.first,c1.second) && !in(c2.first,c2.second))
				continue;
			if (c1.first == c2.first)
				ans[2 * c1.first][2 * c1.second + 1] = ' ';
			else
				ans[2 * c1.first + 1][2 * c2.second] = ' ';
		}
	puts("YES");
	for (int i = 1;i <= 2 * n - 1;i++,putchar('\n'))
		for (int j = 1;j <= 2 * m - 1;j++)
			putchar(ans[i][j]);
}

bool mat_inter()
{
	while (1)
	{
		memset(first,0,sizeof(first));
		ide = 0;
		for (int i = 1;i <= tot + 1;i++)
			if ((vis[i] || i == tot + 1) && !spe[i])
			{
				for (int j = 1;j <= N;j++)
					fa[j] = j;
				for (int j = 1;j <= n;j++)
					for (int k = 1;k <= m;k++)
						deg[j][k] = 4;
				for (int j = 1;j <= tot;j++)
					if (j != i && vis[j])
					{
						add0(u[j],v[j]);
						if (!ok1(u[j],v[j]))
							return 0;
						add1(u[j],v[j]);
					}
				for (int j = 1;j <= tot;j++)
					if (!vis[j])
					{
						if (ok0(u[j],v[j]))
						{
							if (i == tot + 1)
								addE(0,j);
							else
								addE(i,j);
						}
						if (ok1(u[j],v[j]))
						{
							if (i == tot + 1)
								addE(j,tot + 1);
							else
								addE(j,i);
						}
					}
			}
		Q.push(0);
		inqueue[0] = 1;
		for (int i = 1;i <= tot + 1;i++)
			dis[i] = INF;
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inqueue[u] = 0;
			for (int i = first[u],to = edge[i].to;i;i = edge[i].nxt,to = edge[i].to)
				if (dis[u] + 1 < dis[to])
				{
					dis[to] = dis[u] + 1;
					pre[to] = u;
					if (!inqueue[to])
					{
						Q.push(to);
						inqueue[to] = 1;
					}
				}
		}
		if (dis[tot + 1] == INF)
			break;
		int cur = pre[tot + 1];
		while (cur)
		{
			vis[cur] ^= 1;
			cur = pre[cur];
		}
	}
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		memset(spe,0,sizeof(spe));
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			scanf("%s",s[i] + 1);
		tot = 0;
		for (int i = 0;i <= n;i++)
			for (int j = 0;j <= m;j++)
			{
				if (i + 1 <= n)
				{
					u[++tot] = id(i,j);
					v[tot] = id(i + 1,j);
					if (!ok(i + 1,j + 1) || !ok(i + 1,j))
						spe[tot] = vis[tot] = 1;
				}
				if (j + 1 <= m)
				{
					u[++tot] = id(i,j);
					v[tot] = id(i,j + 1);
					if (!ok(i + 1,j + 1) || !ok(i,j + 1))
						spe[tot] = vis[tot] = 1;
				}
			}
		N = id(n,m);
		if (!mat_inter())
		{
			puts("NO");
			continue;
		}
		int cnt = 0;
		for (int i = 1;i <= N;i++)
			fa[i] = i;
		for (int i = 1;i <= tot;i++)
			if (vis[i] && getroot(u[i]) != getroot(v[i]))
			{
				cnt++;
				fa[getroot(u[i])] = getroot(v[i]);
			}
		if (cnt != N - 1)
		{
			puts("NO");
			continue;
		}
		print();
	}
	return 0;
}