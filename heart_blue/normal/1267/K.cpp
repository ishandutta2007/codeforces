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
const int N = 1e2 + 10;
LL dp[N][N];
void init()
{
	for (int i = 0; i < N; i++) dp[i][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}
LL solve(int n, map<int, int>& mc, int flag)
{
	if (flag)
	{
		if (!mc.count(0)) return 0;
		if (mc[0]-- == 1)
			mc.erase(0);
	}
	LL ret = 0;
	vector<pair<int, int>> vp;
	for (auto p : mc)
		vp.push_back(p);
	int used = 0;
	int tot = 0;
	LL ans = 1;
	for (int i = vp.size() - 1; i >= 0; i--)
	{
		tot = n - vp[i].first;
		if (vp[i].first == 0)
			tot--;
		if (tot - used - flag < 0 || tot - used - flag < vp[i].second)
			return 0;
		ans *= dp[tot - used - flag][vp[i].second];
		used += vp[i].second;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<int, int> mc;
		LL n;
		cin >> n;
		int len = 1;
		for (int i = 2; n; i++)
		{
			len++;
			mc[n % i]++;
			n /= i;
		}
		LL ans = solve(len, mc, 0);
		ans -= solve(len, mc, 1);

		printf("%lld\n", ans - 1);
	}
	return 0;
}