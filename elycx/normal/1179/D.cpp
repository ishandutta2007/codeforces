/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
const ll INF = 9e11;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll siz[maxn];
ll ans = INF, f[maxn];
vector<int> G[maxn];
bool cmp(int x, int y)
{
	return siz[x] < siz[y];
}
int t, q[maxn];
inline ll dx(int a, int b)
{
	return siz[a] - siz[b];
}
inline ll dy(int a, int b)
{
	return (f[a] - (ll)2 * siz[a] * n + (ll)siz[a] * siz[a]) - (f[b] - (ll)2 * siz[b] * n + (ll)siz[b] * siz[b]);
}
void dfs(int x, int fa)
{
	ll res = INF;
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
		siz[x] += siz[V];
	}
	sort(G[x].begin(), G[x].end(), cmp);
	f[x] = (ll)siz[x] * siz[x];
	t = 0;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		f[x] = min(f[x], f[V] + (ll)(siz[x] - siz[V]) * (siz[x] - siz[V]));
		ans = min(ans, f[x] + (ll)(n - siz[x]) * (n - siz[x]));
		while(t >= 2 && dx(q[t], q[t - 1]) * 2 * siz[V] > dy(q[t - 1], q[t])) t--;
		if(t) ans = min(ans, f[q[t]] + f[V] + (ll)(n - siz[q[t]] - siz[V]) * (n - siz[q[t]] - siz[V]));
		while(t >= 2 && dx(V, q[t]) * dy(q[t - 1], q[t]) < dx(q[t], q[t - 1]) * dy(q[t], V)) t--;
		q[++t] = V;
	}
//	printf("%d %lld\n", x, f[x]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(n == 2)
	{
		printf("2\n");
		return 0;
	}
	dfs(1, 1);
	printf("%lld\n", (ll)n * (n - 1) / 2 + ((ll)n * n - ans) / 2);
	return 0;
}