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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL dp[2][10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	MEM(dp, 0xdf);
	int o = 0;
	dp[0][0] = 0;
	while (n--)
	{
		o ^= 1;
		memcpy(dp[o], dp[o ^ 1], sizeof(dp[o]));
		int sz;
		scanf("%d", &sz);
		vector<pair<int, int>> vp;
		int maxv2 = 0, maxv3 = 0;
		while (sz--)
		{
			int cost, val;
			scanf("%d%d", &cost, &val);
			if (cost == 1) vp.emplace_back(1, val);
			else if (cost == 2) maxv2 = max(maxv2, val);
			else maxv3 = max(maxv3, val);
		}
		sort(vp.rbegin(), vp.rend());
		while (vp.size() > 3) vp.pop_back();
		if (maxv2 > 0) vp.emplace_back(2, maxv2);
		if (maxv3 > 0) vp.emplace_back(3, maxv3);
		sort(vp.begin(), vp.end());
		do
		{
			for (int i = 0; i < 10; i++)
			{
				int cur = i;
				int rest = 3;
				LL sum = 0;
				for (auto [cost, val] : vp)
				{
					if (rest < cost) break;
					rest -= cost;
					sum += val;
					cur++;
					if (cur == 10) cur = 0, sum += val;
					dp[o][cur] = max(dp[o][cur], dp[o ^ 1][i] + sum);
				}
			}
		} while (next_permutation(vp.begin(), vp.end()));
	}
	LL ans = 0;
	for (int i = 0; i < 10; i++)
		ans = max(ans, dp[o][i]);
	printf("%lld\n", ans);
	return 0;
}