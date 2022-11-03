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
const int N = 2e5 + 10;
int a[N];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<pair<int, int>> vp(n);
		for (auto& [x, y] : vp) scanf("%d", &x), x *= 2;
		int l = 0;
		int r = 1e9;
		for (auto& [x, y] : vp)
		{
			scanf("%d", &y), y *= 2;
			l = max(l, y);
		}
		int ans = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int lo = -2 * INF, up = 2 * INF;
			for (auto& [x, y] : vp)
			{
				int o = mid - y;
				lo = max(lo, x - o);
				up = min(up, x + o);
			}
			if (lo <= up) ans = lo, r = mid - 1;
			else l = mid + 1;
		}
		printf("%.1f\n", ans / 2.0);
	}
	return 0;
}