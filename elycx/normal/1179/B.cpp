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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
int a[maxn];
int vis[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= (n + 1) / 2; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(vis[(i - 1) * m + j - 1]) return 0;
			printf("%d %d\n", i, j);
			vis[(i - 1) * m + j - 1] = 1;
			if(vis[(n - i) * m + (m - j)]) return 0;
			printf("%d %d\n", n - i + 1, m - j + 1);
			vis[(n - i) * m + (m - j)] = 1;
		}
	}
	return 0;
}