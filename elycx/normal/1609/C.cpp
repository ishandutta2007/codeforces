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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[maxn], len;
int f[maxn][2];
int vis[maxn];
void solve()
{
	scanf("%d%d", &n, &len);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n + len; i++) f[i][0] = f[i][1] = 0;
	ll ans = 0;
	for (int i = n; i >= 1; i--)
	{
		if(vis[a[i]]) continue;
		if(a[i] != 1)
		{
			f[i][1] = f[i + len][0] + 1;
			ans--;
		}
		else
		{
			f[i][0] = f[i + len][0] + 1;
			f[i][1] = f[i + len][1];
		}
		ans += f[i][1];
	}
	printf("%lld\n", ans);
}
int main()
{
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 2 * i; j < maxn; j += i)
		{
			vis[j] = 1;
		}
	}
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}