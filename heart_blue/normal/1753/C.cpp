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
const int N = 4e5 + 10;
const LL mod = 998244353;
LL dp[N];
int a[N];
LL powmod(LL a, LL b)
{
	a %= mod;
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
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int cnt0 = count(a + 1, a + n + 1, 0);
		int key = count(a + 1, a + cnt0 + 1, 1);
		int cnt1 = n - cnt0;
		LL o = 1LL * n * (n - 1) % mod * (mod + 1) / 2 % mod;
		for (int i = 1; i <= key; i++)
		{
			// f(i) = (1-p) * f(i) + p * f(i - 1) + 1;
			dp[i] = dp[i - 1] + powmod(1LL * i * i, mod - 2) * o % mod;
		}
		printf("%lld\n", dp[key] % mod);
	}
	return 0;
}