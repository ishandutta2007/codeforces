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
const int N = 3e5 + 10;
vector<int> v[N];
int clr[N];
int cnt[2];
void dfs(int x, int o = 0)
{
	if (clr[x] != -1)
	{
		if (clr[x] != o)
		{
			cnt[0] = cnt[1] = -INF;
		}
		return;
	}
	clr[x] = o;
	cnt[o]++;
	for (auto& y : v[x])
	{
		dfs(y, o ^ 1);
	}
}
LL powmod(LL a, LL b, LL mod = 998244353)
{
	if (b < 0) return 0;
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++) clr[i] = -1;
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].emplace_back(y);
			v[y].emplace_back(x);
		}
		LL ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (clr[i] != -1) continue;
			cnt[0] = cnt[1] = 0;
			dfs(i);
			ans = ans * ((powmod(2, cnt[0]) + powmod(2, cnt[1]))) % 998244353;
		}
		printf("%lld\n", ans);
	}
	return 0;
}