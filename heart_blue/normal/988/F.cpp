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
const int N = 2e3 + 10;
LL dp[N][N];
int flag[N];
vector<pair<int, int>> key[N];
int weight[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	int a, n, m;
	scanf("%d%d%d", &a, &n, &m);
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		for (int i = l + 1; i <= r; i++)
			flag[i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, p;
		scanf("%d%d", &x, &p);
		key[x].emplace_back(p, i);
		weight[i] = p;
	}
	dp[0][0] = 0;
	for (int i = 0; i < a; i++)
	{
		for (auto& [w, pos] : key[i])
		{
			dp[i][pos] = min(dp[i][pos], dp[i][0]);
		}
		if (flag[i + 1] == 0)
			dp[i + 1][0] = dp[i][0];
		for (int j = 1; j <= m; j++)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + weight[j]);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + weight[j]);
		}
	}
	LL ans = dp[a][0];
	if (ans > 1e15)
	{
		puts("-1");
	}
	else printf("%lld\n", ans);
	return 0;
}