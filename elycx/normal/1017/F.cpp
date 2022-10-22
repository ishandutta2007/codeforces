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
#include <bitset>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll A, B, C, D;
bitset<100000005> t;
int prime[10005], cnt;
long long ans = 0;
inline int calc(int x)
{
	return x - x / 2 - x / 3 + x / 6;
}
int main()
{
	scanf("%d%lld%lld%lld%lld", &n, &A, &B, &C, &D);
	for (int i = 4; i <= n; i++)
	{
		if(i % 2 == 0 || i % 3 == 0) continue;
		if(!t[calc(i)])
		{
			long long now = i;
			long long tmpb = (ll)i * i, tmpa = (ll)i * i * i;
			for (; now <= n; now *= i)
			{
				ans = (ans + (ll)(n / now) * (A * tmpa + B * tmpb + C * i + D));
			}
			if((long long)i * i <= n * 2) prime[++cnt] = i;
		}
		for (register int j = 1; (long long)prime[j] * i <= n && j <= cnt; j++)
		{
			t[calc(i * prime[j])] = 1;
			if(i % prime[j] == 0) break;
		}
	}
//	printf("%d\n", cnt);
//	for (int i = 1; i <= cnt; i++) printf("%d ", prime[i]);
//	printf("\n");
	for (int i = 2; i <= 3; i++)
	{
		
			long long now = i;
			long long tmpb = (ll)i * i, tmpa = (ll)i * i * i;
			for (; now <= n; now *= i)
			{
				ans = (ans + (ll)(n / now) * (A * tmpa + B * tmpb + C * i + D));
				ans %= (1ll << 32);
			}
	}
	printf("%lld", ans);
	return 0;
}