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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int dp[N][6][2];
int vis[N][6][2];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k, z;
		scanf("%d%d%d", &n, &k, &z);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			MEM(dp[i], 0);
			MEM(vis[i], 0);
		}
		MEM(vis[0], 0);
		typedef tuple<int, int, int, int> Node;
		priority_queue<Node> pq;
		pq.emplace(0, a[1], 0, 0);
		dp[0][0][0] = a[1];
		int ans = 0;
		while (!pq.empty())
		{
			int step, len, o1, o2;
			tie(step, len, o1, o2) = pq.top();
			pq.pop();
			step = -step;
			if (vis[step][o1][o2]) continue;
			vis[step][o1][o2] = 1;
			int pos = 1 + step - 2 * o1;
			if (step == k)
			{
				ans = max(ans, len);
				continue;
			}
			for (int i = -1; i <= 1; i += 2)
			{
				if (pos + i < 1) continue;
				if (pos + i > n) continue;
				if (i == -1)
				{
					if (o1 == z) continue;
					if (o2 == 1) continue;
				}
				int np = pos + i;
				int& tmp = dp[step + 1][o1 + (i == -1)][i == -1];
				if (tmp < dp[step][o1][o2] + a[np])
				{
					tmp = dp[step][o1][o2] + a[np];
					pq.emplace(-step - 1, tmp, o1 + (i == -1), i == -1 ? 1 : 0);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}