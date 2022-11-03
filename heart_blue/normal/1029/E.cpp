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
#define MEM(a,b) memset((a),(vp),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<int> v[N];
int dp[N][3];
vector<int> vp;
int n;
void dfs(int u, int p = 0, int d = 0) {// p  u 
	dp[u][2] = 0;
	dp[u][0] = 1;
	bool s = false;
	int sum = 0, inc = INF;
	if (d == 2)
	{
		vp.push_back(u);
	}
	for (auto &to : v[u])
	{
		if (to == p) continue;
		dfs(to, u, d + 1);
		dp[u][0] += min(dp[to][0], min(dp[to][1], dp[to][2]));
		if (dp[to][0] <= dp[to][1]) {
			sum += dp[to][0];
			s = true;
		}
		else {
			sum += dp[to][1];
			inc = min(inc, dp[to][0] - dp[to][1]);
		}
		if (dp[to][1] != INF && dp[u][2] != INF) dp[u][2] += dp[to][1];
		else dp[u][2] = INF;
	}
	if (inc == INF && !s) dp[u][1] = INF;
	else {
		dp[u][1] = sum;
		if (!s) dp[u][1] += inc;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int ans = 0;
	for (auto &x : vp)
	{
		ans += min({ dp[x][0] - (v[x].size() == 1), dp[x][1], dp[x][2] });
	}
	printf("%d\n", ans);
	return 0;
}