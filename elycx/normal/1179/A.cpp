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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int tmp[maxn], tmp2[maxn], n, q, a[maxn];
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) a[i] = read();
	tmp[0] = a[1];
	for (int i = 1; i < n; i++)
	{
		tmp[i] = max(tmp[i - 1], a[i + 1]);
		tmp2[i] = (tmp[i - 1] ^ a[i + 1] ^ tmp[i]);
	}
	while(q--)
	{
		long long x;
		scanf("%lld", &x);
		if(x < n) printf("%d %d\n", tmp[x - 1], a[x + 1]);
		else
		{
			x = (x - 1) % (n - 1) + 1;
			printf("%d %d\n", tmp[n - 1], tmp2[x]);
		}
	}
	return 0;
}