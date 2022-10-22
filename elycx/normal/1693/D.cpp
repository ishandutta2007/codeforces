/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, p[maxn], pf[maxn];
int f[maxn][2];
int nxt[maxn][2];
int t[maxn][2];
inline void add(int tp, int x, int v)
{
	for (; x <= n; x += x & (-x)) t[x][tp] = max(t[x][tp], v);
}
inline int que(int tp, int x)
{
	int res = 0;
	for (; x; x -= x & (-x)) res = max(res, t[x][tp]);
	return res;
}
int main()
{
	n = read(); ru(i, 1, n) p[i] = read(), pf[i] = n - p[i] + 1;
	nxt[n][0] = nxt[n][1] = n;
	ll ans = 1; p[n + 1] = pf[n + 1] = n + 1;
	rd(i, n - 1, 1)
	{
		nxt[i][0] = nxt[i][1] = i;
		nxt[i][p[i] > p[i + 1]] = nxt[i + 1][p[i] > p[i + 1]];
		f[i][0] = nxt[i + 1][0], f[i][1] = nxt[i + 1][1];
		if(nxt[i + 1][0] == n) f[i][0] = n;
		else
		{
			if(p[i] > p[nxt[i + 1][0] + 1]) f[i][0] = max(f[i][0], f[nxt[i + 1][0]][1]);
			swap(p[nxt[i + 1][0] + 1], p[n + 1]);
			int loc = lower_bound(p + i + 1, p + nxt[i + 1][0] + 1, p[i]) - p - 2;
			swap(p[nxt[i + 1][0] + 1], p[n + 1]);
			f[i][0] = max(f[i][0], que(1, loc));
//			printf("%d " loc, que(1, loc));
		}
		if(nxt[i + 1][1] == n) f[i][1] = n;
		else
		{
			if(p[i] < p[nxt[i + 1][1] + 1]) f[i][1] = max(f[i][1], f[nxt[i + 1][1]][0]);//, printf("! %d ", nxt[i + 1][1]);
			swap(pf[nxt[i + 1][1] + 1], pf[n + 1]);
			int loc = lower_bound(pf + i + 1, pf + nxt[i + 1][1] + 1, pf[i]) - pf - 2;
			swap(pf[nxt[i + 1][1] + 1], pf[n + 1]);
			f[i][1] = max(f[i][1], que(0, loc));
//			printf("%d ", loc);
		}
		add(0, i, f[i][0]), add(1, i, f[i][1]);
//		printf("%d %d %d\n", i, f[i][0], f[i][1]);
		
		ans += max(nxt[i][0] == n ? n : que(1, nxt[i][0]), nxt[i][1] == n ? n : que(0, nxt[i][1])) - i + 1;
//		printf("%d %d\n", i, max(nxt[i][0] == n ? n : que(1, nxt[i][0]), nxt[i][1] == n ? n : que(0, nxt[i][1])));
	}
	printf("%lld\n", ans);
	return 0;
}