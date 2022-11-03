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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int d[N];
LL sum[N];
LL fact[N];
LL rfact[N];
const LL MOD = 998244353;
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % MOD;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++)
		rfact[i] = (MOD - MOD / i) * rfact[MOD % i] % MOD;
	for (int i = 2; i < N; i++)
		rfact[i] = rfact[i] * rfact[i - 1] % MOD;
}
LL C(int n, int m)
{
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + d[i];
		sum[i] %= MOD;
	}
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int pos = lower_bound(d + 1, d + n + 1, b) - d;
		int x = n - pos + 1;
		int y = pos - 1;
		if (x < a)
		{
			puts("0");
			continue;
		}
		LL tot = C(n, x) * (x - a) % MOD * fact[x - 1] % MOD * fact[n - x] % MOD * (sum[n] - sum[pos - 1]) % MOD;
		if (y > 0)
		{
			tot += (x - a + 1) * C(n, x + 1) % MOD * fact[x] % MOD * fact[n - x - 1] % MOD * sum[y] % MOD;
		}
		tot *= rfact[n];
		tot %= MOD;
		if (tot < 0)
			tot += MOD;
		printf("%lld\n", tot);
	}
	return 0;
}