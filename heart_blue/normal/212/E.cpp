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
const int N = 5e3 + 10;
int sz[N];
vector<int> v[N];
int flag[N];
int dp[N];
int n;
void dfs(int x, int fa = 0)
{
	sz[x] = 0;
	int sx = 0;
	dp[0] = 1;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
	for(auto &y : v[x])
	{
		if (y == fa) continue;
		int sy = sz[y];
		for (int i = 1; i <= sy; i++) dp[sx + i] = 0;
		sx += sy;
		for (int i = sx; i >= sy; i--)
		{
			dp[i] |= dp[i - sz[y]];
		}
	}
	sz[x] = sx + 1;
	for (int i = 0; i <= sx; i++)
	{
		if (dp[i])
			flag[i] = flag[i + (n - sz[x])] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs(1);
	vector<int> ans;
	for (int i = 1; i < n - 1; i++)
	{
		if (flag[i])
			ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d %d\n", x, n - x - 1);
	return 0;
}