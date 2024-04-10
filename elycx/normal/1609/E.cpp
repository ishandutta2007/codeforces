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
int n, q;
char s[maxn];
int t[maxn * 4][6];
void pushup(int x)
{
	for (int i = 0; i < 3; i++) t[x][i] = t[lc(x)][i] + t[rc(x)][i];
	t[x][3] = min(t[lc(x)][0] + t[rc(x)][3], t[lc(x)][3] + t[rc(x)][1]);
	t[x][4] = min(t[lc(x)][1] + t[rc(x)][4], t[lc(x)][4] + t[rc(x)][2]);
	t[x][5] = min(min(t[lc(x)][5] + t[rc(x)][2], t[lc(x)][0] + t[rc(x)][5]), t[lc(x)][3] + t[rc(x)][4]);
}
void build(int x, int l, int r)
{
	if(l == r)
	{
		t[x][s[l] - 'a'] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(x), l, mid);
	build(rc(x), mid + 1, r);
	pushup(x);
}
void modify(int x, int l, int r, int pos, int d)
{
	if(l == r)
	{
		for (int i = 0; i < 3; i++) t[x][i] = 0;
		t[x][d] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) modify(lc(x), l, mid, pos, d);
	else modify(rc(x), mid + 1, r, pos, d);
	pushup(x); 
}
int main()
{
	scanf("%d%d%s", &n, &q, s + 1);
	build(1, 1, n);
	while(q--)
	{
		int x;
		char tt[3];
		scanf("%d%s", &x, tt + 1);
		modify(1, 1, n, x, tt[1] - 'a');
		printf("%d\n", t[1][5]);
	}
	return 0;
}