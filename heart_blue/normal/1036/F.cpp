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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const LL INFINF = INF * INF;
const int N = 1e5 + 10;
int mu[] = {
0
, 1
, -1
, -1
, 0
, -1
, 1
, -1
, 0
, 0
, 1
, -1
, 0
, -1
, 1
, 1
, 0
, -1
, 0
, -1
, 0
, 1
, 1
, -1
, 0
, 0
, 1
, 0
, 0
, -1
, -1
, -1
, 0
, 1
, 1
, 1
, 0
, -1
, 1
, 1
, 0
, -1
, -1
, -1
, 0
, 0
, 1
, -1
, 0
, 0
, 0
, 1
, 0
, -1
, 0
, 1
, 0
, 1
, 1
, -1
, 0
, -1
, 1
, 0
, 0
, 1
, -1
, -1
, 0
, 1
, -1
, -1
, 0
, -1
, 1
, 0
, 0
, 1
, -1
};
inline LL multy(LL a, LL b)
{
	if (a > INFINF / b) return INFINF;
	else return a * b;
}
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = multy(ret, a);
		a = multy(a, a);
		b >>= 1;
	}
	return ret;
}
LL key[N];
LL solve(LL x, LL c, int o = 0)
{
	LL ret = pow(x, 1.0 / c) + 0.5;
	if (powmod(ret, c) > x) ret--;
	return ret - 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	for (int i = 2; i < 100; i++)
		key[i] = solve(INFINF, i, 1) + 1;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		LL ans = n - 1;
		for (int i = 2; i <= 64; i++)
		{
			if (mu[i] == 0) continue;
			ans += mu[i] * solve(n, i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}