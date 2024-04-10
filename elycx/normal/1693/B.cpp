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
int n, fa[maxn];
ll l[maxn], r[maxn], ans;
vector<int> G[maxn];
int dfs(int x)
{
	ll sum = 0;
	for (auto V: G[x]) sum += dfs(V);
	if(sum >= l[x]) return min(sum, r[x]);
	else
	{
		ans++;
		return r[x];
	}
}
void solve()
{
	n = read(), ans = 0;
	ru(i, 1, n) G[i].clear();
	ru(i, 2, n) {G[fa[i] = read()].push_back(i);}
	ru(i, 1, n) l[i] = read(), r[i] = read();
	dfs(1);
	printf("%d\n", ans);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}