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
int n, a[maxn], cnt[maxn];
char s[maxn];
vector<int> p;
int main()
{
	scanf("%d%s", &n, s + 1);
	int sum = 0, mn = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i] == ')' ? sum-- : sum++;
		a[i] = sum;
		mn = min(mn, a[i]);
	}
	if(sum != 0)
	{
		printf("0\n1 1");
		return 0;
	}
	for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (a[i] == mn + 1);
//	for (int i = 1; i <= n; i++) printf("%d ", cnt[i]);
//	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		if(a[i] == mn) p.push_back(i);
	}
	int ans = p.size(), l = 1, r = 1;
	for (int i = 0; i < p.size() - 1; i++)
	{
		int tmp = cnt[p[i + 1]] - cnt[p[i]];
		if(tmp > ans)
		{
			ans = tmp;
			l = p[i] + 1, r = p[i + 1];
		}
	}
	int tmp = cnt[n] - cnt[p[p.size() - 1]] + cnt[p[0]];
	if(mn != 0 && tmp > ans)
	{
		ans = tmp;
		l = p[0], r = p[p.size() - 1] + 1;
	}
	int num = 0, j = 0;
	for (int i = 1; i <= n; i++)
	{
		if(a[i] < mn + 2)
		{
			j = i;
			num = 0;
		}
		if(a[i] == mn + 2) num++;
		if(num + p.size() > ans && a[i + 1] < mn + 2)
		{
			ans = num + p.size();
			l = j + 1, r = i + 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if(a[i] < mn + 2)
		{
			if(num + p.size() > ans)
			{
				ans = num + p.size();
				l = i, r = j + 1;
			}
			break;
		}
		if(a[i] == mn + 2) num++;
	}
	printf("%d\n%d %d\n", ans, l, r);
	return 0;
}