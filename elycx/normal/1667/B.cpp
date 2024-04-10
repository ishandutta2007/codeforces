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
#define mid ((l + r) >> 1)
#define maxn 500005
using namespace std;
const ll INF = 1e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, f[maxn];
ll a[maxn], tmp[maxn];
int t[maxn], len;
inline void add(int x, int d)
{
	for (; x <= len; x += x & (-x)) t[x] = max(t[x], d);
}
inline int que(int x)
{
	int res = -2 * n;
	for (; x; x -= x & (-x)) res = max(res, t[x]);
	return res;
}
void solve()
{
	n = read();
	tmp[n + 1] = 0;
	for (int i = 1; i <= n; i++) 
	{
		a[i] = read() + a[i - 1];
		tmp[i] = a[i];
	}
	sort(tmp + 1, tmp + n + 2);
	len = unique(tmp + 1, tmp + n + 2) - tmp;
	int lc = lower_bound(tmp + 1, tmp + len + 1, 0) - tmp;
	for (int i = 1; i <= len; i++) t[i] = -2 * n;
	add(lc, 0);
	for (int i = 1; i <= n; i++)
	{
		if(a[i] == a[i - 1]) f[i] = f[i - 1];
		else f[i] = f[i - 1] - 1;
		int loc = lower_bound(tmp + 1, tmp + len + 1, a[i]) - tmp;
		f[i] = max(f[i], que(loc - 1) + i);
		add(loc, f[i] - i);
	}
	printf("%d\n", f[n]);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}