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
#define maxn 300005
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, fa[maxn];
ll sum, dep[maxn];
int d[maxn];
ll calc(int x)
{
	ll cnt = 1, tot = 0, rest = n;
	for (int now = 1; now <= n; now++)
	{
		tot += min(cnt, (ll)rest) * now;
		rest -= min(cnt, (ll)rest);
		if(!rest) break;
		cnt *= x;
	}
	return tot;
}
int vis[maxn], chn[maxn];
signed main()
{
	scanf("%lld%lld", &n, &sum);
	if(sum > n * (n + 1) / 2 || sum < 2 * n - 1)
	{
		printf("No\n");
		return 0;
	}
	int L = 1, R = n, mid;
	while(L < R)
	{
		mid = (L + R) >> 1;
		if(calc(mid) <= sum) R = mid;
		else L = mid + 1;
	}
	ll cnt = L, tot = 1, now = 1, l = 1, r = 1;
	dep[1] = 1;
	int len = 1;
	chn[1] = 1;
	for (int lev = 2; lev <= n; lev++)
	{
		ll tl = r + 1, tr = r + (r - l + 1) * L;
		chn[lev] = tl;
		vis[tl] = 1;
		for (int i = l; i <= r; i++)
		{
			if(now == n) break;
			for (int j = 1; j <= L; j++)
			{
				if(now == n) break;
				fa[++now] = i;
				tot += lev;
				len = max(len, lev);
				dep[now] = dep[i] + 1;
			}
		}
		l = tl, r = tr;
		if(now == n) break;
	}
	tot = sum - tot;
	for (int i = n; i >= 1; i--)
	{
		if(!tot) break;
		if(vis[i]) continue;
		int pos = min(len + 1 - dep[i], tot) + dep[i];
		tot -= pos - dep[i];
		if(pos == len + 1) chn[++len] = i;
		fa[i] = chn[pos - 1];
	}
	printf("Yes\n");
	for (int i = 2; i <= n; i++) printf("%lld ", fa[i]);
	return 0;
}