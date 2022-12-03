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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int dp[N][2];
int in[N];
int out[N];
vector<int> v[N];
int dfs(int x, int o)
{
	if (dp[x][o] != -1) return dp[x][o];
	if (in[x] < 2 * o) return 0;
	if (out[x] == 1) return 1;
	int maxv = 0;
	for (auto& y : v[x])
	{
		maxv = max(maxv, dfs(y, 1));
	}
	return dp[x][o] = maxv + 1;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		out[x]++;
		in[y]++;
	}
	int ans = 0;
	MEM(dp, -1);
	for (int i = 1; i <= n; i++)
		ans = max(ans, dfs(i, 0));
	printf("%d\n", ans);
	return 0;
}