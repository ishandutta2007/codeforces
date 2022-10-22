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
int n, k, a[maxn], vis[maxn], id[maxn];
//priority_queue<int> q;
void solve()
{
	n = read(), k = read();
	ru(i, 1, n) a[i] = read(), id[i] = i, vis[i] = 0;
	sort(id + 1, id + n + 1, [](int x, int y){return a[x] + x > a[y] + y;});
	ru(i, 1, k) vis[id[i]] = 1;//, printf("%d ", id[i]);
	int cnt = 0;
	ll ans = 0;
	rd(i, n, 1)
	{
		if(vis[i]) ans += cnt;
		else cnt++, ans += a[i];
	}
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve(); 
	return 0;
}