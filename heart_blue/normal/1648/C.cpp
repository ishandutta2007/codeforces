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
const int N = 2e5 + 10;
const LL mod = 998244353;

class BIT
{
	LL a[N];
public:
	void add(int x, int y)
	{
		while (x < N)
		{
			a[x] += y;
			a[x] %= mod;
			x += x & -x;
		}
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret % mod;
	}
} b;
int cnt[N];
LL fact[N];
LL rfact[N];
LL inv[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
	inv[1] = 1;
	for (int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	rfact[0] = 1;
	for (int i = 1; i < N; i++) rfact[i] = rfact[i - 1] * inv[i] % mod;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int limit = 2e5;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	LL ans = 0;
	LL tot = fact[n];
	for (int i = 1; i < N; i++)
		tot = tot * rfact[cnt[i]] % mod;
	for (int i = 1; i < N; i++)
		b.add(i, cnt[i]);
	for (int i = 1; i <= m && i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		ans += b.sum(x - 1) * tot % mod * inv[n - i + 1] % mod;
		if (cnt[x] == 0) break;
		tot = tot * inv[n - i + 1] % mod * cnt[x] % mod;
		b.add(x, -cnt[x]);
		cnt[x]--;
		b.add(x, cnt[x]);
		if (i == n && i < m)
		{
			ans++;
		}
	}
	printf("%lld\n", ans % mod);
	return 0;
}