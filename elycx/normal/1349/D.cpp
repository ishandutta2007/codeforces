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
#define maxn 300005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], s, x[maxn], y[maxn], f[maxn];
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read(), s += a[i];
	x[0] = 1, y[0] = 0;
	x[1] = 1, y[1] = mo - (n - 1);
	ru(i, 1, s - 1)
	{
		x[i + 1] = ((ll)(s + (ll)(n - 2) * i % mo) * x[i] % mo + mo - (ll)(n - 1) * i % mo * x[i - 1] % mo) % mo;
		y[i + 1] = ((ll)(s + (ll)(n - 2) * i % mo) * y[i] % mo + mo - (ll)(n - 1) * i % mo * y[i - 1] % mo) % mo;
		y[i + 1] = (y[i + 1] + mo - (ll)(n - 1) * s % mo) % mo;
		x[i + 1] = (ll)x[i + 1] * qpow(s - i, mo - 2) % mo;
		y[i + 1] = (ll)y[i + 1] * qpow(s - i, mo - 2) % mo;
	}
	int v = (ll)(mo - y[s]) * qpow(x[s], mo - 2) % mo;
	ru(i, 0, s) f[i] = ((ll)x[i] * v % mo + y[i]) % mo;
	int ans = 0;
	ru(i, 1, n) ans = (ans + f[a[i]]) % mo;
	ans = (ans + mo - (ll)(n - 1) * v % mo) % mo;
	ans = (ll)ans * qpow(n, mo - 2) % mo;
	printf("%d\n", ans);
	return 0;
}