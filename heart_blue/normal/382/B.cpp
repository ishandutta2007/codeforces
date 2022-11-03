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
const int N = 2e3 + 10;
pair<int, LL> dp[N][60];
pair<int, LL> add(pair<int, LL> p1, pair<int, LL> p2)
{
	return { p1.first + p2.first,p1.second + p2.second };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, w, x, c;
	scanf("%d%d%d%d%d", &a, &b, &w, &x, &c);
	for (int i = 0; i < N; i++)
	{
		int j = 0;
		int o = 0;
		if (i >= x) j = i - x;
		else j = i + (w - x), o = 1;
		dp[i][0] = make_pair(j, o * 1LL);
	}
	for (int o = 0; o + 1 < 60; o++)
	{
		for (int i = 0; i < N; i++)
		{
			int j = dp[i][o].first;
			dp[i][o + 1].first = dp[j][o].first;
			dp[i][o + 1].second = dp[i][o].second + dp[j][o].second;
		}
	}
	if (c <= a)
	{
		puts("0");
		return 0;
	}
	LL l = 1, r = 100000 * INF;
	LL ans = 0;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL delta = 0;
		int cur = b;
		for (int o = 0; mid >> o; o++)
		{
			if (mid >> o & 1)
			{
				delta += dp[cur][o].second;
				cur = dp[cur][o].first;
			}
		}
		if (c - mid <= a - delta) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}