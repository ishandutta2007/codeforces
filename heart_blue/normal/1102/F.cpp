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
int a[16][N];
int last[16][16];
int b[16][16];
int dp[1 << 16][16];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	if (n == 1)
	{
		int minv = INF;
		for (int i = 1; i < m; i++)
			minv = min(minv, abs(a[0][i] - a[0][i - 1]));
		printf("%d\n", minv);
		return 0;
	}
	int l = 0, r = INF;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			int minv = INF;
			for (int k = 0; k < m; k++)
			{
				minv = min(minv, abs(a[i][k] - a[j][k]));
			}
			b[i][j] = minv;
			minv = INF;
			for (int k = 0; k + 1 < m; k++)
			{
				minv = min(minv, abs(a[i][k] - a[j][k + 1]));
			}
			last[i][j] = minv;
		}
	}
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int ok = 0;
		MEM(dp, -1);
		for (int key = 0; key < n; key++)
		{
			dp[1 << key][key] = 1;
			queue<pair<int, int>> q;
			q.emplace(1 << key, key);
			while (!q.empty())
			{
				auto [o, x] = q.front();
				q.pop();
				for (int i = 0; i < n; i++)
				{
					if (o >> i & 1) continue;
					if (b[x][i] >= mid)
					{
						if (dp[1 << i | o][i] == key) continue;
						dp[1 << i | o][i] = key;
						q.emplace(1 << i | o, i);
					}
				}
			}
			int mask = 1 << n;
			mask--;
			for (int i = 0; i < n; i++)
			{
				if (dp[mask][i] == key && last[i][key] >= mid)
				{
					ok = 1;
					break;
				}
			}
			if (ok)
				break;
		}
		if (ok) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}