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
int a[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int k, n;
		scanf("%d%d", &k, &n);
		vector<pair<int, int>> vp;
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vp.emplace_back(x, y);
			a[i] = x;
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + a[i];
		}
		LL ans = 0;
		for (auto [x, y] : vp)
		{
			int pos = lower_bound(a + 1, a + n + 1, y) - a;
			pos = max(pos, n - k + 1);
			int rest = k - (n - pos + 1);
			LL res = sum[n] - sum[pos - 1];
			if (x > y)
				res -= x, rest++;
			if (rest >= 1)
				res += x + (rest - 1LL) * y;
			ans = max(ans, res);
		}
		printf("%lld\n", ans);
	}
	return 0;
}