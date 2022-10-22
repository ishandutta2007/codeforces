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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
vector<int> row[maxn], col[maxn];
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) 
		{
			int a = read();
			row[a].push_back(i);
			col[a].push_back(j);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= 100000; i++)
	{
		sort(col[i].begin(), col[i].end());
		for (int j = 0; j < col[i].size(); j++)
		{
			ans += (ll)(j - ((int)col[i].size() - j - 1)) * col[i][j];
		}
		sort(row[i].begin(), row[i].end());
		for (int j = 0; j < row[i].size(); j++)
		{
			ans += (ll)(j - ((int)row[i].size() - j - 1)) * row[i][j];
		}
	}
	printf("%lld", ans);
	return 0;
}