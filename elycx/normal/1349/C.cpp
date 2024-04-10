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
#define maxn 1005
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const ll INF = 2e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, Q;
int a[maxn][maxn];
ll beg[maxn][maxn];
char s[maxn];
queue<pii> q;
void init()
{
	ru(i, 1, n) ru(j, 1, m)
	{
		if(a[i - 1][j] == a[i][j] || a[i + 1][j] == a[i][j] || a[i][j - 1] == a[i][j] || a[i][j + 1] == a[i][j])
		{
			beg[i][j] = 1;
			q.push(mp(i, j));
		}
		else beg[i][j] = INF;
	}
	while(!q.empty())
	{
		int x = q.front().fi, y = q.front().se; q.pop();
		if(x > 1 && beg[x - 1][y] > beg[x][y] + 1)
		{
			beg[x - 1][y] = beg[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}
		if(x < n && beg[x + 1][y] > beg[x][y] + 1)
		{
			beg[x + 1][y] = beg[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}
		if(y > 1 && beg[x][y - 1] > beg[x][y] + 1)
		{
			beg[x][y - 1] = beg[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
		if(y < m && beg[x][y + 1] > beg[x][y] + 1)
		{
			beg[x][y + 1] = beg[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}
	}
}
void solve()
{
	n = read(), m = read(), Q = read();
	ru(i, 0, n + 1) ru(j, 0, m + 1) a[i][j] = -1;
	ru(i, 1, n) 
	{
		scanf("%s", s + 1);
		ru(j, 1, m) a[i][j] = s[j] - '0';
	}
	init();
	while(Q--)
	{
		int x = read(), y = read();
		ll p; scanf("%lld", &p);
		if(p < beg[x][y]) {printf("%d\n", a[x][y]); continue;}
		printf("%d\n", a[x][y] ^ ((p - beg[x][y] + 1) & 1));
	}
}
int main()
{
	solve();
	return 0;
}