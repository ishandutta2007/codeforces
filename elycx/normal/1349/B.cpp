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
int T, n, k, a[maxn];
void solve()
{
	n = read(), k = read();
	int fl = 0;
	ru(i, 1, n) a[i] = read(), fl |= (a[i] == k);
	if(!fl) {printf("no\n"); return;}
	if(n == 1) {printf("yes\n"); return;}
	int mn = n, sum = 0;
	ru(i, 1, n)
	{
		int nxt = sum + (a[i] >= k ? 1 : -1);
		if(nxt - mn > 0) {printf("yes\n"); return;}
		mn = min(mn, sum);
		sum = nxt;
	}
	printf("no\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}