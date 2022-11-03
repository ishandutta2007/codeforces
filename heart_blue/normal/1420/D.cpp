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
const LL MOD = 998244353;
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
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
	int n, k;
	init();
	scanf("%d%d", &n, &k);
	LL ans = 0;
	int sum = 0;
	map<int, int> mc;
	map<int, int> key;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		mc[l]++;
		key[l]++;
		mc[r + 1]--;
	}
	for (auto& p : mc)
	{
		sum += p.second;
		if (key.count(p.first))
		{
			int a = key[p.first];
			for (int i = 1; i <= a && i <= k; i++)
			{
				ans += C(a, i) * C(sum - a, k - i) % MOD;
			}
		}
	}
	printf("%lld\n", ans % MOD);
	return 0;
}