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
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
vector<int> G[maxn];
struct node
{
	int id, dis;
	inline bool operator < (const node &a) const
	{
		return dis > a.dis;
	}
};
priority_queue<node> q;
int dis[maxn], d[maxn], vis[maxn];
int main()
{
	n = read(), m = read();
	ru(i, 1, m) {int x = read(), y = read(); G[y].push_back(x), d[x]++;}
	ru(i, 1, n) dis[i] = INF;
	q.push({n, dis[n] = 0});
	while(!q.empty())
	{
		int x = q.top().id; q.pop();
		if(vis[x]) continue; vis[x] = 1;
		for (auto V: G[x])
		{
			d[V]--;
			if(dis[V] > dis[x] + d[V] + 1) q.push({V, dis[V] = dis[x] + d[V] + 1});
		}
	}
	printf("%d\n", dis[1]);
	return 0;
}