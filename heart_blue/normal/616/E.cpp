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
const int N = 5e5 + 10;
LL sum(LL n)
{
	n %= 2 * INF;
	return (n * (n + 1)) % (2 * INF) / 2;
}
LL multy(LL x, LL y)
{
	x %= INF;
	y %= INF;
	return x * y % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m;
	scanf("%lld%lld", &n, &m);
	LL ans = 0;
	if (m > n)
	{
		ans += multy(m - n, n);
		m = n;
	}
	for (LL i = 1; i <= m; i++)
	{
		LL l = i;
		LL r = min(m, n / (n / i));
		LL len = (r - l + 1);
		ans += multy(len, n);
		ans -= multy(sum(r) - sum(l - 1), n / i);
		i = r;
	}
	ans %= INF;
	if (ans < 0) ans += INF;
	printf("%lld\n", ans);
	return 0;
}