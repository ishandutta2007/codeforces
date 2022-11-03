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
const int N = 4e2 + 10;
vector<pair<int, int>> v[N];
vector<int> ans[N];
int a[N];
int dp[N][N];
int pre[N][N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, cost;
	scanf("%d%d", &n, &cost);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int l, r, f;
		scanf("%d%d%d", &l, &r, &f);
		for (int j = l; j <= r; j++)
		{
			v[j].emplace_back(f, i);
		}
	}
	MEM(dp, 0xcf);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i];
		v[i].emplace_back(0, 0);
		sort(v[i].begin(), v[i].end());
		for (int j = 1; j < v[i].size(); j++)
		{
			v[i][j].first += v[i][j - 1].first;
		}
		for (int j = 0; j < N; j++)
		{
			if (dp[i - 1][j] < 0) continue;
			for (int k = 0; k < v[i].size(); k++)
			{
				if (x + j < v[i][k].first + cost) break;
				int o = min(x, x + j - v[i][k].first - cost);
				if (dp[i][o] < dp[i - 1][j] + k)
				{
					dp[i][o] = dp[i - 1][j] + k;
					pre[i][o] = j;
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (dp[n][i] > dp[n][k])
			k = i;
	}
	printf("%d\n", dp[n][k]);
	for (int i = n; i >= 1; i--)
	{
		int kk = pre[i][k];
		int sz = dp[i][k] - dp[i - 1][kk];
		for (int j = 1; j <= sz; j++)
			ans[i].push_back(v[i][j].second);
		k = kk;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d", ans[i].size());
		for (auto& x : ans[i])
			printf(" %d", x);
		puts("");
	}
	return 0;
}