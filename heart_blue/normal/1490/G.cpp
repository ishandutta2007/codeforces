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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL ans[N];
LL sum[N];
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
		LL maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &sum[i]);
			sum[i] += sum[i - 1];
			maxv = max(maxv, sum[i]);
		}
		memset(ans, -1, sizeof(LL) * (m + 1));
		vector<pair<int, int>> vp;
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(x, i);
		}
		if (sum[n] > 0)
		{
			LL tot = sum[n];
			for (auto& [x, pos] : vp)
			{
				ans[pos] = max(0LL, (x - (maxv - tot) - 1) / tot) * n;
				x -= max(0LL, (x - (maxv - tot) - 1) / tot) * tot;
			}
		}
		sort(vp.begin(), vp.end());
		int ptr = 0;
		LL cur = -1;
		for (int i = 1; i <= n; i++)
		{
			cur = max(cur, sum[i]);
			while (ptr < vp.size())
			{
				int x, pos;
				tie(x, pos) = vp[ptr];
				if (cur < x) break;
				if (ans[pos] == -1) ans[pos] = 0;
				ans[pos] += i;
				ptr++;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (ans[i] != -1) ans[i]--;
			printf("%lld%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}