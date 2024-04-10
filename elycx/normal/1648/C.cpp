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
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, s[maxn], t[maxn], cnt[maxn],fac[maxn], inv[maxn], ifac[maxn];
int T[maxn];
inline void add(int x, int d)
{
	for (; x < maxn; x += x & -x) T[x] = (T[x] + d) % mo;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= x & -x) res = (res + T[x]) % mo;
	return res;
}
int main()
{
	n = read(), m = read();
	inv[1] = ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
	for (int i = 2; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % mo, inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo, ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	for (int i = 1; i <= n; i++) cnt[read()]++;
	for (int i = 1; i < maxn; i++) add(i, cnt[i]);
	for (int i = 1; i <= m; i++) t[i] = read();
	int ans = 0, now = 1;
	for (int i = 1; i < maxn; i++) now = (ll)now * ifac[cnt[i]] % mo;
	for (int i = 1; i <= min(n, m); i++)
	{
		int c = t[i] - 1;
		if(n < m && i == n) c++;
		ans = (ans + (ll)fac[n - i] * now % mo * que(c) % mo) % mo;
		if(!cnt[t[i]]) break;
		add(t[i], mo - cnt[t[i]]);
		now = (ll)now * cnt[t[i]] % mo;
		cnt[t[i]] -= 1;
		add(t[i], cnt[t[i]]);
	}
	printf("%d\n", ans);
	return 0;
}