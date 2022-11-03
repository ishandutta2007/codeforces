#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e6 + 10;
const int MOD = 998244353;
vector<int> v1[N], v2[N];
LL rp[N];
LL key[N];
void init(int n)
{
	rp[1] = 1;
	for (int i = 2; i < N; i++)
	{
		rp[i] = (MOD - MOD / i) * 1LL * rp[MOD % i] % MOD;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++)
	{
		int sz;
		scanf("%d", &sz);
		while (sz--)
		{
			int x;
			scanf("%d", &x);
			v1[i].push_back(x);
			v2[x].push_back(i);
		}
	}
	LL ans = 0;
	LL tot = rp[n] * rp[n] % MOD;
	for (int i = 1; i <= n; i++)
	{
		for (auto& x : v1[i])
		{
			ans += tot * rp[v1[i].size()] % MOD * v2[x].size() % MOD;
			if (ans >= MOD)
				ans -= MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}