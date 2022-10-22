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
int n, m, id[maxn], pos[maxn], cnt;
ll sum[maxn];
vector<int> a[maxn];
void solve()
{
	n = read(), m = read();
	ru(i, 1, m) a[i].clear(), a[i].push_back(0), sum[i] = 0, id[i] = i;
	ru(i, 1, n)
	{
		ru(j, 1, m)
		{
			int x = read();
			a[j].push_back(x), sum[j] += x;
		}
	}
	sort(id + 1, id + m + 1, [](int x, int y) {return sum[x] < sum[y];});
	int fl = 1;
	ru(i, 1, n)
	{
		ru(j, 1, m - 1)
		{
			fl &= (a[id[j]][i] <= a[id[j + 1]][i]);
		}
	}
	if(!fl) {printf("-1\n"); return;}
	cnt = 0;
	ru(i, 1, m) if(sum[id[i]] ^ sum[i]) pos[++cnt] = i;
	if(cnt > 2) {printf("-1\n"); return;}
	if(cnt == 0) printf("1 1\n");
	else printf("%d %d\n", pos[1], pos[2]);
}
int main()
{
	int T = read(); while(T--) solve(); 
	return 0;
}