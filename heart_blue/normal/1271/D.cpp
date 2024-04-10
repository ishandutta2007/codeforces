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
const int N = 5e3 + 10;
int dp[N][N];
vector<int> key[N];
int last[N];
int a[N];
int b[N];
int c[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		last[i] = i;
	}
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		last[v] = max(last[v], u);
	}
	for (int i = 1; i <= n; i++)
	{
		key[last[i]].push_back(c[i]);
		sort(key[i].rbegin(), key[i].rend());
		for (int j = 1; j < key[i].size(); j++)
		{
			key[i][j] += key[i][j - 1];
		}
	}
	MEM(dp, 0xcf);
	dp[1][k] = 0;
	int sum = k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i]; j <= sum; j++)
		{
			if (dp[i][j] < 0) continue;
			dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j]);
			for (int t = 1; t <= key[i].size(); t++)
			{
				if (j + b[i] < t) break;
				int& tmp = dp[i + 1][j + b[i] - t];
				tmp = max(tmp, dp[i][j] + key[i][t - 1]);
			}
		}
		sum += b[i];
	}
	int ans = -1;
	for (int i = 0; i <= sum; i++)
		ans = max(ans, dp[n + 1][i]);
	printf("%d\n", ans);
	return 0;
}