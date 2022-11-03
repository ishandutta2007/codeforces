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
const int N = 6e4 + 10;
int dp[110][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, r;
	scanf("%d%d", &n, &r);
	vector<pair<int, int>> vp1, vp2, vp0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (b >= 0) vp1.emplace_back(a, b);
		else vp2.emplace_back(max(a, -b), b);
	}
	sort(vp1.begin(), vp1.end());
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (auto& [a, b] : vp1)
		{
			if (b == -1) continue;
			if (r >= a)
			{
				r += b, cnt++;
				b = -1;
			}
		}
	}
	sort(vp2.begin(), vp2.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)->bool
		{
			return p1.first + p1.second > p2.first + p2.second;
		});
	dp[0][r] = cnt;
	for (int i = 0; i < vp2.size(); i++)
	{
		for (int j = 0; j <= r; j++)
		{
			dp[i + 1][j] = dp[i][j];
		}
		auto [a, b] = vp2[i];
		for (int j = max(a, -b); j <= r; j++)
		{
			dp[i + 1][j + b] = max(dp[i + 1][j + b], dp[i][j] + 1);
		}
	}
	int tot = 0;
	int sz = vp2.size();
	for (int i = 0; i <= r; i++)
		tot = max(tot, dp[sz][i]);
	printf("%d\n", tot);
	return 0;
}