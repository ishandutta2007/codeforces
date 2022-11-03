#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const LL MOD1 = 998244853;
const LL MOD2 = 998244353;
const int N = 2e3 + 10;
const int M = 2e2 + 10;
const int b1 = 131;
const int b2 = 997;
char str1[N][M];
char str2[M][N];
LL h1[N];
LL h2[M][N];
LL p1[N];
LL p2[N];
LL powmod(LL a, LL b, LL mod)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	LL r1 = powmod(b1, MOD1 - 2, MOD1);
	LL r2 = powmod(b2, MOD2 - 2, MOD2);
	p1[0] = p2[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p1[i] = p1[i - 1] * b1 % MOD1;
		p2[i] = p2[i - 1] * b2 % MOD2;
	}
	vector<LL> v;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str1[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str2[i]);
	}
	for (int i = 0; i < n; i++)
	{
		LL cur = 0;
		for (int j = 0; j < m; j++)
		{
			cur = (cur + str1[i][j] * p1[j]) % MOD1;
		}
		h1[i] = cur;
	}
	map<LL, int> mc;
	for (int i = 0; i < n; i++)
	{
		h1[i] = (h1[i] * p2[i]) % MOD2;
		if (i > 0) h1[i] = (h1[i] + h1[i - 1]) % MOD2;
		if (i >= m - 1)
		{
			LL rp = powmod(r2, i - (m - 1), MOD2);
			LL h = h1[i];
			if (i >= m) h -= h1[i - m];
			if (h < 0) h += MOD2;
			h = h * rp % MOD2;
			mc[h] = i - (m - 1) + 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		LL cur = 0;
		for (int j = 0; j < n; j++)
		{
			cur = (cur + str2[i][j] * p1[j]) % MOD1;
			h2[i][j] = cur;
		}
	}
	for (int j = n - 1; j >= m - 1; j--)
	{
		LL pj = powmod(r1, j - (m - 1), MOD1);
		LL h = 0;
		for (int i = 0; i < m; i++)
		{
			LL cur = h2[i][j];
			if (j >= m) cur -= h2[i][j - m];
			cur = cur * pj % MOD1;
			if (cur < 0) cur += MOD1;
			h += cur * p2[i] % MOD2;
		}
		h %= MOD2;
		if (h < 0) h += MOD2;
		if (mc.count(h))
		{
			printf("%d %d\n", mc[h], j - (m - 1) + 1);
			return 0;
		}
	}
	return 0;
}