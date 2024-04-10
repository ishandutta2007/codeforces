/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, u, v, id[maxn], d[maxn];
inline bool cmp(int x, int y)
{
	return d[x] < d[y];
}
int k;
set<int> G[maxn];
int vis[maxn];
set<int> p;
set<int>::iterator it;
vector<int> pp[maxn];
vector<int> tmp;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		d[u]++, d[v]++;
		G[u].insert(v), G[v].insert(u);
	}
	if(n - 1 - d[1] < k)
	{
		printf("impossible");
		return 0;
	}
	for (int i = 2; i <= n; i++) p.insert(i);
	queue<int> q;
	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if(!vis[i])
		{
			cnt++;
			q.push(i);
			while(!q.empty())
			{
				int u = q.front();
				vis[u] = cnt;
				pp[cnt].push_back(u);
				q.pop();
				tmp.clear();
				for (it = p.begin(); it != p.end(); it++)
				{
					if(G[u].find(*it) == G[u].end())
					{
						q.push(*it);
						tmp.push_back(*it);
					}
				}
				for (int i = 0; i < tmp.size(); i++) p.erase(tmp[i]);
			}
		}
	}
	if(cnt > k)
	{
		printf("impossible");
		return 0;
	}
	for (int i = 1; i <= cnt; i++)
	{
		int flag = 0;
		for (int j = 0; j < pp[i].size(); j++)
		{
			int V = pp[i][j];
			if(G[1].find(V) == G[1].end()) flag = 1;
		}
		if(!flag)
	{
		printf("impossible");
		return 0;
	}
	}
	printf("possible");
	return 0;
}