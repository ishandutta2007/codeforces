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
const LL MOD = 998244353;
const int N = 2e5 + 10;
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++)
		rfact[i] = (MOD - MOD / i) * rfact[MOD % i] % MOD;
	for (int i = 2; i < N; i++)
		rfact[i] = rfact[i - 1] * rfact[i] % MOD;
}
LL C(int n, int m)
{
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	init();
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.rbegin(), v.rend());
		if (v[0] == v[1])
		{
			printf("%lld\n", fact[n]);
			continue;
		}
		if (v[0] > v[1] + 1)
		{
			puts("0");
			continue;
		}
		int cnt = count(v.begin(), v.end(), v[1]);
		LL ans = cnt * fact[cnt] % MOD * C(n, cnt + 1) % MOD * fact[n - cnt - 1] % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}