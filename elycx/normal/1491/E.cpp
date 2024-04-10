/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, x, y, vis[maxn];
vector<int> G[maxn], flag[maxn];
int f[maxn], id[maxn], siz[maxn], fa[maxn];
int tmp[maxn], cnt;
void dfs(int x)
{
	tmp[++cnt] = x;
	vis[x] = 1;
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		if(flag[x][i]) continue;
		int V = G[x][i];
		if(vis[V]) continue;
		fa[V] = x;
		dfs(V);
		siz[x] += siz[V];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) id[i] = -1;
	f[0] = f[1] = 1;
	id[1] = 1;
	for (int i = 2; i <= 30; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] > n) break;
		id[f[i]] = i;
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		flag[x].push_back(0);
		G[y].push_back(x);
		flag[y].push_back(0);
	}
	for (int o = 1; o <= 30; o++)
	{
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			cnt = 0;
			dfs(i);
			if(id[siz[i]] == -1)
			{
				printf("NO");
				return 0;
			}
			if(siz[i] <= 2) continue;
			int f2 = 0;
			for (int k = 1; k <= cnt; k++)
			{
				if(id[siz[tmp[k]]] == id[siz[i]] - 1 || id[siz[tmp[k]]] == id[siz[i]] - 2)
				{
					f2 = 1;
					for (int j = 0; j < G[tmp[k]].size(); j++) 
					{
						int V = G[tmp[k]][j];
						if(V == fa[tmp[k]]) flag[tmp[k]][j] = 1;
					}
					for (int j = 0; j < G[fa[tmp[k]]].size(); j++) 
					{
						int V = G[fa[tmp[k]]][j];
						if(V == tmp[k]) flag[fa[tmp[k]]][j] = 1;
					}
					break;
				}
			}
			if(!f2)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}