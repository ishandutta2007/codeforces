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
#define maxn 5005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, f[maxn][maxn], c[maxn][maxn], fac[maxn];
int main()
{
	n = read();
	fac[0] = 1;
	ru(i, 1, n) fac[i] = (ll)fac[i - 1] * i % mo;
	ru(i, 0, n)
	{
		c[i][0] = c[i][i] = 1;
		ru(j, 1, i - 1) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
	}
	f[1][0] = 1;
	ru(i, 2, n) ru(j, 0, i - 1)
	{
		f[i][j] = (ll)f[i - 1][j] * (j + 1) % mo;
		if(j) f[i][j] = (f[i][j] + (ll)f[i - 1][j - 1] * (i - j) % mo) % mo;
	}
	ru(i, 1, n)
	{
		int res = 0;
		ru(j, 1, n)
		{
			res = (res + (ll)f[j][i - 1] * c[n][j] % mo * fac[n - j] % mo) % mo;
		}
		printf("%d ", res);
	}
	return 0;
}