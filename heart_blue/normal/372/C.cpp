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
const int N = 1.5e5 + 10;
int n;
LL dp[N];
LL dp2[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, dd;
	scanf("%d%d%d", &n, &m, &dd);
	MEM(dp, 0);
	LL ans = 0;
	LL a, b, t;
	LL pre = 1;

	while (m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a = x;
		b = y;
		t = z;
		if ((t - pre) * dd >= n - 1)
		{
			pre = t;
			LL maxv = dp[1];
			for (int i = 1; i <= n; i++)
				maxv = max(maxv, dp[i]);
			maxv += b;
			for (int i = 1; i <= n; i++)
			{
				dp[i] = maxv - abs(i - a);
			}

			continue;
		}
		memcpy(dp2, dp, sizeof(dp));
		int cur = 1;
		deque<int> q;
		for (int i = 1; i <= n; i++)
		{
			LL l = i - (t - pre) * dd;
			LL r = i + (t - pre) * dd;
			if (l < 1) l = 1;
			if (r > n) r = n;
			while (cur <= r)
			{
				while (!q.empty() && dp2[q.back()] <= dp2[cur]) q.pop_back();
				q.push_back(cur++);
			}
			while (!q.empty() && q.front() < l) q.pop_front();
			dp[i] = b - abs(a - i) + dp2[q.front()];
		}
		pre = t;

	}
	ans = dp[1];
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	printf("%lld\n", ans);
	return 0;
}