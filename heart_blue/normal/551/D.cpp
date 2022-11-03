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
const int N = 5e2 + 20;
map<LL, LL> mc;
int mod;
LL fun(LL x)
{
	if (x <= 2) return 1 % mod;
	if (mc.count(x)) return mc[x];
	if (x % 2 == 0)
	{
		return mc[x] = fun(x / 2) * (fun(x / 2 + 1) * 2 - fun(x / 2)) % mod;
	}
	else
	{
		return mc[x] = (fun(x / 2) * fun(x / 2) + fun(x / 2 + 1) * fun(x / 2 + 1)) % mod;
	}
}
LL powmod(LL a, LL b)
{
	LL ret = 1 % mod;
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
	LL n, k, l;
	cin >> n >> k >> l >> mod;
	LL tot = powmod(2, n);
	LL key[2];
	key[0] = fun(n + 2);
	key[1] = tot - key[0];
	if (key[0] < 0)
		key[0] += mod;
	if (l <= 62 && k >> l)
	{
		puts("0");
		return 0;
	}
	if (l == 0)
	{
		int ans = 1 % mod;
		printf("%d\n", ans);
		return 0;
	}
	LL ans = 1 % mod;
	for (int o = 0; o < l; o++)
	{
		ans = ans * key[k >> o & 1] % mod;
	}
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;
}