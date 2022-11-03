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
const int N = 1e5 + 10;
map<int, int> mc;
LL fact[N];
LL rfact[N];
LL dp[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % INF;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++) rfact[i] = (INF - INF / i) * rfact[INF % i] % INF;
	for (int i = 2; i < N; i++) rfact[i] = rfact[i] * rfact[i - 1] % INF;
}
bool check(int x)
{
	while (x)
	{
		if (x % 10 != 4 && x % 10 != 7)
			return false;
		x /= 10;
	}
	return true;
}
LL C(int n, int m)
{
	if (n < m) return 0;
	if (m < 0) return 0;
	return fact[n] * rfact[m] % INF * rfact[n - m] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, k;
	scanf("%d%d", &n, &k);
	int rest = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (check(x)) mc[x]++;
		else rest++;
	}
	int sz = mc.size();
	dp[0] = 1;
	for (auto& p : mc)
	{
		int t = p.second;
		for (int i = sz; i > 0; i--)
			dp[i] = (dp[i] + dp[i - 1] * t) % INF;
	}
	LL ans = 0;
	for (int i = 0; i <= sz; i++)
	{
		ans += dp[i] * C(rest, k - i) % INF;
	}
	ans %= INF;
	printf("%lld\n", ans);
	return 0;
}