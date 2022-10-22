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
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, d, x, y, fa[maxn], cnt = 1, siz[maxn];
multiset<int> t;
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) t.insert(1);
	for (int i = 1; i <= n; i++) siz[i] = 1, fa[i] = i;
	for (int i = 1; i <= d; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if(x != y)
		{
			multiset<int>::iterator pos = t.find(siz[x]);
			t.erase(pos);
			pos = t.find(siz[y]);
			t.erase(pos);
			t.insert(siz[x] + siz[y]);
			fa[x] = y;
			siz[y] += siz[x];
		}
		else cnt++;
		int ans = -1;
		int tmp = cnt;
		for (multiset<int>::iterator it = t.end(); tmp && it != t.begin(); tmp--)
		{
			it--;
			ans += (*it);
		}
		printf("%d\n", ans);
	}
	return 0;
}