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
const int N = 2e5 + 10;
const LL mod = 998244353;
LL p[N];
LL powmod(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	LL r100 = powmod(100, mod - 2);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &p[i]);
		p[i] = p[i] * r100 % mod;
	}
	LL a = 0, b = 0;
	for (int i = n; i >= 1; i--)
	{
		tie(a, b) = make_pair(a * p[i] + 1, b * p[i] + 1 - p[i]);
		a %= mod;
		b %= mod;
	}
	b--;
	LL ans = -a * powmod(b, mod - 2);
	ans %= mod;
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;
}