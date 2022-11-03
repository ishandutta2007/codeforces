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
const int N = 5e1 + 10;
const int M = 5e3 + 200;
LL dp[M][N];
int pre[M][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<tuple<int, LL, int>> vp;
	for (int i = 1; i <= m; i++)
	{
		LL a, b;
		int c;
		scanf("%lld%lld%d", &a, &b, &c);
		for (LL x = a; x <= b; x++)
		{
			vp.emplace_back(c, x, i);
		}
	}
	sort(vp.begin(), vp.end());
	MEM(dp, -1);
	for (int i = 0; i < vp.size(); i++)
	{
		auto [c1, x1, id1] = vp[i];
		dp[i][1] = x1;
		for (int j = 0; j < i; j++)
		{
			auto [c2, x2, id2] = vp[j];
			if (c1 <= c2) break;
			if (x2 + k != x1 && x2 * k != x1) continue;
			for (int t = 2; t <= n; t++)
			{
				if (dp[j][t - 1] == -1) continue;
				if (dp[i][t] < dp[j][t - 1] + x1)
				{
					dp[i][t] = dp[j][t - 1] + x1;
					pre[i][t] = j;
				}
			}
		}
	}
	int o = 0;
	for (int i = 0; i < vp.size(); i++)
	{
		if (dp[i][n] > dp[o][n])
		{
			o = i;
		}
	}
	if (dp[o][n] < 0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	vector<pair<int, LL>> ans;
	for (int i = n; i >= 1; i--)
	{
		auto [c, x, id] = vp[o];
		ans.emplace_back(id, x);
		o = pre[o][i];
	}
	reverse(ans.begin(), ans.end());
	for (auto [id, x] : ans)
		printf("%d %lld\n", id, x);
	return 0;
}