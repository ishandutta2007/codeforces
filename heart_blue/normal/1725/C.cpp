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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
const LL mod = 998244353;
LL p2[N];
LL fact[N];
LL rfact[N];
void init()
{
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % mod;
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = fact[i - 1] * i % mod;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++)
		rfact[i] = (mod - mod / i) * rfact[mod % i] % mod;
	for (int i = 2; i < N; i++)
		rfact[i] = rfact[i - 1] * rfact[i] % mod;
}
LL C(int n, int m)
{
	if (n < m) return 0;
	return fact[n] * rfact[m] % mod * rfact[n - m] % mod;
}
LL powmod(LL a, LL b)
{
	a %= mod;
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
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> v(n);
	LL tot = 0;
	for (auto& x : v)
		scanf("%d", &x), tot += x;
	if (tot & 1)
	{
		printf("%lld\n", powmod(m, n));
		return 0;
	}
	tot /= 2;
	LL sum = 0;
	int cnt = 0;
	map<LL, int> mc;
	for (auto& x : v)
	{
		sum += x;
		cnt += mc[sum - tot];
		mc[sum] = 1;
	}
	LL ans = 0;
	for (int i = 0; i <= cnt; i++)
	{
		LL rest = m - i;
		if (rest < 0) continue;
		ans += C(cnt, i) * C(m, i) % mod * fact[i] % mod *
			powmod(rest * (rest - 1), cnt - i) % mod * powmod(rest, n - cnt * 2) % mod;
	}
	printf("%lld\n", ans % mod);
	return 0;
}