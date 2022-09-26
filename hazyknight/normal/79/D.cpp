#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 10005;
const int MAXM = 20;
const int MAXL = 105;
const int INF = (1 << 30) - 1;

int n,m,l;
int b[MAXN];
int a[MAXL];
int dis[MAXM][MAXN];
int f[1 << MAXM];

queue<int> Q;
vector<int> pos;
vector<int> e[MAXN];

int bitcount(int v)
{
	return v ? bitcount(v - (v & -v)) + 1 : 0;
}

void bfs(int st)
{
	for (int i = 1;i <= n;i++)
		dis[st][i] = INF;
	dis[st][pos[st]] = 0;
	Q.push(pos[st]);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0;i < e[u].size();i++)
			if (dis[st][u] + 1 < dis[st][e[u][i]])
			{
				dis[st][e[u][i]] = dis[st][u] + 1;
				Q.push(e[u][i]);
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> l;
	n++;
	for (int x,i = 1;i <= m;i++)
	{
		cin >> x;
		b[x] = 1;
	}
	for (int i = n;i >= 1;i--)
		b[i] ^= b[i - 1];
	for (int i = 1;i <= n;i++)
		if (b[i])
			pos.push_back(i);
	for (int i = 1;i <= l;i++)
	{
		cin >> a[i];
		for (int j = 1;j + a[i] <= n;j++)
		{
			e[j].push_back(j + a[i]);
			e[j + a[i]].push_back(j);
		}
	}
	for (int i = 0;i < pos.size();i++)
		bfs(i);
	for (int i = 1;i < (1 << (int)pos.size());i++)
	{
		f[i] = INF;
		if (bitcount(i) & 1)
			continue;
		int st = -1;
		for (int j = 0;j < pos.size();j++)
			if (i >> j & 1)
			{
				if (st == -1)
				{
					st = j;
					continue;
				}
				f[i] = min(f[i],f[i ^ (1 << st) ^ (1 << j)] + dis[st][pos[j]]);
			}
	}
	cout << (f[(1 << (int)pos.size()) - 1] == INF ? -1 : f[(1 << (int)pos.size()) - 1]) << endl;
	return 0;
}