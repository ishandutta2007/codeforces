/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

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
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 4000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, u, v, tot, dep[maxn];
char s[2];
int ch[maxn][26], siz[maxn];
int ans[maxn];
int merge(int x, int y)
{
	if(!x || !y) return x + y;
	int tmp = ++tot;
	siz[tmp] = 1;
	for (int i = 0; i < 26; i++)
	{
		ch[tmp][i] = merge(ch[x][i], ch[y][i]);
		siz[tmp] += siz[ch[tmp][i]];
	}
	return tmp;
}
void dfs(int x)
{
	siz[x] = 1;
	for (int i = 0; i < 26; i++)
	{
		int V = ch[x][i];
		if(!V) continue;
		dep[V] = dep[x] + 1;
		dfs(V);
		siz[x] += siz[V];
	}
}
void work(int x)
{
//	printf("%d\n", x);
	int tmp = ++tot;
	siz[tmp] = 1;
	for (int i = 0; i < 26; i++)
	{
		int V = ch[x][i];
		if(!V) continue;
		tmp = merge(tmp, V);
	}
	ans[dep[x]] += siz[x] - siz[tmp];
	for (int i = 0; i < 26; i++)
	{
		int V = ch[x][i];
		if(V) work(V);
	}
}
int main()
{
	scanf("%d", &n);
	tot = n;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%s", &u, &v, s);
		ch[u][s[0] - 'a'] = v;
	}
	dfs(1);
	work(1);
	int res = 0;
	for (int i = 0; i <= n; i++)
	{
		if(ans[i] > ans[res]) res = i;
	}
	printf("%d\n%d", n - ans[res], res + 1);
	return 0;
}