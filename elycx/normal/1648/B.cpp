/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, c, sum[maxn];
void solve()
{
	n = read(), c = read();
	for (int i = 1; i <= c; i++) sum[i] = 0;
	for (int i = 1; i <= n; i++) sum[read()]++;
	for (int i = 1; i <= c; i++) sum[i] += sum[i - 1];
	int fl = 1;
	for (int i = 1; i <= c; i++)
	{
		if(sum[i] == sum[i - 1]) continue;
		for (int j = 1; i * j <= c; j++)
		{
			if(sum[min(c, i * (j + 1) - 1)] - sum[i * j - 1] > 0 && sum[j] == sum[j - 1])
			{
				fl = 0;
			}
		}
	}
	if(fl) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}