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
int T, n;
ll a[100];
void solve()
{
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		while(a[i] % 2 == 0)
		{
			cnt++;
			a[i] /= 2;
		}
	}
	sort(a + 1, a + n + 1);
	a[n] *= (1ll << cnt);
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i];
	printf("%lld\n", ans); 
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		solve();
	}
	return 0;
}