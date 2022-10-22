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
int buc[maxn], vis[maxn], n;
int main()
{
	n = read();
	ru(i, 1, n) buc[read()]++;
	ll ans = 1;
	ru(i, 2, maxn - 1)
	{
		if(!vis[i])
		{
			ll mn = 1;
			for (ll j = i; j < maxn; j *= i)
			{
				int cnt = 0;
				for (int k = j; k < maxn; k += j)
				{
					cnt += buc[k];
				}
				mn = j;
				if(cnt < n - 1) {mn = j / i; break;}
			}
			ans *= mn;
		}
		for (int j = i; j < maxn; j += i) vis[j] = 1;
	}
	printf("%lld\n", ans);
	return 0;
}