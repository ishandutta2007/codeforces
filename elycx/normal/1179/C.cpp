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
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn], b[maxn], q;
int t[maxn * 4], tag[maxn * 4];
void pushdown(int x)
{
	tag[lc(x)] += tag[x];
	tag[rc(x)] += tag[x];
	t[lc(x)] += tag[x];
	t[rc(x)] += tag[x];
	tag[x] = 0;
}
void add(int x, int l, int r, int a, int b, int data)
{
	if(a <= l && r <= b)
	{
		tag[x] += data;
		t[x] += data;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) add(lc(x), l, mid, a, b, data);
	if(b > mid) add(rc(x), mid + 1, r, a, b, data);
	t[x] = max(t[lc(x)], t[rc(x)]);
}
void calc(int x, int l, int r)
{
	if(l == r)
	{
		printf("%d\n", l);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x);
	if(t[rc(x)] > 0) calc(rc(x), mid + 1, r);
	else calc(lc(x), l, mid);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		add(1, 1, 1000000, 1, a[i], 1);
	}
	for (int i = 1; i <= m; i++)
	{
		b[i] = read();
		add(1, 1, 1000000, 1, b[i], -1);
	}
	scanf("%d", &q);
	while(q--)
	{
		int tp = read(), x = read(), y = read();
		if(tp == 1)
		{
			add(1, 1, 1000000, 1, a[x], -1);
			a[x] = y;
			add(1, 1, 1000000, 1, a[x], 1);
		}
		else
		{
			add(1, 1, 1000000, 1, b[x], 1);
			b[x] = y;
			add(1, 1, 1000000, 1, b[x], -1);
		}
		if(t[1] <= 0)
		{
			printf("-1\n");
			continue;
		}
		calc(1, 1, 1000000);
	}
	return 0;
}