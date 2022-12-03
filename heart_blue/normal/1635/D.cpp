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
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[1] = 1;
	for (int i = 1; i < N - 3; i++)
	{
		dp[i] %= INF;
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
	}
	for (int i = 1; i < N; i++)
		dp[i] = (dp[i] + dp[i - 1]) % INF;
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> v(n);
	map<int, int> mc;
	for (auto& x : v)
		scanf("%d", &x), mc[x] = 1;
	LL ans = 0;
	for (auto& p : mc)
	{
		int x = p.first;
		auto check = [&](int x) ->bool
		{
			while (x)
			{
				if (x & 1) x /= 2;
				else if (x % 4 == 0) x /= 4;
				else break;
				if (mc.count(x))
					return true;
			}
			return false;
		};
		if (check(x))
			p.second = 0;
		if (p.second == 0) continue;
		auto getlen = [](int x) ->int
		{
			int ret = 0;
			while (x)
				ret++, x /= 2;
			return ret;
		};
		int len = getlen(x);
		if (len > k) continue;
		ans += dp[k - len + 1];
	}
	printf("%lld\n", ans % INF);
	return 0;
}