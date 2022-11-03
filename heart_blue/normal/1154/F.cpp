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
const int N = 2e5 + 10;
LL sum[N];
LL dp[N];
int cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> sum[i];
	sort(sum + 1, sum + n + 1);
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= k; i++) dp[i] = sum[i];
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		cost[x] = max(cost[x], y);
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + sum[i] - sum[i - (j - cost[j])]);
		}
	}
	cout << dp[k];
	return 0;
}