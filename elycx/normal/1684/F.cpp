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
int n, m, p[maxn], nxt[maxn][22], a[maxn];
map<int, int> las;
vector<int> add[maxn], sub[maxn];
multiset<int> now;
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) add[i].clear(), sub[i].clear(), a[i] = read(), p[i] = 0;
	las.clear();
	ru(j, 0, 20) nxt[n + 1][j] = n + 1;
	rd(i, n, 1)
	{
		nxt[i][0] = las[a[i]];
		if(!nxt[i][0]) nxt[i][0] = n + 1;
		ru(j, 1, 20) nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		las[a[i]] = i;
	}
	ru(i, 1, m)
	{
		int l = read(), r = read();
		p[l] = max(p[l], r);
	}
	int mx = 0;
	ru(i, 1, n)
	{
		mx = max(mx, p[i]);
		if(nxt[i][0] > mx) continue;
		int tmp = nxt[i][0];
		add[1].push_back(i);
		sub[i + 1].push_back(i);
		add[i + 1].push_back(tmp);
		sub[tmp + 1].push_back(tmp);
		add[tmp + 1].push_back(n + 1);
		tmp = i;
		rd(j, 20, 0) if(nxt[tmp][j] <= mx) tmp = nxt[tmp][j];
//		printf("%d %d\n", i, tmp);
		add[1].push_back(i);
		sub[i + 1].push_back(i);
		add[i + 1].push_back(tmp);
		sub[tmp + 1].push_back(tmp);
		add[tmp + 1].push_back(n + 1);
	}
	now.clear();
	int ans = n;
	ru(i, 1, n)
	{
		for (auto V: add[i]) now.insert(V);
		for (auto V: sub[i]) now.erase(now.find(V));
		if(now.empty()) {ans = 0; break;}
		int mx = (*--now.end());
//		for (auto V: now) printf("%d ", V);
//		printf("%d %d\n", i, mx);
		if(mx != n + 1) ans = min(ans, mx - i + 1);
	}
	printf("%d\n", max(0, ans));
}
int main()
{
	int T = read(); while(T--) solve(); 
	return 0;
}