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
const int N = 2e5 + 10;
const int MOD = 998244353;
vector<int> v[N];
LL fact[N];
LL rfact[N];
LL ans[N];
int son[N];
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
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}
void dfs(int x, int fa = 0)
{
	ans[x] = 1;
	son[x] = 1;
	int cnt = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		cnt++;
		dfs(y, x);
		son[x] += son[y];
		ans[x] = ans[x] * ans[y] % MOD;
	}
	if (x != 1)
		ans[x] = ans[x] * (cnt + 1) % MOD;
	ans[x] = ans[x] * fact[cnt] % MOD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	printf("%lld\n", ans[1] * n % MOD);
	return 0;
}