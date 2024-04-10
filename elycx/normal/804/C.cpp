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
#define maxn 300005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, ans, m, cnt;
vector<int> p[maxn], G[maxn];
int color[maxn];
set<int> tmp;
set<int>::iterator it;
void dfs(int x, int fa)
{
	for (int i = 0; i < p[x].size(); i++)
	{
		if(color[p[x][i]]) tmp.erase(color[p[x][i]]);
	}
	for (int i = 0; i < p[x].size(); i++)
	{
		if(!color[p[x][i]])
		{
			it = tmp.begin();
			color[p[x][i]] = (*it);
			tmp.erase(it);
		}
	}
	for (int i = 0; i < p[x].size(); i++) tmp.insert(color[p[x][i]]);
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	int ans = 0;
	p[0].push_back(1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cnt);
		if(cnt > p[ans].size()) ans = i;
		while(cnt--)
		{
			int x;
			scanf("%d", &x);
			p[i].push_back(x);
		}
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i = 1; i <= p[ans].size(); i++) tmp.insert(i);
	dfs(ans, 0);
	printf("%d\n", p[ans].size());
	for (int i = 1; i <= m; i++)
	{
		if(!color[i]) printf("1 ");
		else printf("%d ", color[i]);
	}
	return 0;
}