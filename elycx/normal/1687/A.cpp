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
int n, k, a[maxn];
ll sum[maxn];
void solve()
{
	n = read(), k = read();
	ru(i, 1, n) a[i] = read();
	ll ans = 0;
	ru(i, 1, n) sum[i] = sum[i - 1] + a[i];
	if(k > n)
	{
		ans = sum[n] + (ll)(k - 1) * n - (ll)n * (n - 1) / 2;
	}
	else {ru(i, k, n) ans = max(ans, sum[i] - sum[i - k]); ans += (ll)k * (k - 1) / 2;}
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve(); 
	return 0;
}