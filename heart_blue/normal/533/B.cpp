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
vector<int> v[N];
LL w[N];
LL dp[N][2];
void dfs(int x)
{
	dp[x][0] = 0;
	dp[x][1] = -INF * INF;
	for (auto &y : v[x])
	{
		dfs(y);
		tie(dp[x][0], dp[x][1]) = make_pair(max(dp[x][0] + dp[y][0], dp[x][1] + dp[y][1]),
			max(dp[x][0] + dp[y][1], dp[x][1] + dp[y][0]));
	}
	dp[x][1] = max(dp[x][1], dp[x][0] + w[x]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int fa;
		cin >> fa >> w[i];
		if (fa != -1) v[fa].push_back(i);
	}
	dfs(1);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
	return 0;
}