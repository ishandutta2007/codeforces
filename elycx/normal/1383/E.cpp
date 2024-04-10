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
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
char s[maxn];
int tmp[maxn], sum = 0;
int f[maxn], g[maxn], last[2];
int mx = 0;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	last[0] = last[1] = -1;
	g[0] = 1;
	f[0] = 1;
	for (int i = 0; i <= n + 1; i++) tmp[i] = n + 1;
	for (int i = 1; i <= n; i++)
	{
		last[s[i] - '0'] = i;
		if(last[1] != -1) 
		{
			sum = (sum + mo - g[tmp[i - last[1]]]) % mo;
			sum = (sum + g[last[1] - 1]) % mo;
			tmp[i - last[1]] = last[1] - 1;
		}
		if(last[1] == -1) mx = i;
		g[i] = (sum + mx + 1) % mo;
		int pos = max(0, last[1]);
		f[i] = (f[i] + (ll)(i - pos) * f[pos] % mo) % mo;
		if(pos) f[i] = (f[i] + g[pos - 1]) % mo;
//		printf("%d %d\n", f[i], g[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}