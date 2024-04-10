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
const LL mod = 998244353;
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
	LL n, m, l, r;
	cin >> n >> m >> l >> r;
	LL len = (r - l + 1);
	LL a = len / 2;
	LL b = len / 2;
	LL ans = 1;
	if (len & 1)
	{
		if (l & 1) b++;
		else a++;
	}
	if (n * m % 2 == 1)
		ans = powmod(a + b, n * m) * 2;
	else
		ans = powmod(a + b, n * m) + powmod(a - b, n * m);
	ans = ans * powmod(2, mod - 2) % mod;
	if (ans < 0)
		ans += mod;
	printf("%lld\n", ans);
	return 0;
}