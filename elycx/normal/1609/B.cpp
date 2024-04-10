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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q;
char s[100005], t[3];
int res = 0;
inline void del(int pos)
{
	if(s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c') res--;
}
inline void add(int pos)
{
	if(s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c') res++;
}
int main()
{
	scanf("%d%d%s", &n, &q, s + 1);
	for (int i = 1; i <= n - 2; i++) add(i);
	for (int i = 1; i <= q; i++)
	{
		int x;
		scanf("%d%s", &x, t);
		for (int j = max(1, x - 2); j <= min(n - 2, x); j++) del(j);
		s[x] = t[0];
		for (int j = max(1, x - 2); j <= min(n - 2, x); j++) add(j);
		printf("%d\n", res);
	}
	return 0;
}