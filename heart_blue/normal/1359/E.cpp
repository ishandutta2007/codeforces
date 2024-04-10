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
const int N = 5e5 + 10;
const LL MOD = 998244353;
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % MOD;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++) rfact[i] = (MOD - MOD / i) * rfact[MOD % i] % MOD;
	for (int i = 2; i < N; i++) rfact[i] = rfact[i] * rfact[i - 1] % MOD;
}
LL C(int n, int m)
{
	if (n < m) return 0;
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL ans = 0;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		ans += C(n / i - 1, k - 1);
	}
	printf("%lld\n", ans % MOD);
	return 0;
}