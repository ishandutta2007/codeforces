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
const int N = 1e5 + 10;
LL dp[N][202];
vector<tuple<int, int, int>> v[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	MEM(dp, 0x3f);
	MEM(dp[0], 0);
	using Node = tuple<int, int, int>;
	priority_queue<Node> pq;
	for (int i = 1; i <= k; i++)
	{
		int s, t, d, w;
		scanf("%d%d%d%d", &s, &t, &d, &w);
		v[s].emplace_back(w, d, i);
		v[t + 1].emplace_back(w, d, i);
	}
	for (int i = 0; i <= n; i++)
	{
		for (auto [w, d, id] : v[i])
		{
			flag[id] ^= 1;
			if (flag[id])
				pq.emplace(w, d, id);
		}
		while (!pq.empty())
		{
			auto [w, d, id] = pq.top();
			if (flag[id]) break;
			pq.pop();
		}
		for (int j = 0; j <= m; j++)
		{
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
		}
		if (!pq.empty())
		{
			auto [w, d, id] = pq.top();
			for (int j = 0; j <= m; j++)
				dp[d + 1][j] = min(dp[d + 1][j], dp[i][j] + w);
		}
		else
		{
			for (int j = 0; j <= m; j++)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		}
	}
	LL ans = 4 * INF * INF;
	for (int i = 0; i <= m; i++)
		ans = min(ans, dp[n + 1][i]);
	printf("%lld\n", ans);
	return 0;
}