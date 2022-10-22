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
int n, m;
struct node
{
	int id, val;
	inline bool operator < (const node &a) const
	{
		return val < a.val;
	}
}p[maxn];
int st[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	ru(i, 1, m)
	{
		printf("? ");
		ru(j, 1, m) printf("%d", i == j ? 1 : 0);
		printf("\n"); fflush(stdout);
		scanf("%d", &p[i].val); p[i].id = i;
	}
	sort(p + 1, p + m + 1);
	long long las = 0;
	ru(i, 1, m)
	{
		st[p[i].id] = 1;
		printf("? ");
		ru(j, 1, m) printf("%d", st[j]);
		printf("\n"); fflush(stdout);
		long long now;
		scanf("%lld", &now);
		if(now != las + p[i].val) st[p[i].id] = 0; 
		else las = now;
	}
	printf("! %d\n", las); fflush(stdout);
	return 0;
}