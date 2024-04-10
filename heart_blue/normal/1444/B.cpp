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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
const int MOD = 998244353;
int fact(int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret = 1LL * ret * i % MOD;
	}
	return ret;
}
int powmod(int a, int b, int mod = MOD)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v(2 * n);
	for (auto& x : v) scanf("%d", &x);
	LL ans = powmod(fact(n), MOD - 2);
	ans = ans * ans % MOD;
	ans = ans * fact(2 * n) % MOD;
	LL sum = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		sum += v[i + n] - v[i];
	}
	sum %= MOD;
	printf("%lld\n", ans * sum % MOD);
	return 0;
}