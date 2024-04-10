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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
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
/*
px+a = (p-1)y+b
p1x-p2y = b-a
ax-(a-1)y = 1
a(x-y)+y = 1;

x = 2-a + (a-1)t
y = 1-a + at
*/
LL solve(int p, int u, int v, LL tot)
{
	int c = u - v;
	LL x = (2LL - p) * c;
	LL y = (1LL - p) * c;
	x = x * p + v;
	y = y * (p - 1) + u;
	LL key = 1LL * p * (p - 1);
	x %= key;
	while (x <= 0) x += key;
	return tot / key + (tot % key >= x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, p;
	LL tot = 0;
	scanf("%d%d%d%lld", &a, &b, &p, &tot);
	LL ans = 0;
	for (int i = 1; i < p; i++)
	{
		int u = powmod(a, i, p);
		u = b * powmod(u, p - 2, p) % p;
		int v = i;
		ans += solve(p, v, u, tot);
	}
	printf("%lld\n", ans);
	return 0;
}