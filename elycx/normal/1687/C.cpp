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
int T, n, m, vis[maxn], l[maxn], r[maxn];
vector<int> p[maxn];
ll a[maxn];
int fa[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
queue<int> q;
void solve()
{
	n = read(), m = read();
	ru(i, 0, n) p[i].clear();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n) a[i] -= read();
	ru(i, 1, n) a[i] += a[i - 1];
	ru(i, 1, m)
	{
		l[i] = read() - 1, r[i] = read();
		vis[i] = 0, p[l[i]].push_back(i), p[r[i]].push_back(i);
		if(a[l[i]] == 0 && a[r[i]] == 0) q.push(i), vis[i] = 1;
	}
	fa[n + 1] = n + 1;
	rd(i, n, 0) fa[i] = (a[i] == 0 ? fa[i + 1] : i);
	while(!q.empty())
	{
		int id = q.front(); q.pop();
		for (int i = find(l[id]); i <= r[id]; i = find(i))
		{
			fa[i] = i + 1;
			for (auto x: p[i])
			{
				if(!vis[x] && fa[l[x]] != l[x] && fa[r[x]] != r[x])
				{
					vis[x] = 1;
					q.push(x);
				}
			}
		}
	}
	ru(i, 0, n) if(fa[i] == i) {printf("NO\n"); return;}
	printf("YES\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}