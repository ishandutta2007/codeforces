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
const int N = 2e5 + 10;
int minv[N];
int maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	int limit = 0;
	MEM(minv, 0x3f);
	MEM(maxv, 0);
	while (k--)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		minv[r] = min(minv[r], c);
		maxv[r] = max(maxv[r], c);
		limit = max(limit, r);
	}
	vector<int> v(q);
	for (auto& x : v)
		scanf("%d", &x);
	sort(v.begin(), v.end());
	map<int, LL> mc1;
	mc1[1] = 0;
	for (int i = 1; i <= limit; i++)
	{
		map<int, LL> mc2;
		int a = minv[i];
		int b = maxv[i];
		if (b != 0)
		{
			mc2[a] = mc2[b] = INF * INF;
			for (auto [x, val] : mc1)
			{
				mc2[a] = min(mc2[a], 1LL * b - a + abs(b - x) + val);
				mc2[b] = min(mc2[b], 1LL * b - a + abs(a - x) + val);
			}
			mc1 = mc2;
			mc2.clear();
			if (i == limit) break;
		}
		for (auto [x, val] : mc1)
		{
			auto iter = lower_bound(v.begin(), v.end(), x);
			if (iter != v.end())
			{
				int y = *iter;
				int d = abs(y - x) + 1;
				if (mc2[y] == 0)
					mc2[y] = INF * INF;
				mc2[y] = min(mc2[y], val + d);
				if (d == 1) continue;
			}
			if (iter != v.begin())
			{
				iter--;
				int y = *iter;
				int d = abs(y - x) + 1;
				if (mc2[y] == 0)
					mc2[y] = INF * INF;
				mc2[y] = min(mc2[y], val + d);
			}
		}
		mc1 = mc2;
	}
	LL ans = INF * INF;
	for (auto [x, val] : mc1)
	{
		ans = min(ans, val);
	}
	printf("%lld\n", ans);
	return 0;
}